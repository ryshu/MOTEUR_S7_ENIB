/*
 * pulseGenerator.c
 *
 *  Created on: 15 nov. 2016
 *      Author: kerhoas
 */

#include "pulseGenerator.h"

TIM_HandleTypeDef    h_TimPulseGenerator;

//============================================================================

void pulseGenerator_Init(int period)
{
	unsigned int uwPrescalerValue;

	//Compute the prescaler value to have counter clock equal to 10 KHz */
	uwPrescalerValue = (unsigned int) ((SystemCoreClock / 10000) - 1);

	h_TimPulseGenerator.Instance = TIM5;

	h_TimPulseGenerator.Init.Period = 10*period;
	h_TimPulseGenerator.Init.Prescaler = uwPrescalerValue;
	h_TimPulseGenerator.Init.ClockDivision = 0;
	h_TimPulseGenerator.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_Base_Init(&h_TimPulseGenerator);

	HAL_TIM_Base_Start_IT(&h_TimPulseGenerator);
}

//============================================================================

