/*
 * pwmTimer.c
 *
 *  Created on: 25 oct. 2016
 *      Author: kerhoas
 */


#include "pwmTimer.h"
#include "stm32f4xx_hal.h"

//================================================================
void pwmTimer_Init(void)
{
  TIM_SlaveConfigTypeDef sSlaveConfig;
  TIM_MasterConfigTypeDef sMasterConfig;
  TIM_OC_InitTypeDef sConfigOC;
  TIM_ClearInputConfigTypeDef sClearInputConfig;
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig;

  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 0;
  htim1.Init.CounterMode = TIM_COUNTERMODE_CENTERALIGNED2;//TIM_COUNTERMODE_CENTERALIGNED2;
  htim1.Init.Period = (PWM_COUNT_PERIOD-1)*ADJUST;//*(36045/32768);
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  HAL_TIM_Base_Init(&htim1);
  HAL_TIM_PWM_Init(&htim1);
  //--------------------------------------------------------
  sSlaveConfig.SlaveMode = TIM_SLAVEMODE_TRIGGER;
  sSlaveConfig.InputTrigger = TIM_TS_ITR3; // TRIGGER FROM TIMER 3
  HAL_TIM_SlaveConfigSynchronization(&htim1, &sSlaveConfig);

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_ENABLE;
  HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig);

  //------------------------------------------------------------

  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_ENABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_ENABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 5;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_ENABLE;
  HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig);

  //------------------------------------------------------------
  sConfigOC.OCMode = TIM_OCMODE_PWM2; // _PWM1 : Clear on compare match / _PWM2 : Set on compare match
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_LOW;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_LOW;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1);
  HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_2);
  HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_3);

  sClearInputConfig.ClearInputSource = TIM_CLEARINPUTSOURCE_ETR;
  sClearInputConfig.ClearInputPolarity = TIM_CLEARINPUTPOLARITY_NONINVERTED;
  sClearInputConfig.ClearInputPrescaler = TIM_CLEARINPUTPRESCALER_DIV1;
  sClearInputConfig.ClearInputFilter = 0;
  HAL_TIM_ConfigOCrefClear(&htim1, &sClearInputConfig, TIM_CHANNEL_1);
  HAL_TIM_ConfigOCrefClear(&htim1, &sClearInputConfig, TIM_CHANNEL_2);
  HAL_TIM_ConfigOCrefClear(&htim1, &sClearInputConfig, TIM_CHANNEL_3);
}
//================================================================
