/*********************************************************************
* File    : hw_conf.h
* Title   : Configuration file for motor and controller parameters
**********************************************************************
*/

#ifndef HW_CONF_H
#define HW_CONF_H

/* Voltage measurement configuration */
#define USER_Vbus_divider          187.0f / 18.0f
#define USER_Vphase_divider        12.2f / 2.2f
#define USER_Vref                  3.3f // Set this to the value returned by measure_Vdda(). Otherwise 3.3f close enough to regulator output.
#define USER_Va_offset_ADC         (uint16_t)170 // Vphase measurement offset due to Vf drop of clamp diode       
#define USER_Vb_offset_ADC         (uint16_t)201
#define USER_Vc_offset_ADC         (uint16_t)149
// extern float Vref;

/* Current measurement configuration */
#define USER_current_gain          64.0f / 7.0f // Gain from divider network with PGA gain of 16x
#define USER_Ia_offset_ADC         (uint16_t)0x9f8 // Current measurement offset in ADC counts. In theory offset voltage should be 48/77 * 3.3V
#define USER_Ib_offset_ADC         (uint16_t)0x9ed // TODO: Read these off and set these
#define USER_Ic_offset_ADC         (uint16_t)0x9f8

/*  Encoder configuration 
    Only ABI type encoder supported */
#define encoder_ppr           (uint32_t)4096 // Encoder pulses per revolution

/* Controller configuration */
// TODO: Enter in the correct full scale ADC values
#define USER_Vbus_max              15.0f // DC bus voltage which triggers the ADC watchdog
#define USER_Vbus_full_scale       40.0f // DC voltage which saturates the Vbus ADC 
#define USER_Vphase_max            15.0f // Vphase which triggers the ADC watchdog
#define USER_Vphase_full_scale     30.0f // Voltage which saturates the Vphase ADC
#define USER_Iphase_max            15.0f // Voltage which triggers the ADC watchdog
#define USER_Iphase_full_scale     25.0f // Low side shunt current which saturates the ADC
#define USER_Id_max                5.0f // Maximum negative field weakening current
#define USER_Vs_max                0.57f // 1/sqrt(3) to provider maximum pure sinusoid line voltage output with SVM. 

/* Motor */
#define USER_motor_R               25e-3f // Phase to neutral resistance
#define USER_motor_L               50e-6f // Phase to neutral inductance
#define USER_motor_J               1e-3f // Rotor inertia
#define USER_motor_B               1e-4f // Viscous drag constant
#define USER_motor_lambda          5e-3f // Flux linkage in weber or V*s/rad

/* Current PI controller */
#define USER_current_kp           1.0f // Series
#define USER_current_ki           1.0e3f
#define USER_current_PI_bw_rad    3e3 // Typically 20x less than current loop rate 

/* Speed PI controller */
#define USER_speed_kp             20.0f
#define USER_speed_ki             200.0f

/* HFI */
#define USER_Vs_hfi               2.0f

/* Advanced features */
#define USER_EnableFW             (uint8_t)0
#define USER_EnableMTPA           (uint8_t)0




/*  Temperature sensor configuration
    10k NTC only */
#define NTC_beta                  3455.0f // Copied from g431-esc-github
#define Inv_beta                  (float)(1.0f/3455.0f)

#endif // end of HW_CONF_H defines
       

