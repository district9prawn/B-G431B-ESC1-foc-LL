/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*                        The Embedded Experts                        *
**********************************************************************

-------------------------- END-OF-HEADER -----------------------------

File    : main.c
Purpose : Generic application start
*/
/* Includes */
#include "main.h"

/* Private variables */
volatile uint32_t isr_cnt;
volatile uint32_t slow_loop_cnt;
uint32_t tim2_cnt;
uint32_t addr = 0;
volatile uint16_t ADC1_DMA_buf[4]; // Raw voltage and current values from ADC1
__attribute((section(".CCM_RAM1"))) 
volatile uint16_t ADC2_DMA_buf[4]; // Raw voltage and current values from ADC2
// volatile uint16_t Vbus_adc; // Raw adc values from Vbus
float Vbus;
float Vdda;
volatile float temperature;
uint16_t VREF_adc;
volatile motor_vars_t MotorVars; // Place in CCM SRAM

/* Testing */
volatile uint32_t isr_cycles; // Count execution time of isr
int cordic_input;
float sin_res;
float cos_res;
float angle;
float x_float = 0.866025f;
float y_float = 0.5f; 
float PI_res;
float fb = 0;
uint16_t current_offset[3] = {0x9EB, 0x9EB, 0x9FA};
PI_obj PI_test;
char cmd_tmp[8];

/*  RTT buffers
    Leave buffer 0 for printf output as terminal can only display RTT buffer 0 */
char RTT_buf1[1024];  

/* Function prototypes */
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM1_Init(void);
static void MX_TIM2_Init(void);
static void MX_TIM3_Init(void);
static void MX_TIM7_Init(void);
static void MX_ADC1_Init(void);
static void MX_ADC2_Init(void);
static void MX_OPAMP1_Init(void);
static void MX_OPAMP2_Init(void);
static void MX_OPAMP3_Init(void);
static void MX_DMA_Init(void);
static void MX_CORDIC_Init(void);
static float measure_Vdda_ADC1(void);


// VREFINT_CAL_VREF

int main(void)
{
  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);

  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
  //NVIC_SetPriorityGrouping(2U);

  /* System interrupt init*/
  /* SysTick_IRQn interrupt configuration */
  NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),15, 0));

  /** Disable the internal Pull-Up in Dead Battery pins of UCPD peripheral
  */
  LL_PWR_DisableUCPDDeadBattery();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all the configured peripherals */
  MX_GPIO_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM7_Init();
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_ADC2_Init();
  MX_OPAMP1_Init();
  MX_OPAMP2_Init();
  MX_OPAMP3_Init();
  MX_CORDIC_Init();
  
  PI_init(&PI_test, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f);

  /* Initialize motor vars before PWM timer */
  MotorVars.phase = -M_PI * 0.5f;
  MotorVars.Vdq_ref[0] = 0.0f;
  MotorVars.Vdq_ref[1] = 0.0f;

  // TODO: Put this in ADC_INIT where DMA is configured
  /* Setup DMA transfers from ADC1 */
  LL_DMA_SetDataLength(DMA1, LL_DMA_CHANNEL_2, 4);
  LL_DMA_SetPeriphAddress(DMA1, LL_DMA_CHANNEL_2, (uint32_t)&ADC1->DR);
  LL_DMA_SetMemoryAddress(DMA1, LL_DMA_CHANNEL_2, (uint32_t)ADC1_DMA_buf);
  LL_DMA_EnableChannel(DMA1, LL_DMA_CHANNEL_2);

  /* Setup DMA transfers from ADC2 */
  LL_DMA_SetDataLength(DMA1, LL_DMA_CHANNEL_1, 4);
  LL_DMA_SetPeriphAddress(DMA1, LL_DMA_CHANNEL_1, (uint32_t)&ADC2->DR);
  LL_DMA_SetMemoryAddress(DMA1, LL_DMA_CHANNEL_1, (uint32_t)(ADC2_DMA_buf));
  LL_DMA_EnableChannel(DMA1, LL_DMA_CHANNEL_1);

  /* Enable TIM1 and its PWM outputs */
  LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH1);
  LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH1N);
  LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH2);
  LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH2N);
  LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH3);
  LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH3N);
  LL_TIM_EnableCounter(TIM1);
  // LL_TIM_EnableAllOutputs(TIM1); // MOE bit

  /* Start free running TIM2 */
  LL_TIM_EnableCounter(TIM2);

  /* Start LED blinking TIM3 */
  LL_TIM_CC_EnableChannel(TIM3, LL_TIM_CHANNEL_CH1);
  LL_TIM_EnableCounter(TIM3);
  LL_TIM_EnableAllOutputs(TIM3); // MOE bit

  /* Enable op amps */
  LL_OPAMP_Enable(OPAMP1);
  LL_OPAMP_Enable(OPAMP2);
  LL_OPAMP_Enable(OPAMP3);

  /* Configure, enable and start ADC1 */
  LL_ADC_Enable(ADC1);
  LL_mDelay(10); // Wait for ADC to stabilize after enable. 
  Vdda = measure_Vdda_ADC1();
  LL_ADC_REG_StartConversion(ADC1);

  /* Enable ADC2 and start regular conversions */
  LL_ADC_Enable(ADC2);
  LL_mDelay(10); // Wait for ADC to stabilize after enable. 
  LL_ADC_REG_StartConversion(ADC2);

  /* Enable TIM7 update interrupt */
  LL_TIM_EnableIT_UPDATE(TIM7);
  LL_TIM_EnableCounter(TIM7);

  /* Initialize PI controller instance */
  //PI_init(&PI_test, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f);
  //int i;
  //for(i=0; i<11; i++) {
  //PI_run(&PI_test, (float)i, 5.0f, &PI_res);
  //__ASM("nop");
  //  }

  float VREFINT_CAL = (float)*VREFINT_CAL_ADDR;
  cordic_input = (int)angle * M_Q31_PI; // WTF is this

  /* RTT init (is this necessary) */
  SEGGER_RTT_Init();

  /* Rename RTT buffer for J-Scope. Leave buffer 0 for terminal output. */
  SEGGER_RTT_ConfigUpBuffer(1, "JScope_u4u4u4", RTT_buf1, 1024, 0);

  /* Infinite loop */
  while (1)
  {
    // LL_GPIO_TogglePin(GPIOC, LL_GPIO_PIN_6);

    /* Periodically change AWD2 thresholds to blank the PWM */
    //LL_ADC_ConfigAnalogWDThresholds(ADC1, LL_ADC_AWD2, 0xfa0, 0x01);
    //LL_mDelay(2000);
    //LL_ADC_ConfigAnalogWDThresholds(ADC1, LL_ADC_AWD2, 0x03, 0x01);
    //LL_mDelay(2000);

    
    
    LL_mDelay(100);
  }  

}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_3);
  while(LL_FLASH_GetLatency() != LL_FLASH_LATENCY_3)
  {
  }
  LL_PWR_SetRegulVoltageScaling(LL_PWR_REGU_VOLTAGE_SCALE1);
  LL_RCC_HSE_Enable();
   /* Wait till HSE is ready */
  while(LL_RCC_HSE_IsReady() != 1)
  {
  }

  /* Disable PLL before modifying PLL configuration (see TRM) */
  CLEAR_BIT(RCC->CR, RCC_CR_PLLON);
  while (LL_RCC_PLL_IsReady() == 1);
  LL_RCC_PLL_DisableDomain_SYS(); // Disable PLL main output through R divider

  /* Configure PLL */
  LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSE, LL_RCC_PLLM_DIV_2, 84, LL_RCC_PLLR_DIV_2);
  LL_RCC_PLL_EnableDomain_SYS();
  LL_RCC_PLL_Enable();
   /* Wait until PLL is ready */
  while(LL_RCC_PLL_IsReady() != 1)
  {
  }

  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_2);
   /* Wait until System clock is ready */
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL)
  {
  }

  /* Insure 1?s transition state at intermediate medium speed clock based on DWT */
  CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
  DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
  DWT->CYCCNT = 0;
  while(DWT->CYCCNT < 100);
  /* Set AHB prescaler*/
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);

  LL_Init1msTick(168000000);

  LL_SetSystemCoreClock(168000000);
  LL_RCC_ConfigMCO(LL_RCC_MCO1SOURCE_HSE, LL_RCC_MCO1_DIV_1);
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOC);
  LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOF);
  LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOG);
  LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA);
  LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOB);

  /* GPIO_BEMF pin needs to be reset to low state for correct Vphase measurements  */
  LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

  /* Red LED pin config */
  GPIO_InitStruct.Pin = LL_GPIO_PIN_10;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  GPIO_InitStruct.Alternate = LL_GPIO_AF_0;
  LL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /* GPIO_BEMF pin config */
  GPIO_InitStruct.Pin = LL_GPIO_PIN_5;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

static void MX_ADC1_Init(void)
{
  LL_ADC_InitTypeDef ADC_InitStruct = {0};
  LL_ADC_REG_InitTypeDef ADC_REG_InitStruct = {0};
  LL_ADC_CommonInitTypeDef ADC_CommonInitStruct = {0};

  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
  
  /* Clocks */
  LL_RCC_SetADCClockSource(LL_RCC_ADC12_CLKSOURCE_SYSCLK);
  LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_ADC12); // Enable ADC peripheral clock
  LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA); // Enable GPIOA peripheral clock
  LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOB); // Enable GPIOB peripheral clock

  /**ADC1 GPIO Configuration
  PA0   ------> ADC1_IN1    (Vbus) 
  PB11  ------> ADC1_IN14   (Vphase3) 
  PB14  ------> ADC1_IN5    (Temperature) */
  
  /* Set pins to analog mode */
  GPIO_InitStruct.Pin = LL_GPIO_PIN_0;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = LL_GPIO_PIN_11;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = LL_GPIO_PIN_14;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* Register ADC12 global interrupt in NVIC */
  NVIC_SetPriority(ADC1_2_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(ADC1_2_IRQn);

  /* ADC1 DMA init */
  LL_DMA_SetPeriphRequest(DMA1, LL_DMA_CHANNEL_2, LL_DMAMUX_REQ_ADC1);
  LL_DMA_SetDataTransferDirection(DMA1, LL_DMA_CHANNEL_2, LL_DMA_DIRECTION_PERIPH_TO_MEMORY);
  LL_DMA_SetChannelPriorityLevel(DMA1, LL_DMA_CHANNEL_2, LL_DMA_PRIORITY_MEDIUM);
  LL_DMA_SetMode(DMA1, LL_DMA_CHANNEL_2, LL_DMA_MODE_CIRCULAR);
  LL_DMA_SetPeriphIncMode(DMA1, LL_DMA_CHANNEL_2, LL_DMA_PERIPH_NOINCREMENT);
  LL_DMA_SetMemoryIncMode(DMA1, LL_DMA_CHANNEL_2, LL_DMA_MEMORY_INCREMENT);
  LL_DMA_SetPeriphSize(DMA1, LL_DMA_CHANNEL_2, LL_DMA_PDATAALIGN_HALFWORD);
  LL_DMA_SetMemorySize(DMA1, LL_DMA_CHANNEL_2, LL_DMA_MDATAALIGN_HALFWORD);

  /* Configure ADC */
  ADC_InitStruct.Resolution = LL_ADC_RESOLUTION_12B;
  ADC_InitStruct.DataAlignment = LL_ADC_DATA_ALIGN_RIGHT;
  ADC_InitStruct.LowPowerMode = LL_ADC_LP_MODE_NONE;
  LL_ADC_Init(ADC1, &ADC_InitStruct);
  ADC_REG_InitStruct.TriggerSource = LL_ADC_REG_TRIG_EXT_TIM1_TRGO;
  ADC_REG_InitStruct.SequencerLength = LL_ADC_REG_SEQ_SCAN_ENABLE_4RANKS;
  ADC_REG_InitStruct.SequencerDiscont = LL_ADC_REG_SEQ_DISCONT_DISABLE;
  ADC_REG_InitStruct.ContinuousMode = LL_ADC_REG_CONV_SINGLE;
  ADC_REG_InitStruct.DMATransfer = LL_ADC_REG_DMA_TRANSFER_UNLIMITED;
  ADC_REG_InitStruct.Overrun = LL_ADC_REG_OVR_DATA_OVERWRITTEN;
  LL_ADC_REG_Init(ADC1, &ADC_REG_InitStruct);
  LL_ADC_SetGainCompensation(ADC1, 0);
  LL_ADC_SetOverSamplingScope(ADC1, LL_ADC_OVS_DISABLE);
  ADC_CommonInitStruct.CommonClock = LL_ADC_CLOCK_SYNC_PCLK_DIV4;
  ADC_CommonInitStruct.Multimode = LL_ADC_MULTI_INDEPENDENT;
  LL_ADC_CommonInit(__LL_ADC_COMMON_INSTANCE(ADC1), &ADC_CommonInitStruct);
  LL_ADC_REG_SetTriggerEdge(ADC1, LL_ADC_REG_TRIG_EXT_RISING);

  /* Disable ADC deep power down (enabled by default after reset state) */
  LL_ADC_DisableDeepPowerDown(ADC1);
  /* Enable ADC internal voltage regulator */
  LL_ADC_EnableInternalRegulator(ADC1);
  LL_mDelay(10); // Delay for regulator voltage stabilization.
  // TODO: Experiment and reduce regulator voltage stabilization time

  /* Run ADC calibration
    Before calibration start, should have DEEPPWD=0, ADVREGEN=1 and ADEN=0 */
  LL_ADC_StartCalibration(ADC1, LL_ADC_SINGLE_ENDED);
  while (LL_ADC_IsCalibrationOnGoing(ADC1)); // Wait until ADCAL=0

  /* Configure Analog Watchdog 1 */
  LL_ADC_SetAnalogWDMonitChannels(ADC1, LL_ADC_AWD2, LL_ADC_AWD_CH_VOPAMP1_REG);
  LL_ADC_ConfigAnalogWDThresholds(ADC1, LL_ADC_AWD2, 0xfa, 1);
  LL_ADC_SetAWDFilteringConfiguration(ADC1, LL_ADC_AWD2, LL_ADC_AWD_FILTERING_2SAMPLES);
  LL_ADC_EnableIT_AWD2(ADC1);

  /* Configure Vopamp1 channel */
  LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_1, LL_ADC_CHANNEL_VOPAMP1);
  LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_VOPAMP1, LL_ADC_SAMPLINGTIME_2CYCLES_5);
  LL_ADC_SetChannelSingleDiff(ADC1, LL_ADC_CHANNEL_VOPAMP1, LL_ADC_SINGLE_ENDED);

  ///* Configure VREFINT channel */
  //LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_1, LL_ADC_CHANNEL_VREFINT);
  //LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_VREFINT, LL_ADC_SAMPLINGTIME_92CYCLES_5);
  //LL_ADC_SetChannelSingleDiff(ADC1, LL_ADC_CHANNEL_VREFINT, LL_ADC_SINGLE_ENDED);

  /* Configure Vphase3 channel */
  LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_2, LL_ADC_CHANNEL_14);
  LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_14, LL_ADC_SAMPLINGTIME_2CYCLES_5);
  LL_ADC_SetChannelSingleDiff(ADC1, LL_ADC_CHANNEL_14, LL_ADC_SINGLE_ENDED);

  /* Configure Vbus channel */
  LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_3, LL_ADC_CHANNEL_1);
  LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_1, LL_ADC_SAMPLINGTIME_12CYCLES_5);
  LL_ADC_SetChannelSingleDiff(ADC1, LL_ADC_CHANNEL_1, LL_ADC_SINGLE_ENDED);

  /* Configure temperature channel */
  LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_4, LL_ADC_CHANNEL_5);
  LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_5, LL_ADC_SAMPLINGTIME_12CYCLES_5);
  LL_ADC_SetChannelSingleDiff(ADC1, LL_ADC_CHANNEL_5, LL_ADC_SINGLE_ENDED);
} 

static void MX_ADC2_Init(void)
{
  LL_ADC_InitTypeDef ADC_InitStruct = {0};
  LL_ADC_REG_InitTypeDef ADC_REG_InitStruct = {0};
  LL_ADC_CommonInitTypeDef ADC_CommonInitStruct = {0};

  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* Clocks */
  LL_RCC_SetADCClockSource(LL_RCC_ADC12_CLKSOURCE_SYSCLK);
  LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_ADC12); // Enable ADC peripheral clock
  LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOC);

  /**ADC2 GPIO Configuration
  PA4   ------> ADC2_IN17   (Vphase1)
  PC4   ------> ADC2_IN5    (Vphase2)
  */

  /* Set pins to analog mode */
  GPIO_InitStruct.Pin = LL_GPIO_PIN_4;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = LL_GPIO_PIN_4;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* ADC2 DMA Init */
  LL_DMA_SetPeriphRequest(DMA1, LL_DMA_CHANNEL_1, LL_DMAMUX_REQ_ADC2);
  LL_DMA_SetDataTransferDirection(DMA1, LL_DMA_CHANNEL_1, LL_DMA_DIRECTION_PERIPH_TO_MEMORY);
  LL_DMA_SetChannelPriorityLevel(DMA1, LL_DMA_CHANNEL_1, LL_DMA_PRIORITY_MEDIUM);
  LL_DMA_SetMode(DMA1, LL_DMA_CHANNEL_1, LL_DMA_MODE_CIRCULAR);
  LL_DMA_SetPeriphIncMode(DMA1, LL_DMA_CHANNEL_1, LL_DMA_PERIPH_NOINCREMENT);
  LL_DMA_SetMemoryIncMode(DMA1, LL_DMA_CHANNEL_1, LL_DMA_MEMORY_INCREMENT);
  LL_DMA_SetPeriphSize(DMA1, LL_DMA_CHANNEL_1, LL_DMA_PDATAALIGN_HALFWORD);
  LL_DMA_SetMemorySize(DMA1, LL_DMA_CHANNEL_1, LL_DMA_MDATAALIGN_HALFWORD);

  /* Configure ADC */
  ADC_InitStruct.Resolution = LL_ADC_RESOLUTION_12B;
  ADC_InitStruct.DataAlignment = LL_ADC_DATA_ALIGN_RIGHT;
  ADC_InitStruct.LowPowerMode = LL_ADC_LP_MODE_NONE;
  LL_ADC_Init(ADC2, &ADC_InitStruct);
  ADC_REG_InitStruct.TriggerSource = LL_ADC_REG_TRIG_EXT_TIM1_TRGO;
  ADC_REG_InitStruct.SequencerLength = LL_ADC_REG_SEQ_SCAN_ENABLE_4RANKS;
  ADC_REG_InitStruct.SequencerDiscont = LL_ADC_REG_SEQ_DISCONT_DISABLE;
  ADC_REG_InitStruct.ContinuousMode = LL_ADC_REG_CONV_SINGLE;
  ADC_REG_InitStruct.DMATransfer = LL_ADC_REG_DMA_TRANSFER_UNLIMITED;
  ADC_REG_InitStruct.Overrun = LL_ADC_REG_OVR_DATA_OVERWRITTEN;
  LL_ADC_REG_Init(ADC2, &ADC_REG_InitStruct);
  LL_ADC_SetGainCompensation(ADC2, 0);
  LL_ADC_SetOverSamplingScope(ADC2, LL_ADC_OVS_DISABLE);
  ADC_CommonInitStruct.CommonClock = LL_ADC_CLOCK_SYNC_PCLK_DIV4; 
  LL_ADC_CommonInit(__LL_ADC_COMMON_INSTANCE(ADC2), &ADC_CommonInitStruct);
  LL_ADC_REG_SetTriggerEdge(ADC2, LL_ADC_REG_TRIG_EXT_RISING);

  /* Disable ADC deep power down (enabled by default after reset state) */
  LL_ADC_DisableDeepPowerDown(ADC2);
  /* Enable ADC internal voltage regulator */
  LL_ADC_EnableInternalRegulator(ADC2);
  LL_mDelay(100); // Delay for regulator voltage stabilization

  /* Run ADC calibration
    Need DEEPPWD=0, ADVREGEN=1 and ADEN=0 */
  LL_ADC_StartCalibration(ADC2, LL_ADC_SINGLE_ENDED);
  while (LL_ADC_IsCalibrationOnGoing(ADC2)); // Wait until ADCAL=0

  /* Configure Vopamp2 channel */
  LL_ADC_REG_SetSequencerRanks(ADC2, LL_ADC_REG_RANK_1, LL_ADC_CHANNEL_VOPAMP2);
  LL_ADC_SetChannelSamplingTime(ADC2, LL_ADC_CHANNEL_VOPAMP2, LL_ADC_SAMPLINGTIME_2CYCLES_5);
  LL_ADC_SetChannelSingleDiff(ADC2,LL_ADC_CHANNEL_VOPAMP2, LL_ADC_SINGLE_ENDED);

  /* Configure Vopamp3 channel */
  LL_ADC_REG_SetSequencerRanks(ADC2, LL_ADC_REG_RANK_2, LL_ADC_CHANNEL_VOPAMP3_ADC2);
  LL_ADC_SetChannelSamplingTime(ADC2, LL_ADC_CHANNEL_VOPAMP3_ADC2, LL_ADC_SAMPLINGTIME_2CYCLES_5);
  LL_ADC_SetChannelSingleDiff(ADC2,LL_ADC_CHANNEL_VOPAMP3_ADC2, LL_ADC_SINGLE_ENDED);

  /* Configure Vphase1 channel */
  LL_ADC_REG_SetSequencerRanks(ADC2, LL_ADC_REG_RANK_3, LL_ADC_CHANNEL_17);
  LL_ADC_SetChannelSamplingTime(ADC2, LL_ADC_CHANNEL_17, LL_ADC_SAMPLINGTIME_2CYCLES_5);
  LL_ADC_SetChannelSingleDiff(ADC2, LL_ADC_CHANNEL_17, LL_ADC_SINGLE_ENDED);

  /* Configure Vphase2 channel */
  LL_ADC_REG_SetSequencerRanks(ADC2, LL_ADC_REG_RANK_4, LL_ADC_CHANNEL_5);
  LL_ADC_SetChannelSamplingTime(ADC2, LL_ADC_CHANNEL_5, LL_ADC_SAMPLINGTIME_2CYCLES_5);
  LL_ADC_SetChannelSingleDiff(ADC2, LL_ADC_CHANNEL_5, LL_ADC_SINGLE_ENDED);
}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{
  LL_TIM_InitTypeDef TIM_InitStruct = {0};
  LL_TIM_OC_InitTypeDef TIM_OC_InitStruct = {0};
  LL_TIM_BDTR_InitTypeDef TIM_BDTRInitStruct = {0};

  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* Peripheral clock enable */
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_TIM1);

  /* Configure timer counter */
  TIM_InitStruct.Prescaler = 0;
  TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_CENTER_UP_DOWN;
  TIM_InitStruct.Autoreload = 8399;
  TIM_InitStruct.ClockDivision = LL_TIM_CLOCKDIVISION_DIV1;
  TIM_InitStruct.RepetitionCounter = 0;
  LL_TIM_Init(TIM1, &TIM_InitStruct);

  /* Configure PWM ch1 */
  LL_TIM_DisableARRPreload(TIM1);
  LL_TIM_OC_EnablePreload(TIM1, LL_TIM_CHANNEL_CH1);
  TIM_OC_InitStruct.OCMode = LL_TIM_OCMODE_PWM1;
  TIM_OC_InitStruct.OCState = LL_TIM_OCSTATE_DISABLE;
  TIM_OC_InitStruct.OCNState = LL_TIM_OCSTATE_DISABLE;
  TIM_OC_InitStruct.CompareValue = 5900;
  TIM_OC_InitStruct.OCPolarity = LL_TIM_OCPOLARITY_HIGH;
  TIM_OC_InitStruct.OCNPolarity = LL_TIM_OCPOLARITY_HIGH;
  TIM_OC_InitStruct.OCIdleState = LL_TIM_OCIDLESTATE_LOW;
  TIM_OC_InitStruct.OCNIdleState = LL_TIM_OCIDLESTATE_LOW;
  LL_TIM_OC_Init(TIM1, LL_TIM_CHANNEL_CH1, &TIM_OC_InitStruct);
  LL_TIM_OC_DisableFast(TIM1, LL_TIM_CHANNEL_CH1);

  /* Configure PWM ch2 */
  LL_TIM_OC_EnablePreload(TIM1, LL_TIM_CHANNEL_CH2);
  TIM_OC_InitStruct.CompareValue = 1111;
  LL_TIM_OC_Init(TIM1, LL_TIM_CHANNEL_CH2, &TIM_OC_InitStruct);
  LL_TIM_OC_DisableFast(TIM1, LL_TIM_CHANNEL_CH2);

  /* Configure PWM ch3 */
  LL_TIM_OC_EnablePreload(TIM1, LL_TIM_CHANNEL_CH3);
  TIM_OC_InitStruct.CompareValue = 2222;
  LL_TIM_OC_Init(TIM1, LL_TIM_CHANNEL_CH3, &TIM_OC_InitStruct);
  LL_TIM_OC_DisableFast(TIM1, LL_TIM_CHANNEL_CH3);

  /* Configure ch4 as output compare (no output) for adc trigger 
    Trgo edge twice per pwm cycle. ADC trigger on rising edge for v0 only.*/
  TIM_OC_InitStruct.OCMode = LL_TIM_OCMODE_TOGGLE;
  TIM_OC_InitStruct.CompareValue = 1800; // Counter value where ADC is triggered
  LL_TIM_OC_Init(TIM1, LL_TIM_CHANNEL_CH4, &TIM_OC_InitStruct);
  LL_TIM_OC_DisableFast(TIM1, LL_TIM_CHANNEL_CH4);
  LL_TIM_SetTriggerOutput(TIM1, LL_TIM_TRGO_OC4REF);
  LL_TIM_SetTriggerOutput2(TIM1, LL_TIM_TRGO2_RESET);
  LL_TIM_DisableMasterSlaveMode(TIM1);

  /* Set trgo on update event
    Trgo will fire in the middle of v0 and v7 */
  //LL_TIM_SetTriggerOutput(TIM1, LL_TIM_TRGO_UPDATE);
  //LL_TIM_SetTriggerOutput2(TIM1, LL_TIM_TRGO2_RESET);

  /* Configure break and dead-time register */
  TIM_BDTRInitStruct.OSSRState = LL_TIM_OSSR_DISABLE;
  TIM_BDTRInitStruct.OSSIState = LL_TIM_OSSI_DISABLE;
  TIM_BDTRInitStruct.LockLevel = LL_TIM_LOCKLEVEL_OFF;
  TIM_BDTRInitStruct.DeadTime = 35;
  TIM_BDTRInitStruct.BreakState = LL_TIM_BREAK_DISABLE;
  TIM_BDTRInitStruct.BreakPolarity = LL_TIM_BREAK_POLARITY_HIGH;
  TIM_BDTRInitStruct.BreakFilter = LL_TIM_BREAK_FILTER_FDIV1;
  TIM_BDTRInitStruct.BreakAFMode = LL_TIM_BREAK_AFMODE_INPUT;
  TIM_BDTRInitStruct.Break2State = LL_TIM_BREAK2_DISABLE;
  TIM_BDTRInitStruct.Break2Polarity = LL_TIM_BREAK2_POLARITY_HIGH;
  TIM_BDTRInitStruct.Break2Filter = LL_TIM_BREAK2_FILTER_FDIV1;
  TIM_BDTRInitStruct.Break2AFMode = LL_TIM_BREAK_AFMODE_INPUT;
  TIM_BDTRInitStruct.AutomaticOutput = LL_TIM_AUTOMATICOUTPUT_DISABLE;
  LL_TIM_BDTR_Init(TIM1, &TIM_BDTRInitStruct);

  LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOC);
  LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA);
  /**TIM1 GPIO Configuration
  PA8   TIM1_CH1
  PC13  TIM1_CH1N
  PA9   TIM1_CH2
  PA12  TIM1_CH2N
  PA10  TIM1_CH3
  PB15  TIM1_CH3N
  */

  /* TIM1_CH1 on PA8 */
  GPIO_InitStruct.Pin = LL_GPIO_PIN_8;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  GPIO_InitStruct.Alternate = LL_GPIO_AF_6;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* TIM1_CH1n on PC13 */
  GPIO_InitStruct.Pin = LL_GPIO_PIN_13;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  GPIO_InitStruct.Alternate = LL_GPIO_AF_4;
  LL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* TIM1_CH2 on PA9 */
  GPIO_InitStruct.Pin = LL_GPIO_PIN_9;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  GPIO_InitStruct.Alternate = LL_GPIO_AF_6;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* TIM1_CH2N on PA12 */
  GPIO_InitStruct.Pin = LL_GPIO_PIN_12;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  GPIO_InitStruct.Alternate = LL_GPIO_AF_6;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* TIM1_CH3 on PA10 */
  GPIO_InitStruct.Pin = LL_GPIO_PIN_10;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  GPIO_InitStruct.Alternate = LL_GPIO_AF_6;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  
  /* TIM1_CH3N on PB15 */
  GPIO_InitStruct.Pin = LL_GPIO_PIN_15;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  GPIO_InitStruct.Alternate = LL_GPIO_AF_4;
  LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* Allow AWD2 to clear OCREF signal asynchronously for current limiting */
  LL_TIM_SetETRSource(TIM1, LL_TIM_TIM1_ETRSOURCE_ADC1_AWD2); // Set AWD2 out as external trigger
  LL_TIM_ConfigETR(TIM1, LL_TIM_ETR_POLARITY_NONINVERTED, LL_TIM_ETR_PRESCALER_DIV1, LL_TIM_ETR_FILTER_FDIV1); // No filter or frequency division
  LL_TIM_SetOCRefClearInputSource(TIM1, LL_TIM_OCREF_CLR_INT_ETR); // Set OCREF clear source as ETR, not comparator
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  * Free running fast timer for general use
  */
static void MX_TIM2_Init(void)
{
  LL_TIM_InitTypeDef TIM_InitStruct = {0};

  /* Peripheral clock enable */
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM2);

  TIM_InitStruct.Prescaler = 0;
  TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_UP;
  TIM_InitStruct.Autoreload = 4.294967295E9;
  TIM_InitStruct.ClockDivision = LL_TIM_CLOCKDIVISION_DIV1;
  LL_TIM_Init(TIM2, &TIM_InitStruct);
  LL_TIM_DisableARRPreload(TIM2);
  LL_TIM_SetClockSource(TIM2, LL_TIM_CLOCKSOURCE_INTERNAL);
  LL_TIM_SetTriggerOutput(TIM2, LL_TIM_TRGO_RESET);
  LL_TIM_DisableMasterSlaveMode(TIM2);
}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{
  LL_TIM_InitTypeDef TIM_InitStruct = {0};
  LL_TIM_OC_InitTypeDef TIM_OC_InitStruct = {0};

  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* Peripheral clock enable */
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM3);

  TIM_InitStruct.Prescaler = 0;
  TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_CENTER_UP_DOWN;
  TIM_InitStruct.Autoreload = 24999;
  TIM_InitStruct.ClockDivision = LL_TIM_CLOCKDIVISION_DIV1;
  LL_TIM_Init(TIM3, &TIM_InitStruct);
  LL_TIM_DisableARRPreload(TIM3);
  LL_TIM_OC_EnablePreload(TIM3, LL_TIM_CHANNEL_CH1);
  TIM_OC_InitStruct.OCMode = LL_TIM_OCMODE_PWM1;
  TIM_OC_InitStruct.OCState = LL_TIM_OCSTATE_DISABLE;
  TIM_OC_InitStruct.OCNState = LL_TIM_OCSTATE_DISABLE;
  TIM_OC_InitStruct.CompareValue = 2499;
  TIM_OC_InitStruct.OCPolarity = LL_TIM_OCPOLARITY_HIGH;
  LL_TIM_OC_Init(TIM3, LL_TIM_CHANNEL_CH1, &TIM_OC_InitStruct);
  LL_TIM_OC_DisableFast(TIM3, LL_TIM_CHANNEL_CH1);
  LL_TIM_SetTriggerOutput(TIM3, LL_TIM_TRGO_RESET);
  LL_TIM_DisableMasterSlaveMode(TIM3);

  LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOC);
  /**TIM3 GPIO Configuration
  PC6   ------> TIM3_CH1
  */
  GPIO_InitStruct.Pin = LL_GPIO_PIN_6;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  GPIO_InitStruct.Alternate = LL_GPIO_AF_2;
  LL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}

/*  Intialize basic timer TIM7
    TIM7 periodically triggers slow loop */
static void MX_TIM7_Init(void)
{
  LL_TIM_InitTypeDef TIM_InitStruct = {0};

  /* Peripheral clock enable */
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM7);

  /* Enable TIM7 update interrupt */
  LL_TIM_EnableIT_UPDATE(TIM7);

  /* Register TIM7 interrupt vector with NVIC */
  NVIC_SetPriority(TIM7_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),10, 0));
  NVIC_EnableIRQ(TIM7_IRQn);

  TIM_InitStruct.Prescaler = 167;
  TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_UP;
  TIM_InitStruct.Autoreload = 999;
  LL_TIM_Init(TIM7, &TIM_InitStruct);
  LL_TIM_DisableARRPreload(TIM7);
  LL_TIM_SetTriggerOutput(TIM7, LL_TIM_TRGO_RESET);
  LL_TIM_DisableMasterSlaveMode(TIM7);
}

/**
  * @brief OPAMP1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_OPAMP1_Init(void)
{
  LL_OPAMP_InitTypeDef OPAMP_InitStruct = {0};

  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

  LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA);
  /**OPAMP1 GPIO Configuration
  PA1   ------> OPAMP1_VINP
  PA3   ------> OPAMP1_VINM0
  */
  GPIO_InitStruct.Pin = LL_GPIO_PIN_1;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = LL_GPIO_PIN_3;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  OPAMP_InitStruct.PowerMode = LL_OPAMP_POWERMODE_NORMALSPEED;
  OPAMP_InitStruct.FunctionalMode = LL_OPAMP_MODE_PGA_IO0_BIAS; // Input on VINM0 and input signal on VINPx
  OPAMP_InitStruct.InputNonInverting = LL_OPAMP_INPUT_NONINVERT_IO0;
  LL_OPAMP_Init(OPAMP1, &OPAMP_InitStruct);
  LL_OPAMP_SetInputsMuxMode(OPAMP1, LL_OPAMP_INPUT_MUX_DISABLE);
  LL_OPAMP_SetInternalOutput(OPAMP1, LL_OPAMP_INTERNAL_OUPUT_ENABLED);
  LL_OPAMP_SetPGAGain(OPAMP1, LL_OPAMP_PGA_GAIN_16_OR_MINUS_15);
  LL_OPAMP_SetTrimmingMode(OPAMP1, LL_OPAMP_TRIMMING_FACTORY);

}

/**
  * @brief OPAMP2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_OPAMP2_Init(void)
{
  LL_OPAMP_InitTypeDef OPAMP_InitStruct = {0};

  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

  LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA);
  /**OPAMP2 GPIO Configuration
  PA5   ------> OPAMP2_VINM0
  PA7   ------> OPAMP2_VINP
  */
  GPIO_InitStruct.Pin = LL_GPIO_PIN_5;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = LL_GPIO_PIN_7;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  OPAMP_InitStruct.PowerMode = LL_OPAMP_POWERMODE_NORMALSPEED;
  OPAMP_InitStruct.FunctionalMode = LL_OPAMP_MODE_PGA_IO0_BIAS; 
  OPAMP_InitStruct.InputNonInverting = LL_OPAMP_INPUT_NONINVERT_IO0;
  LL_OPAMP_Init(OPAMP2, &OPAMP_InitStruct);
  LL_OPAMP_SetInputsMuxMode(OPAMP2, LL_OPAMP_INPUT_MUX_DISABLE);
  LL_OPAMP_SetInternalOutput(OPAMP2, LL_OPAMP_INTERNAL_OUPUT_ENABLED);
  LL_OPAMP_SetPGAGain(OPAMP2, LL_OPAMP_PGA_GAIN_16_OR_MINUS_15);
  LL_OPAMP_SetTrimmingMode(OPAMP2, LL_OPAMP_TRIMMING_FACTORY);
}

static void MX_OPAMP3_Init(void)
{
  LL_OPAMP_InitTypeDef OPAMP_InitStruct = {0};

  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

  LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOB);
  /**OPAMP3 GPIO Configuration
  PB0   ------> OPAMP3_VINP
  PB2   ------> OPAMP3_VINM0
  */
  GPIO_InitStruct.Pin = LL_GPIO_PIN_0;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = LL_GPIO_PIN_2;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN OPAMP3_Init 1 */

  /* USER CODE END OPAMP3_Init 1 */
  OPAMP_InitStruct.PowerMode = LL_OPAMP_POWERMODE_NORMALSPEED;
  OPAMP_InitStruct.FunctionalMode = LL_OPAMP_MODE_PGA;
  OPAMP_InitStruct.InputNonInverting = LL_OPAMP_INPUT_NONINVERT_IO0;
  OPAMP_InitStruct.InputInverting = LL_OPAMP_INPUT_INVERT_IO0;
  LL_OPAMP_Init(OPAMP3, &OPAMP_InitStruct);
  LL_OPAMP_SetInputsMuxMode(OPAMP3, LL_OPAMP_INPUT_MUX_DISABLE);
  LL_OPAMP_SetInternalOutput(OPAMP3, LL_OPAMP_INTERNAL_OUPUT_ENABLED);
  LL_OPAMP_SetPGAGain(OPAMP3, LL_OPAMP_PGA_GAIN_16_OR_MINUS_15);
  LL_OPAMP_SetTrimmingMode(OPAMP3, LL_OPAMP_TRIMMING_FACTORY);
  /* USER CODE BEGIN OPAMP3_Init 2 */

  /* USER CODE END OPAMP3_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* Init with LL driver */
  /* DMA controller clock enable */
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMAMUX1);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA1);

  /* DMA1 channel 1 interrupt enable */
  LL_DMA_EnableIT_TC(DMA1, LL_DMA_CHANNEL_1); // Enable transfer complete interrupt
  LL_DMA_EnableIT_TE(DMA1, LL_DMA_CHANNEL_1); // Enable transfer error interrupt
  
  /* DMA1 channel 2 interrupt init */
  LL_DMA_EnableIT_TC(DMA1, LL_DMA_CHANNEL_2); // Enable transfer complete interrupt
  LL_DMA_EnableIT_TE(DMA1, LL_DMA_CHANNEL_2); // Enable transfer error interrupt

  // TODO: Enable other errors?

  /* Enable DMA1_Channel1_IRQn in NVIC */
  NVIC_SetPriority(DMA1_Channel1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),7,0));
  NVIC_EnableIRQ(DMA1_Channel1_IRQn);

  /* Enable DMA1_Channel2_IRQn in NVIC */
  NVIC_SetPriority(DMA1_Channel2_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),8, 0));
  NVIC_EnableIRQ(DMA1_Channel2_IRQn);
}

static void MX_CORDIC_Init(void)
{
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_CORDIC);
}

/*  Measure analog supply voltage Vdda which is connected to Vref+
    Improves absolute accuracy of measurements
    Vref+ = Vdd_charac * VREFINT_CAL / VREFINT_DATA
    VREFINT_CAL is factory calibration value stored in ROM
    VREFINT_DATA is measured VREFINT
    Vdd_charac = 3.0V +- 10mv (factory test condition)
    Run this after the ADC1 has been configured but before it has been enabled
    ADC1 channel 18 can be connected to VREFINT 
    Returns Vdda as a float */
static float measure_Vdda_ADC1(void)
{
  uint16_t VREFINT_adc; // Raw adc reading of VREFINT
  uint16_t VREFINT_CAL = *VREFINT_CAL_ADDR;
  float Vdda;
  float Vdda_charac = 3.0f;

  /* Save ADC registers */ 

  /* Configure ADC to measure VREFINT */
  while(LL_ADC_REG_IsConversionOngoing(ADC1)); // Wait until ADC idle before writing to registers
  MODIFY_REG(ADC1->CFGR, (ADC_CFGR_DMACFG | ADC_CFGR_DMAEN), LL_ADC_REG_DMA_TRANSFER_NONE); // Disable DMA transfer
  LL_ADC_REG_SetTriggerSource(ADC1, LL_ADC_REG_TRIG_SOFTWARE); // ADC triggered by software only
  LL_ADC_REG_SetSequencerLength(ADC1, LL_ADC_REG_SEQ_SCAN_DISABLE); // Sequence consists of one conversion
  LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_1, LL_ADC_CHANNEL_VREFINT);
  LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_VREFINT, LL_ADC_SAMPLINGTIME_47CYCLES_5);
  LL_ADC_SetChannelSingleDiff(ADC1, LL_ADC_CHANNEL_VREFINT, LL_ADC_SINGLE_ENDED);
  LL_ADC_SetCommonPathInternalCh(__LL_ADC_COMMON_INSTANCE(ADC1), LL_ADC_PATH_INTERNAL_VREFINT); // Enable internal pathway connecting VREFINT output to ADC1
  LL_mDelay(10); // Small delay for VREFINT internal pathway stabilization time
  
  /* Enable ADC and take measurement */
  LL_ADC_REG_StartConversion(ADC1);
  while(!LL_ADC_IsActiveFlag_EOS(ADC1)); // Wait for conversion complete
  VREFINT_adc = LL_ADC_REG_ReadConversionData12(ADC1);
  
  /* Calculate Vdda */
  Vdda = Vdda_charac * (float)VREFINT_CAL / (float)VREFINT_adc; // Equation from TRM

  /* Reconfigure ADC back to reading currents and voltages as before */
  while(LL_ADC_REG_IsConversionOngoing(ADC1)); // Wait until ADC idle before writing to registers
  MODIFY_REG(ADC1->CFGR, (ADC_CFGR_DMACFG | ADC_CFGR_DMAEN), LL_ADC_REG_DMA_TRANSFER_UNLIMITED); // Enable DMA transfer from DR
  LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_1, LL_ADC_CHANNEL_VOPAMP1);
  LL_ADC_REG_SetSequencerLength(ADC1, LL_ADC_REG_SEQ_SCAN_ENABLE_4RANKS);
  LL_ADC_REG_SetTriggerSource(ADC1,LL_ADC_REG_TRIG_EXT_TIM1_TRGO);

  return Vdda;
}


/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

//static void MX_ADC1_Init(void)
//{
//  LL_ADC_InitTypeDef ADC_InitStruct = {0};
//  LL_ADC_REG_InitTypeDef ADC_REG_InitStruct = {0};
//  LL_ADC_CommonInitTypeDef ADC_CommonInitStruct = {0};

//  LL_RCC_SetADCClockSource(LL_RCC_ADC12_CLKSOURCE_SYSCLK);

//  /* Peripheral clock enable */
//  LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_ADC12);
//  /** Common config
//  */
//  ADC_InitStruct.Resolution = LL_ADC_RESOLUTION_12B;
//  ADC_InitStruct.DataAlignment = LL_ADC_DATA_ALIGN_RIGHT;
//  ADC_InitStruct.LowPowerMode = LL_ADC_LP_MODE_NONE;
//  LL_ADC_Init(ADC1, &ADC_InitStruct);
//  ADC_REG_InitStruct.TriggerSource = LL_ADC_REG_TRIG_SOFTWARE;
//  ADC_REG_InitStruct.SequencerLength = LL_ADC_REG_SEQ_SCAN_DISABLE;
//  ADC_REG_InitStruct.SequencerDiscont = LL_ADC_REG_SEQ_DISCONT_DISABLE;
//  ADC_REG_InitStruct.ContinuousMode = LL_ADC_REG_CONV_SINGLE;
//  ADC_REG_InitStruct.DMATransfer = LL_ADC_REG_DMA_TRANSFER_NONE;
//  ADC_REG_InitStruct.Overrun = LL_ADC_REG_OVR_DATA_OVERWRITTEN;
//  LL_ADC_REG_Init(ADC1, &ADC_REG_InitStruct);
//  LL_ADC_SetGainCompensation(ADC1, 0);
//  LL_ADC_SetOverSamplingScope(ADC1, LL_ADC_OVS_DISABLE);
//  ADC_CommonInitStruct.CommonClock = LL_ADC_CLOCK_SYNC_PCLK_DIV4;
//  ADC_CommonInitStruct.Multimode = LL_ADC_MULTI_INDEPENDENT;
//  LL_ADC_CommonInit(__LL_ADC_COMMON_INSTANCE(ADC1), &ADC_CommonInitStruct);

//  /* Disable ADC deep power down (enabled by default after reset state) */
//  LL_ADC_DisableDeepPowerDown(ADC1);
//  /* Enable ADC internal voltage regulator */
//  LL_ADC_EnableInternalRegulator(ADC1);
//  /* Delay for ADC internal voltage regulator stabilization. */
//  /* Compute number of CPU cycles to wait for, from delay in us. */
//  /* Note: Variable divided by 2 to compensate partially */
//  /* CPU processing cycles (depends on compilation optimization). */
//  /* Note: If system core clock frequency is below 200kHz, wait time */
//  /* is only a few CPU processing cycles. */
//  uint32_t wait_loop_index;
//  wait_loop_index = ((LL_ADC_DELAY_INTERNAL_REGUL_STAB_US * (SystemCoreClock / (100000 * 2))) / 10);
//  while(wait_loop_index != 0)
//  {
//    wait_loop_index--;
//  }
//  /** Configure Regular Channel
//  */
//  LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_1, LL_ADC_CHANNEL_VREFINT);
//  LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_VREFINT, LL_ADC_SAMPLINGTIME_47CYCLES_5);
//  LL_ADC_SetChannelSingleDiff(ADC1, LL_ADC_CHANNEL_VREFINT, LL_ADC_SINGLE_ENDED);
//  LL_ADC_SetCommonPathInternalCh(__LL_ADC_COMMON_INSTANCE(ADC1), LL_ADC_PATH_INTERNAL_VREFINT);

//}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

