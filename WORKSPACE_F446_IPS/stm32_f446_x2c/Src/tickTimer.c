#include "tickTimer.h"
TIM_HandleTypeDef    TimHandle_period;

//================================================
//		TIMER 3 INIT : FAST TRACK UPDATE
//================================================

void tickTimerInit(uint16_t pwm_count_period)
{
  TIM_MasterConfigTypeDef sMasterConfig;
  TIM_OC_InitTypeDef sConfigOC;

  TimHandle_period.Instance = TIM3;
  TimHandle_period.Init.Prescaler = 0;
  TimHandle_period.Init.Period = 2*PWM_COUNT_PERIOD-3;
  TimHandle_period.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  TimHandle_period.Init.CounterMode = TIM_COUNTERMODE_UP;//TIM_COUNTERMODE_CENTERALIGNED1;
  TimHandle_period.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  TimHandle_period.Init.RepetitionCounter = 0;
  HAL_TIM_Base_Init(&TimHandle_period);
  HAL_TIM_PWM_Init(&TimHandle_period);

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_OC1;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_ENABLE;
  HAL_TIMEx_MasterConfigSynchronization(&TimHandle_period, &sMasterConfig);

  sConfigOC.OCMode = TIM_OCMODE_PWM1; // TIM_OCMODE_PWM2; ??  PWM1 : Clear on compare match / PWM2 : Set on compare match
  sConfigOC.Pulse =2250;//2250;//2200;//2100;//2000;		// Pour régler le moment de la conversion anlogique --> Numérique
  sConfigOC.OCPolarity = TIM_OCPOLARITY_LOW;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_LOW;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  HAL_TIM_PWM_ConfigChannel(&TimHandle_period, &sConfigOC, TIM_CHANNEL_1);
}

//================================================
