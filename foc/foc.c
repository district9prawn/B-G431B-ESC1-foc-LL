/*
* Copyright 2021-2022 Gary Lai
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* 1. Redistributions of source code must retain the above copyright notice, this
*    list of conditions and the following disclaimer.
*
* 2. Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
*
* 3. Neither the name of the copyright holder nor the names of its contributors
*    may be used to endorse or promote products derived from this software
*    without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/*********************************************************************
* File    : foc.c
* Purpose : Field-oriented control functions
**********************************************************************
*/

#include "foc.h"
float phase_step = 0.2513f;
float hfi_phase_step = 0.2513f;
volatile float hfi_phase = 0.0;
const float phase_step_inc = 6.2832e-5f / 5.0f;
const float phase_step_max = 0.1257f; // 20Hz

/* Initialize motor parameter struct */
void motor_vars_init(motor_vars_t vars)
{

}

/*  Calculate currents, voltages and phase (sensored or sensorless)
    Calculate and apply new PWM
    Triggered by DMA transfer complete interrupt */
__attribute((section(".fast"))) // Run ISR from RAM
void foc_observer_isr(void)
{
  //TIM2->CNT = 0;
  uint16_t Vabc_tmp[3];
  uint16_t Iabc_tmp[3];
  uint16_t Vbus;
  float sin_phase;
  float cos_phase;
  float sin_hfi_phase;
  float cos_hfi_phase;

  /* Save phase currents from DMA buffers */
  Iabc_tmp[0] = ADC1_DMA_buf[3];
  Iabc_tmp[1] = ADC2_DMA_buf[0];
  Iabc_tmp[2] = ADC2_DMA_buf[1];

  /* Save voltages from DMA buffers */
  Vabc_tmp[0] = ADC2_DMA_buf[2];
  Vabc_tmp[1] = ADC2_DMA_buf[3];
  Vabc_tmp[2] = ADC1_DMA_buf[0];
  Vbus = ADC1_DMA_buf[1];

  /* Increment phase for high frequency openloop */
  //MotorVars.phase += phase_step;
  //norm_angle(&MotorVars.phase);

  /* Increment hfi sine wave phase */
  //hfi_phase += hfi_phase_step;
  //norm_angle(&hfi_phase);
  //cordic_sincos(hfi_phase, &sin_hfi_phase, &cos_hfi_phase);

  /* Get phase currents and convert to amps
      36.458333 term is from shunt voltage / 0.003
      Note negative sign */
  MotorVars.Iabc[0] = -Vdda * 36.45833333f * ((float)Iabc_tmp[0] - (float)USER_Ia_offset_ADC) / 4096.0f;
  MotorVars.Iabc[1] = -Vdda * 36.45833333f * ((float)Iabc_tmp[1] - (float)USER_Ib_offset_ADC) / 4096.0f;
  MotorVars.Iabc[2] = -Vdda * 36.45833333f * ((float)Iabc_tmp[2] - (float)USER_Ic_offset_ADC) / 4096.0f;

  /* Get phase voltages and convert to volts */
  MotorVars.Vabc[0] = Vdda * USER_Vphase_divider * (((float)Vabc_tmp[0]-(float)USER_Va_offset_ADC) / 4096.0f);
  MotorVars.Vabc[1] = Vdda * USER_Vphase_divider * (((float)Vabc_tmp[1]-(float)USER_Vb_offset_ADC) / 4096.0f);
  MotorVars.Vabc[2] = Vdda * USER_Vphase_divider * (((float)Vabc_tmp[2]-(float)USER_Vc_offset_ADC) / 4096.0f);

  /* Calculate Vbus */
  MotorVars.Vbus = Vdda * USER_Vbus_divider * ((float)Vbus / 4096.0f);

  /* Clarke transform */
  clarke_full_run(MotorVars.Vabc, MotorVars.Vab);
  clarke_full_run(MotorVars.Iabc, MotorVars.Iab);

  /* Calculate motor phase */
  // Openloop simulation performed in slow loop

  /* Park transform */
  cordic_sincos(MotorVars.phase, &sin_phase, &cos_phase);
  park_run(MotorVars.Vab, sin_phase, cos_phase, MotorVars.Vdq);
  park_run(MotorVars.Iab, sin_phase, cos_phase, MotorVars.Idq);

  /* Fault if overcurrent */
  MotorVars.Is_mag = sqrtf(MotorVars.Iab[0]*MotorVars.Iab[0] + MotorVars.Iab[1]*MotorVars.Iab[1]);
  if(MotorVars.Is_mag > MotorVars.Is_max)
  {
    /* Disable PWM and enter fault state */
    LL_TIM_DisableAllOutputs(TIM1);
    MotorVars.fault_OverCurrent = 1;
    SEGGER_RTT_printf(0, "Overcurrent fault\n");
  }

  /* HFI datalogging */
  if(fast_loop_cnt < 128) // If this isn't guarded will write over entire ram
  {
    hfi_debug_buf[fast_loop_cnt] = MotorVars.Idq[1];
    hfi_vdq_buf[fast_loop_cnt] = MotorVars.Vdq_ref[0]; // Save previous Vd_ref
  }

  if(MotorVars.flag_MCState == 1)
  {
  /* Run current PI controller */
  PI_run(&Id_PI, MotorVars.Idq[0], MotorVars.Idq_ref[0], &MotorVars.Vdq_ref[0]);
  PI_run(&Iq_PI, MotorVars.Idq[1], MotorVars.Idq_ref[1], &MotorVars.Vdq_ref[1]);

  /* Overwrite with manual Vdq */
  MotorVars.Vdq_ref[0] = 0.0f;
  MotorVars.Vdq_ref[1] = 0.0f;

  }

  /* HFI */
  if(MotorVars.hfi_state == 1)
  {
    float sign_hfi;

    /* Alternating pulses */
    if(MotorVars.hfi_cnt < 2) 
    {
      sign_hfi = 1.0f; //  Inject with opposite polarity
    }
    else 
    {
      sign_hfi = -1.0f;
    }
    MotorVars.Vdq_ref[0] += sign_hfi * MotorVars.hfi_Vs; // Inject in d-axis
    MotorVars.Iq_hfi = MotorVars.Idq[1] - MotorVars.Iq_prev; // Difference between current and previous sample
                                                             // This won't work as also need to take alternate samples
    MotorVars.Iq_prev = MotorVars.Idq[1]; // Save Iq
    fast_loop_cnt++;
    MotorVars.hfi_cnt++;
    if(MotorVars.hfi_cnt > 3)
    {
      MotorVars.hfi_cnt = 0;
    }
  }

  /* Inverse Park transform */
  cordic_sincos(MotorVars.phase, &sin_phase, &cos_phase);
  ipark_run(MotorVars.Vdq_ref, sin_phase, cos_phase, MotorVars.Vab_ref);

  /* Inverse Clarke transform */
  iclarke_run(MotorVars.Vab_ref, MotorVars.Vabc_ref);

  /* Space Vector Modulation */
  svgen_run(MotorVars.Vabc_ref, MotorVars.Dabc, MotorVars.Vbus);

  /* Write PWM */
  uint16_t period = TIM1->ARR;
  TIM1->CCR1 = (uint16_t)(MotorVars.Dabc[0] * (float)period);
  TIM1->CCR2 = (uint16_t)(MotorVars.Dabc[1] * (float)period);
  TIM1->CCR3 = (uint16_t)(MotorVars.Dabc[2] * (float)period);
  
  /* Update debug buffer or RTT stuff */
  //isr_cycles = TIM2->CNT;

  /* HFI debug buffer */



}

/*  Slow loop triggered by slow TIM7 basic timer 
    Run speed PI controller
    Calculate temperature and throttle */
// __attribute((section(".fast"))) // This can probably run off flash
void foc_speed_isr(void)
{
  TIM2->CNT = 0; // For benchmarking

  /* Open loop rotating vector slowly accelerating to 50 Hz */
  //phase_step += phase_step_inc;
  //if(phase_step > phase_step_max) {
  //  phase_step = phase_step_max;
  //}
  //MotorVars.phase += phase_step;
  //norm_angle(&MotorVars.phase);

  MotorVars.phase = 0.0f; // Lock rotor to 0 degree

  /* Calculate temperature */
  
  uint16_t temperature_adc; // Raw adc reading
  float R_ntc; // Thermistor resistance
  float Vadc;
  temperature_adc = ADC1_DMA_buf[2];
  Vadc = Vdda * ((float)temperature_adc / 4096.0f);
  R_ntc = (4700.0f * Vdda / Vadc) - 1;
  temperature = (1.0f / (Inv_beta * logf(R_ntc / 10000.0f) + invT0)) - 273.15 ;

    /* Check if newline character encountered in RTT buffer */
    
    char char_tmp =0;
    SEGGER_RTT_Read(0, &char_tmp, 1);
    if(char_tmp == 0xa) {
      _SEGGER_RTT.aDown[0].RdOff = 0; // Read from start of buffer
      SEGGER_RTT_Read(0, cmd_tmp, 8);
      _SEGGER_RTT.aDown[0].WrOff = 0; // Command has been transferred, reset write pointer to start of buffer

      /* Process command */
      switch(cmd_tmp[0]) {
        case '1':
          MotorVars.Idq_ref[0] = 0.0f;
          MotorVars.Idq_ref[1] = 0.0f;
          MotorVars.flag_MCState = 1;
          MotorVars.hfi_state = 1;
          LL_TIM_EnableAllOutputs(TIM1);
          break;
        case '0':
          MotorVars.Idq_ref[0] = 0.0f;
          MotorVars.Idq_ref[1] = 0.0f;
          MotorVars.flag_MCState = 0;
          LL_TIM_DisableAllOutputs(TIM1);
          break;
        case 'i':
          // Show currents
          MotorVars.debug_data_sel = 1;
          break;
        case 'v':
          // Show voltages
          MotorVars.debug_data_sel = 2;
          break;
        case 'd':
          // Show duty
          MotorVars.debug_data_sel = 3;
          break;
        case 'q':
          // No output over terminal or in J-scope buffer
          MotorVars.debug_data_sel = 0;
          break;
        case 'h':
          // Show HFI debug info
          MotorVars.debug_data_sel = 4;
          fast_loop_cnt = 0; // Reset debug counter
          MotorVars.hfi_cnt = 0; // Reset counter so hfi debug values are saved
          break;
        case 'o':
          // Show sliding mode observer debug info
          break;
        case 's':
          // Show encoder/hall sensor debug info
          break;
        default:
          SEGGER_RTT_printf(0, "Invalid input\n");
          // break;
      }
    }

  /* RTT debug output */
  if(MotorVars.debug_data_sel != 0)
  {
    char str_tmp[32];
    switch(MotorVars.debug_data_sel) {
      case 1:
        /* Print currents */
        sprintf(str_tmp, 
                  "Ia=%.4f, Ib=%.4f, Ic=%.4f\n",
                  MotorVars.Iabc[0], MotorVars.Iabc[1], MotorVars.Iabc[2]);
        SEGGER_RTT_printf(0, str_tmp);
        SEGGER_RTT_Write(1, &MotorVars.Iabc[0], 4);
        SEGGER_RTT_Write(1, &MotorVars.Iabc[1], 4);
        SEGGER_RTT_Write(1, &MotorVars.Iabc[2], 4);
        break;
      case 2:
        /* Print voltages */
        sprintf(str_tmp, 
                  "Va=%.4f, Vb=%.4f, Vc=%.4f\n",
                  MotorVars.Vdq_ref[0], MotorVars.Vdq_ref[1], MotorVars.Vabc[2]);
        SEGGER_RTT_printf(0, str_tmp);
        SEGGER_RTT_Write(1, &MotorVars.Vabc[0], 4);
        SEGGER_RTT_Write(1, &MotorVars.Vabc[1], 4);
        SEGGER_RTT_Write(1, &MotorVars.Vabc[2], 4);
        break;
      case 3:
        /* Print duty */
          sprintf(str_tmp,
                  "Da=%.4f, Db=%.4f, Dc=%.4f\n",
                  MotorVars.Dabc[0], MotorVars.Dabc[1], MotorVars.Dabc[2]);
          SEGGER_RTT_printf(0, str_tmp);
          SEGGER_RTT_Write(1, &MotorVars.Dabc[0], 4);
          SEGGER_RTT_Write(1, &MotorVars.Dabc[1], 4);
          SEGGER_RTT_Write(1, &MotorVars.Dabc[2], 4);
        break;
      case 4:
        // Print hfi debug data
        sprintf(str_tmp, 
                "Vdq_ref=%.4f, Id=%.4f, I_q=%.4f\n",
                MotorVars.Vdq_ref[0], MotorVars.Idq[0], MotorVars.Idq[1]);
        SEGGER_RTT_printf(0, str_tmp);
        SEGGER_RTT_Write(1, &MotorVars.Idq[0], 4);
        SEGGER_RTT_Write(1, &MotorVars.Idq[1], 4);
        SEGGER_RTT_Write(1, &MotorVars.Iq_hfi, 4);
      default:
        break;
    }
  }

  /*  Write debug data to RTT up buffer for J-Scope */
  //SEGGER_RTT_Write(1, &MotorVars.Vab_ref[0], 4);
  //SEGGER_RTT_Write(1, &MotorVars.Vab_ref[1], 4);
  //SEGGER_RTT_Write(1, &MotorVars.Dabc[2], 4);

  SEGGER_RTT_Write(1, &MotorVars.Idq[0], 4);
  SEGGER_RTT_Write(1, &MotorVars.Idq[0], 4);

  isr_cycles = TIM2->CNT;
}

/*  Write duty cycles to the PWM timer
    Input TIMx: Base address of the advanced timer used for PWM
    Input Dabc: Pointer to array of three duty values with range between 0 and 1 */
void write_PWM(TIM_TypeDef *TIMx, volatile float *Dabc)
{

}

/*  Start the timer PWM output
    Do same same safety checks as startup before driving the gates */
void start_PMW(TIM_TypeDef *TIMx)
{

}

/* Force stop the timer PWM output */
void stop_PMW(TIM_TypeDef *TIMx)
{
  // MOE bit
}
