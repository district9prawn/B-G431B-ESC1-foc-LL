/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "SEGGER_RTT.h"
#include <stdio.h>
#include "stm32g4xx.h"
#include "stm32g4xx_ll_rcc.h"
#include "stm32g4xx_ll_bus.h"
#include "stm32g4xx_ll_crs.h"
#include "stm32g4xx_ll_system.h"
#include "stm32g4xx_ll_exti.h"
#include "stm32g4xx_ll_cortex.h"
#include "stm32g4xx_ll_utils.h"
#include "stm32g4xx_ll_pwr.h"
#include "stm32g4xx_ll_adc.h"
#include "stm32g4xx_ll_opamp.h"
#include "stm32g4xx_ll_dma.h"
#include "stm32g4xx_ll_gpio.h"
#include "stm32g4xx_ll_tim.h"
#include "stm32g4xx_ll_cordic.h"
#include "datatypes.h"
#include "hw_conf.h"
#include "pi.h"
#include "utils.h"

#if defined(USE_FULL_ASSERT) // This is necessary when the LL drivers are used standalone without HAL (see HAL/LL driver manual)
#include "stm32_assert.h"
#endif /* USE_FULL_ASSERT */

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
extern volatile uint32_t isr_cnt;
extern volatile uint32_t slow_loop_cnt;
extern volatile uint32_t isr_cycles;
extern PI_obj PI_test;
extern PI_obj Id_PI;
extern PI_obj Iq_PI;
extern float sin_res;
extern float cos_res;
extern float angle; 
extern float x_float;
extern float y_float;
extern volatile float temperature;
extern volatile uint16_t ADC1_DMA_buf[4];
extern volatile uint16_t ADC2_DMA_buf[4];
extern uint16_t current_offset[3];
extern float Vdda;
extern volatile motor_vars_t MotorVars;
extern char cmd_tmp[8];
extern float hfi_debug_buf[128];
extern float hfi_vdq_buf[128];
extern uint32_t fast_loop_cnt;
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define red_led_Pin LL_GPIO_PIN_6
#define red_led_GPIO_Port GPIOC
#ifndef NVIC_PRIORITYGROUP_0
#define NVIC_PRIORITYGROUP_0         ((uint32_t)0x00000007) /*!< 0 bit  for pre-emption priority,
                                                                 4 bits for subpriority */
#define NVIC_PRIORITYGROUP_1         ((uint32_t)0x00000006) /*!< 1 bit  for pre-emption priority,
                                                                 3 bits for subpriority */
#define NVIC_PRIORITYGROUP_2         ((uint32_t)0x00000005) /*!< 2 bits for pre-emption priority,
                                                                 2 bits for subpriority */
#define NVIC_PRIORITYGROUP_3         ((uint32_t)0x00000004) /*!< 3 bits for pre-emption priority,
                                                                 1 bit  for subpriority */
#define NVIC_PRIORITYGROUP_4         ((uint32_t)0x00000003) /*!< 4 bits for pre-emption priority,
                                                                 0 bit  for subpriority */
#define CCMRAM_SRAM2_OFFSET          ((uint32_t)0x10005800) // Offset from CCMRAM to its aliased address at the end of SRAM2
#endif
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
