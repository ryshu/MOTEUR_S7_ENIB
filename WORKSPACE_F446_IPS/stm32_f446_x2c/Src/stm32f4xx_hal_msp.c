#include "stm32f4xx_hal.h"

#define 	TIM3_INT_PRIO		8
#define 	TIM1_INT_PRIO		7
#define 	ADC_INT_PRIO		10
#define 	TIM4_INT_PRIO		11
#define 	UART2_INT_PRIO		14
#define 	EXTI15_10_IRQ_PRIO	2
#define  	DMA_INT_PRIO   		9
#define 	TIM5_INT_PRIO		13
#define 	CAN1_RX0_INT_PRIO	12
#define 	EXTI4_IRQ_PRIO		6
#define 	EXTI9_5_IRQ_PRIO	5


void ADC1_MspInit();
void CAN1_MspInit();
void TIM1_MspInit();
void TIM3_MspInit();
void TIM2_MspInit();
void TIM5_MspInit();
void UART2_MspInit();
void GPIO_MspInit(void);

extern DMA_HandleTypeDef hdma_adc1;
//=============================================================
void HAL_MspInit(void)
{
	GPIO_MspInit();
	ADC1_MspInit();
	TIM1_MspInit();		// PWM TIMER
	TIM3_MspInit();		// TICK TIMER
	TIM2_MspInit();		// ENCODER TIMER
	TIM5_MspInit();		// PULSE GENERATOR TIMER
	UART2_MspInit();
	CAN1_MspInit();
}
//=============================================================
// CAN BUS --> CAN
// CAN1_RX : PB8
// CAN1_TD : PB9
//=============================================================
void CAN1_MspInit()
{
	 GPIO_InitTypeDef GPIO_InitStruct;
	  __GPIOB_CLK_ENABLE();
	  __CAN1_CLK_ENABLE();

	   GPIO_InitStruct.Pin = GPIO_PIN_8;
	   GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	   GPIO_InitStruct.Pull = GPIO_PULLUP;
	   GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
	   GPIO_InitStruct.Alternate = GPIO_AF9_CAN1;
	   HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	   GPIO_InitStruct.Pin = GPIO_PIN_9;
	   GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	   GPIO_InitStruct.Pull = GPIO_PULLUP;
	   GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
	   GPIO_InitStruct.Alternate = GPIO_AF9_CAN1;
	   HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	   HAL_NVIC_SetPriority(CAN1_RX0_IRQn, CAN1_RX0_INT_PRIO, 0);
	   HAL_NVIC_EnableIRQ(CAN1_RX0_IRQn);
}
//=============================================================
// ADC1 GPIO Configuration
// PB1     ------> ADC1_IN9		// SPEED (POT)
// PA0 --------> ADC1_IN0		// CURRENT FB1
// PC1 --------> ADC1_IN11		// CURRENT FB2
// PC0 --------> ADC1_IN?		// CURRENT FB3
//=============================================================
void ADC1_MspInit()
{
  GPIO_InitTypeDef GPIO_InitStruct;

    __ADC1_CLK_ENABLE();
    __GPIOC_CLK_ENABLE();
    __GPIOA_CLK_ENABLE();
    __DMA2_CLK_ENABLE();

    GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, DMA_INT_PRIO, 0);
    HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);

    HAL_NVIC_SetPriority(ADC_IRQn, ADC_INT_PRIO, 0);
    HAL_NVIC_EnableIRQ(ADC_IRQn);
}
//=============================================================
/**TIM1 GPIO Configuration
PA6     ------> TIM1_BKIN
PA8     ------> TIM1_CH1
PA9     ------> TIM1_CH2
PA10     ------> TIM1_CH3
PA12     ------> TIM1_ETR
*/
//=============================================================
void TIM1_MspInit()
{
  GPIO_InitTypeDef GPIO_InitStruct;

    __TIM1_CLK_ENABLE();
  
    GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10 |GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF1_TIM1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    HAL_NVIC_SetPriority(TIM1_BRK_TIM9_IRQn, TIM1_INT_PRIO, 0);
    HAL_NVIC_EnableIRQ(TIM1_BRK_TIM9_IRQn);
}
//=============================================================
void TIM3_MspInit()
{
    __TIM3_CLK_ENABLE();
    HAL_NVIC_SetPriority(TIM3_IRQn, TIM3_INT_PRIO, 0);
    HAL_NVIC_EnableIRQ(TIM3_IRQn);
}
//=============================================================
void TIM5_MspInit()
{
    __TIM5_CLK_ENABLE();
    HAL_NVIC_SetPriority(TIM5_IRQn, TIM5_INT_PRIO, 0);
    HAL_NVIC_EnableIRQ(TIM5_IRQn);
}
//=============================================================
// ENCODER TIMER
// PA15     ------> TIM2_CH1	-- A	/// PA15 ?
// PB10     ------> TIM2_CH3		-- Index
// PB3     ------> TIM2_CH2		-- B
//=============================================================
void TIM2_MspInit()
{
  GPIO_InitTypeDef GPIO_InitStruct;

    __TIM2_CLK_ENABLE();
  
    GPIO_InitStruct.Pin = GPIO_PIN_15;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_10;	// IIndex --> EXTI INTERRUPT
    GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}
//=============================================================
/**USART2 GPIO Configuration
PA2     ------> USART2_TX
PA3     ------> USART2_RX
*/
//=============================================================
void UART2_MspInit()
{

  GPIO_InitTypeDef GPIO_InitStruct;

    __USART2_CLK_ENABLE();

    GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    HAL_NVIC_SetPriority(USART2_IRQn, UART2_INT_PRIO, 0);
    HAL_NVIC_EnableIRQ(USART2_IRQn);
}
//=============================================================
// PC10 : EN1
// PC11 : EN2
// PC12 : EN3
//=============================================================
void GPIO_MspInit(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;

  __GPIOC_CLK_ENABLE();
  __GPIOH_CLK_ENABLE();
  __GPIOA_CLK_ENABLE();
  __GPIOB_CLK_ENABLE();

  /*Configure GPIO pin : PB8 MESURE PERIODE */
  GPIO_InitStruct.Pin = GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  // PC13 : BLUE BUTTON
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  // PC10, PC11, PC12 : ENABLE
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

 // PB2 : RED LED
  GPIO_InitStruct.Pin = GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  // FIN DE COURSE PA4
  GPIO_InitStruct.Pin = GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);


  // FIN DE COURSE PC5
  GPIO_InitStruct.Pin = GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);


  HAL_NVIC_SetPriority(EXTI4_IRQn, EXTI4_IRQ_PRIO, 0);
  HAL_NVIC_EnableIRQ(EXTI4_IRQn);

  HAL_NVIC_SetPriority(EXTI9_5_IRQn, EXTI9_5_IRQ_PRIO, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);


  HAL_NVIC_SetPriority(EXTI15_10_IRQn, EXTI15_10_IRQ_PRIO, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}
//=============================================================
//=============================================================
//=============================================================

void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef* htim_base)
{

  if(htim_base->Instance==TIM1)
  {

    __TIM1_CLK_DISABLE();
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_6|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10 
                          |GPIO_PIN_12);

    HAL_NVIC_DisableIRQ(TIM1_BRK_TIM9_IRQn);

  }
  else if(htim_base->Instance==TIM3)
  {

    __TIM3_CLK_DISABLE();
  
    /**TIM3 GPIO Configuration    
    PB4     ------> TIM3_CH1 
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_4);
  }
  else if(htim_base->Instance==TIM4)
  {
    __TIM4_CLK_DISABLE();
    HAL_NVIC_DisableIRQ(TIM4_IRQn);

  }

}

void HAL_TIMEx_HallSensor_MspDeInit(TIM_HandleTypeDef* htimex_hallsensor)
{

  if(htimex_hallsensor->Instance==TIM2)
  {
  /* USER CODE BEGIN TIM2_MspDeInit 0 */

  /* USER CODE END TIM2_MspDeInit 0 */
    /* Peripheral clock disable */
    __TIM2_CLK_DISABLE();
  
    /**TIM2 GPIO Configuration    
    PA0-WKUP     ------> TIM2_CH1
    PB10     ------> TIM2_CH3
    PB3     ------> TIM2_CH2 
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_0);

    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_10|GPIO_PIN_3);

  /* USER CODE BEGIN TIM2_MspDeInit 1 */

  /* USER CODE END TIM2_MspDeInit 1 */
  }

}



void HAL_UART_MspDeInit(UART_HandleTypeDef* huart)
{

  if(huart->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspDeInit 0 */

  /* USER CODE END USART2_MspDeInit 0 */
    /* Peripheral clock disable */
    __USART2_CLK_DISABLE();
  
    /**USART2 GPIO Configuration    
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX 
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_2|GPIO_PIN_3);

    /* Peripheral interrupt DeInit*/
    HAL_NVIC_DisableIRQ(USART2_IRQn);

  /* USER CODE BEGIN USART2_MspDeInit 1 */

  /* USER CODE END USART2_MspDeInit 1 */
  }

}

void HAL_ADC_MspDeInit(ADC_HandleTypeDef* hadc)
{

  if(hadc->Instance==ADC1)
  {
    __ADC1_CLK_DISABLE();
    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_1|GPIO_PIN_7);
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_0|GPIO_PIN_1);
    HAL_NVIC_DisableIRQ(ADC_IRQn);
  }

}
