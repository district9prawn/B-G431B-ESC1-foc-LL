/*********************************************************************
* File    : datatypes.h
* Title   : Datatypes for the motor controller
**********************************************************************
*/

/* Prevent recursive definition */
#ifndef DATATYPES_H
#define DATATYPES_H

/* Includes */

typedef struct motor_vars_t
{
  /*  Status flags 
      Could be more memory efficient to use bitfields but meh */
  uint8_t flag_IsSensored; // 1 if encoder or hall sensor is being used. 
  
  uint8_t flag_EnableSpeedCtrl;
  uint8_t flag_IsFault;
  uint8_t flag_EnableFieldWeaken;
  uint8_t flag_EnableMTPA;
  uint8_t flag_IsHFI;

  /* Controller state machine flags */
  // TODO: This should be a typedef enum
  uint8_t flag_MCState; // 0=off, 1=drive - for now

  // TODO: Faults. Bitfields?
  uint8_t fault_OverCurrent;
  uint8_t fault_OverVoltage_phase;
  uint8_t fault_OverVoltage_bus;
  uint8_t fault_OverTemperature;
  uint8_t fault_Watchdog; // MCU system faults, not analog watchdog

  /* Debug */
  uint8_t debug_data_sel; // Pick what data to print
  uint32_t terminal_print_rate; // Process terminal commands every x iterations of slow loop

  /* Motor params */
  float lambda; // Don't actually need this in SMC?
  float Rs; // Ohm
  float Ls; // Henries
  float motor_J; // Rotor inertia
  float motor_B; // Rotor viscous drag coefficient

  /* State variables */
  float Vabc[3]; // Motor phase voltages in three-phase system
  float Vab[2]; // Motor phase voltages in alpha beta frame
  float Vdq[2]; // Motor phase voltages in d-q frame
  float Vabc_ref[3];
  float Vab_ref[2];
  float Vdq_ref[2];
  float Vs_mag; // Stator voltage magnitude
  float Vbus; // DC bus voltage
  float Iabc[3]; // Motor phase currents in three-phase system
  float Iab[2]; // Motor phase currents in alpha beta
  float Idq[2]; // Motor phase currents in d-q frame
  float Iabc_ref[3];
  float Iab_ref[2];
  float Idq_ref[2];
  float Is_mag; // Stator current magnitude
  float Iq_hfi; // Response current to injected voltage
  float Iq_prev; // Saved Iq from previous sample for hfi
  float phase;
  float Dabc[3]; // Duty cycle between 0 and 1 to be sent to PWM

  /* Limits */
  float Is_max; // Max stator current in amps
  float Vs_max_pu; // Max stator voltage in per unit. Max 0.66.

  /* Current PI */
  float current_kp;
  float current_ki;

  /* Speed PI */
  float speed_kp;
  float speed_ki;

  /* HFI */
  float hfi_Vs; // Injection voltage
  uint8_t hfi_state; // Variable that might be useful
  uint32_t hfi_cnt; // Number of times hfi has run in foc_isr
} motor_vars_t;



#endif // End of datatypes.h defines
