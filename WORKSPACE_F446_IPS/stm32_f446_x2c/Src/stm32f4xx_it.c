#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "stm32f4xx_it.h"
#include "6Step_Lib.h"

extern ADC_HandleTypeDef 	hadc1;
extern TIM_HandleTypeDef 	htim1;
extern UART_HandleTypeDef 	Uart2Handle;
extern TIM_HandleTypeDef    TimHandle_period;
extern TIM_HandleTypeDef    h_TimPulseGenerator;
extern CAN_HandleTypeDef 	CanHandle;
extern DMA_HandleTypeDef 	hdma_adc1;

extern void xPortSysTickHandler(void);
/******************************************************************************/
/*            Cortex-M4 Processor Interruption and Exception Handlers         */ 
/******************************************************************************/
void ADC_IRQHandler(void)
{
  HAL_ADC_IRQHandler(&hadc1);
}
//==============================================================================
void SysTick_Handler(void)
{
	if (xTaskGetSchedulerState() != taskSCHEDULER_NOT_STARTED)
	    {
	      xPortSysTickHandler();
	    }
  HAL_IncTick();
}
//==============================================================================
void USART2_IRQHandler(void)
{
	HAL_UART_IRQHandler(&Uart2Handle);
}
//==============================================================================
void TIM3_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&TimHandle_period);
}
//==============================================================================
void TIM1_UP_TIM10_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&htim1);
}
//==============================================================================
void TIM5_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&h_TimPulseGenerator);
}
//==============================================================================
void EXTI15_10_IRQHandler(void)
{
 if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_13))
{ HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);}		// BUTTON PC13
 else
 { HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_10);}		// Index
}


void EXTI9_5_IRQHandler(void)
{
 if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_5))
{ HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_5);}		// Fin de course PC5
}

void EXTI4_IRQHandler(void)
{

HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);		// Fin de course PA4

}


//==============================================================================
void TIM1_BRK_TIM9_IRQHandler(void)
{
  if(__HAL_TIM_GET_FLAG(&htim1, TIM_FLAG_BREAK) != RESET)
  {
	  htim1.Instance->CR1 &= ~(TIM_CR1_CEN);
	  htim1.Instance->CNT = 0;
	  HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);           //TIM1_CH1 DISABLE
	  HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);           //TIM1_CH2 DISABLE
	  HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_3);           //TIM1_CH3 DISABLE
	  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,GPIO_PIN_RESET);//BSP_X_NUCLEO_FAULT_LED_OFF();
  }
  HAL_TIM_IRQHandler(&htim1);
}
//==============================================================================
void DMA2_Stream0_IRQHandler(void)
{
	HAL_DMA_IRQHandler(&hdma_adc1);
}
//==============================================================================
void CAN1_RX0_IRQHandler(void)
{
	HAL_CAN_IRQHandler(&CanHandle);
}
//==============================================================================
void CAN1_RX1_IRQHandler(void)
{
	HAL_CAN_IRQHandler(&CanHandle);
}
//==============================================================================
