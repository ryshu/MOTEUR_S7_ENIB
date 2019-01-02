/*
 * QuadEncoder.c
 */
#include "quadEncoder.h"
#define COUNT_PER_ROUND 2000
#define MAX_CNT_PER_REV (COUNT_PER_ROUND * 4 - 1)
#define MAX_COUNT (int)(((unsigned long)MAX_CNT_PER_REV*4096)/1000)
#define HALF_MAX_COUNT (MAX_COUNT>>1)

#define TE_ms	1	// Sample Period in ms

TIM_HandleTypeDef    TimEncoderHandle;

static int indexZ=-1;

int first_index_reached = 0;

//================================================================
//		TIMER INIT
//================================================================

void quadEncoder_Init(void)
{
	TIM_Encoder_InitTypeDef sConfig;

	TimEncoderHandle.Instance = TIM2;
	TimEncoderHandle.Init.Prescaler = 0;
	TimEncoderHandle.Init.CounterMode = TIM_COUNTERMODE_UP;
	TimEncoderHandle.Init.Period = COUNT_PER_ROUND*4;
	TimEncoderHandle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;

	sConfig.EncoderMode = TIM_ENCODERMODE_TI12;
	sConfig.IC1Polarity = TIM_INPUTCHANNELPOLARITY_RISING;
	sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
	sConfig.IC1Prescaler = TIM_ICPSC_DIV4;
	sConfig.IC1Filter = 0x0F;
	sConfig.IC2Polarity = TIM_INPUTCHANNELPOLARITY_RISING;
	sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;//TIM_ICSELECTION_DIRECTTI; //TIM_TI1SELECTION_XORCOMBINATION
	sConfig.IC2Prescaler = TIM_ICPSC_DIV4;
	sConfig.IC2Filter = 0x0F;

	HAL_TIM_Encoder_Init(&TimEncoderHandle, &sConfig);
	HAL_TIM_Encoder_Start(&TimEncoderHandle,TIM_CHANNEL_1);
	HAL_TIM_Encoder_Start(&TimEncoderHandle,TIM_CHANNEL_2);
}
//================================================================
//		POSITION LEFT CALC
//================================================================
void quadEncoder_PosCalc(int* AngPos)
{
	int POSCNTcopy = 0;
	POSCNTcopy = (int)TIM2->CNT;
	AngPos[1] = AngPos[0];
	AngPos[0] = (unsigned int)(((unsigned long)POSCNTcopy * 4096)/1000); // 0 <= POSCNT <= 4999 to 0 <= AngPos <= 32767
}
//================================================================
//		POSITION LEFT 16 BITS
//================================================================
uint16_t quadEncoder_GetPos16(void)
{
	uint16_t Pos = 0;
	Pos=TIM2->CNT;
	return Pos;
}
//================================================================
//		POSITION LEFT 32 BITS	(pos 16 bits + nombre de tours)
//================================================================
int32_t quadEncoder_GetPos32(void)
{
	int32_t  Pos = 0;
	Pos=indexZ*4*COUNT_PER_ROUND + (int32_t) quadEncoder_GetPos16();
	return Pos;
}
//================================================================
//		SPEED LEFT
//--> get pos and reset timer ; must be called every Te
//================================================================
int16_t quadEncoder_GetSpeed(void)
{
	static int AngPos[2] = {0,0};
	static int16_t Speed=0;


	quadEncoder_PosCalc(AngPos);
	Speed = AngPos[0] - AngPos[1];
	if (Speed >= 0)
	{
		if (Speed >= HALF_MAX_COUNT)
			{
			Speed = Speed - MAX_COUNT;
			}
	}
	else
	{
		if (Speed < -HALF_MAX_COUNT)
			{
			Speed = Speed + MAX_COUNT;
			}
	}


	//***********************************
	// CONVERT RPM
	// 1 tour = 32767
	// Nbre de Tours pendant Te: DELTA_pos/32767
	// Nbre de Tours pendant 1s (Te en ms) : (DELTA_pos/32767)*(1000/Te)
	// Nbre de Tours par minute : : (DELTA_pos/32767)*((60*1000)/Te)

	Speed=(Speed*60*1000)/(32767*TE_ms);
	Speed=Speed+(Speed*10)/100;

	return Speed;
}
//================================================================
//		MAJ indexZ Left
//================================================================
void quadEncoder_CallbackIndexZ()
{
		if (__HAL_TIM_DIRECTION_STATUS(&TimEncoderHandle)==1)
		{
			indexZ--;
		}
		else
		{
			indexZ++;
		}
		__HAL_TIM_SetCounter(&TimEncoderHandle, 0);		// RAZ Counter
		HAL_TIM_Encoder_Start(&TimEncoderHandle,TIM_CHANNEL_1);
		HAL_TIM_Encoder_Start(&TimEncoderHandle,TIM_CHANNEL_2);

		first_index_reached = 1;
}
//================================================================



