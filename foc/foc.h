/*********************************************************************
* File    : foc.h
* Title   : Field-oriented control library
**********************************************************************
*/

/* Prevent recursive definition */
#ifndef FOC_H
#define FOC_H


/* Includes */
// #include "math.h"
// #include "utils.h"
#include "main.h" // This becomes circular since main.h includes foc.h
                  // Manually include what is necessary
#include "clarke.h"
#include "park.h"
#include "svgen.h"

void foc_observer_isr(void);

void foc_speed_isr(void);

void write_PWM(TIM_TypeDef *TIMx, volatile float *Dabc);

void start_PMW(TIM_TypeDef *TIMx);

void stop_PMW(TIM_TypeDef *TIMx);

#endif


       

