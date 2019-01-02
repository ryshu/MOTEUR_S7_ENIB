#include "stm32F446_nucleo_ihm07m1_enib.h"
#include "arm_common_tables.h"
#include "arm_math.h"
#include "motorControl.h"

#define OFFSET_THETA	800//850

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef    TimHandle_period;
extern 	uint32_t pot;
extern int first_index_reached;
extern int16_t Ia_bias, Ib_bias;
extern int pulse;

uint16_t 	quadPos, theta_elec;
q31_t theta_elec_ext;
uint16_t pwm_duty_1,  pwm_duty_2,  pwm_duty_3;
q31_t id_mes, id_ref, id_err, id_cde;
q31_t iq_mes, iq_ref, iq_err, iq_cde;
uint16_t Ia_mes, Ib_mes, Ic_mes;
uint16_t	potentiometre;
int32_t	Ia_mes_ext, Ib_mes_ext;
q31_t alpha, beta, sinVal, cosVal;


extern int16_t speed_mes;
int32_t speed_mes_q31;
int32_t speed_err;
int32_t speed_cde;
int32_t speed_ref;

int i; // Index Mesures
float speed_cde_f, ui_f, up_f, speed_cde_f, speed_err_f, speed_ref_f, speed_mes_f;

//============================================================================
// 		DEMARRAGE : recherche du premier index pour position initiale
//============================================================================
void findFirstIndex()
{
	q31_t T[3];
	q31_t 	iq_cde;
	int64_t T_ext[3];
	uint16_t pwm_duty_1,  pwm_duty_2,  pwm_duty_3;
	static uint32_t theta_ramp=0;

	//-------------------------------------------------------
	// 			RAMP GENERATOR
	//-------------------------------------------------------
	theta_ramp = theta_ramp+ ( 0x1 << 21);//( 0x1 << 21); //( 0x1 << 21); //(pot >> 2);//( 0x1 << 16);
	if (theta_ramp >= 0x7FFFFFFF)
	{theta_ramp = 0;}

	cosVal=arm_cos_q31((q31_t)theta_ramp);
	sinVal=arm_sin_q31((q31_t)theta_ramp);

	iq_cde=0x20000000;
	arm_inv_park_q31(0,iq_cde ,&alpha,&beta,sinVal,cosVal);
	calculateSpaceVector_q31(alpha, beta, T );
	//-------------------------------------------------------
	// 			T_ext <- T + 1
	//-------------------------------------------------------
	T_ext[0]=(int64_t)T[0]+0x7FFFFFFF;
	T_ext[1]=(int64_t)T[1]+0x7FFFFFFF;
	T_ext[2]=(int64_t)T[2]+0x7FFFFFFF;
	//-------------------------------------------------------
	// 			CONVERT q31_t [0 2[ --> [0 2^N
	//-------------------------------------------------------
	pwm_duty_1=(uint16_t)((uint64_t)(T_ext[0]>>(33-(N_BITS_COUNT+1)))&(PWM_COUNT_PERIOD-1)); // intervalle [0 2^N]
	pwm_duty_2=(uint16_t)((uint64_t)(T_ext[1]>>(33-(N_BITS_COUNT+1)))&(PWM_COUNT_PERIOD-1)); // intervalle [0 1024]
	pwm_duty_3=(uint16_t)((uint64_t)(T_ext[2]>>(33-(N_BITS_COUNT+1)))&(PWM_COUNT_PERIOD-1)); // intervalle [0 1024]
	//-------------------------------------------------------
	// 			PWM Set DUTY CYCLE
	//-------------------------------------------------------
	pwmSetDutyCycle(pwm_duty_1,pwm_duty_2,pwm_duty_3);
}

//============================================================================
 void MC_FOC_Nucleo_Init()
  {
    TIM_ClearInputConfigTypeDef sClearInputConfig;

    sClearInputConfig.ClearInputState = 1;
    sClearInputConfig.ClearInputSource = TIM_CLEARINPUTSOURCE_ETR;
    sClearInputConfig.ClearInputPolarity = TIM_CLEARINPUTPOLARITY_NONINVERTED;
    sClearInputConfig.ClearInputPrescaler = TIM_CLEARINPUTPRESCALER_DIV1;
    sClearInputConfig.ClearInputFilter = 0;
    HAL_TIM_ConfigOCrefClear(&htim1, &sClearInputConfig, TIM_CHANNEL_1);
    HAL_TIM_ConfigOCrefClear(&htim1, &sClearInputConfig, TIM_CHANNEL_2);
    HAL_TIM_ConfigOCrefClear(&htim1, &sClearInputConfig,TIM_CHANNEL_3);

    __HAL_FREEZE_TIM1_DBGMCU();  				// Stop TIM during Breakpoint
    __HAL_TIM_ENABLE_IT(&htim1, TIM_IT_BREAK); 	// Enable the TIM Break interrupt
  }
//============================================================================
void MC_FOC_Start_PWM_driving()
{
	  HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
	  HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
	  HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_3);
}
//============================================================================
void  MC_FOC_EnableInputs()
{
	 HAL_GPIO_WritePin(GPIOC,GPIO_PIN_10,GPIO_PIN_SET);   	//EN1 ENABLE
	 HAL_GPIO_WritePin(GPIOC,GPIO_PIN_11,GPIO_PIN_SET);  	//EN2 DISABLE
	 HAL_GPIO_WritePin(GPIOC,GPIO_PIN_12,GPIO_PIN_SET);    	//EN3 ENABLE
}
//============================================================================


