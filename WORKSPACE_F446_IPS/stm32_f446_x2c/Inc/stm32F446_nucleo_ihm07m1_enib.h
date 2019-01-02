/*
 * stm32F401_nucleo_ihm07m1_enib.h
 *
 *  Created on: 6 mai 2016
 *      Author: kerhoas
 */

#ifndef INC_STM32F401_NUCLEO_IHM07M1_ENIB_H_
#define INC_STM32F401_NUCLEO_IHM07M1_ENIB_H_

#include "stm32f4xx_hal.h"
#include "main.h"
//#include "X-NUCLEO-IHM07M1.h"


extern TIM_HandleTypeDef    TimHandle_period;

#define HF_TIMx               htim1				// TIMER PWM
#define LF_TIMx               TimHandle_period	// TIMER TickTimer (Te Current Loop)
#define HALL_ENCODER_TIMx     htim2
#define ADCx                  hadc1
#define DACx                  htim3
#define UART                  huart2

#define GPIO_PORT_1           GPIOC
#define GPIO_CH1              GPIO_PIN_10
#define GPIO_PORT_2           GPIOC
#define GPIO_CH2              GPIO_PIN_11
#define GPIO_PORT_3           GPIOC
#define GPIO_CH3              GPIO_PIN_12
#define GPIO_SET              GPIO_PIN_SET
#define GPIO_RESET            GPIO_PIN_RESET

#define ADC_CH_1              ADC_CHANNEL_11  /*CURRENT*/
#define ADC_CH_2              ADC_CHANNEL_9   /*SPEED*/
#define ADC_CH_3              ADC_CHANNEL_1   /*VBUS*/
#define ADC_CH_4              ADC_CHANNEL_12  /*TEMP*/
#define ADC_Bemf_CH1          ADC_CHANNEL_13  /*BEMF1*/
#define ADC_Bemf_CH2          ADC_CHANNEL_8   /*BEMF2*/
#define ADC_Bemf_CH3          ADC_CHANNEL_7   /*BEMF3*/

#define ADC_CH_1_ST           ADC_SAMPLETIME_3CYCLES    /*CURRENT sampling time */
#define ADC_CH_2_ST           ADC_SAMPLETIME_84CYCLES /*SPEED sampling time*/
#define ADC_CH_3_ST           ADC_SAMPLETIME_84CYCLES /*VBUS sampling time*/
#define ADC_CH_4_ST           ADC_SAMPLETIME_84CYCLES /*TEMP sampling time*/
#define ADC_Bemf_CH1_ST       ADC_SAMPLETIME_28CYCLES  /*BEMF1 sampling time*/
#define ADC_Bemf_CH2_ST       ADC_SAMPLETIME_28CYCLES  /*BEMF2 sampling time*/
#define ADC_Bemf_CH3_ST       ADC_SAMPLETIME_28CYCLES  /*BEMF3 sampling time*/

#define HF_TIMx_CH1           TIM_CHANNEL_1
#define HF_TIMx_CH2           TIM_CHANNEL_2
#define HF_TIMx_CH3           TIM_CHANNEL_3
#define HF_TIMx_CCR1          CCR1            /*Channel 1*/
#define HF_TIMx_CCR2          CCR2            /*Channel 2*/
#define HF_TIMx_CCR3          CCR3            /*Channel 3*/

#define DAC_ENABLE            0               /*!< Enable (1) the DAC peripheral */

#define GPIO_PORT_ZCR         GPIOC           /*!<  GPIO port name for zero crossing detection */
#define GPIO_CH_ZCR           GPIO_PIN_7      /*!<  GPIO pin name for zero crossing detection */
#define GPIO_PORT_COMM        GPIOC           /*!<  GPIO port name for 6Step commutation */
#define GPIO_CH_COMM          GPIO_PIN_4      /*!<  GPIO pin name for 6Step commutation */

#define STARTM_CMD             0     /*!<  Start Motor command received */
#define STOPMT_CMD             1     /*!<  Stop Motor command received */
#define SETSPD_CMD             2     /*!<  Set the new speed value command received */
#define GETSPD_CMD             3     /*!<  Get Mechanical Motor Speed command received */
#define INIREF_CMD             4     /*!<  Set the new STARUP_CURRENT_REFERENCE value command received */
#define POLESP_CMD             5     /*!<  Set the Pole Pairs value command received */
#define ACCELE_CMD             6     /*!<  Set the Accelleration for Start-up of the motor command received */
#define KP_PRM_CMD             7    /*!<  Set the KP PI param command received */
#define KI_PRM_CMD             8    /*!<  Set the KI PI param command received */
#define POTENZ_CMD             9    /*!<  Enable Potentiometer command received */
#define HELP_CMD               10    /*!<  Help command received */
#define STATUS_CMD             11    /*!<  Get the Status of the system command received */
#define DIRECT_CMD             12    /*!<  Get the motor direction */

void MC_FOC_Nucleo_Init();
void MC_Fast_Task(void);
void MC_Slow_Task(void);
uint16_t MC_FOC_Get_potentiometre(void);
void MC_FOC_Start_PWM_driving(void);
void MC_FOC_HF_TIMx_SetDutyCycle_CH1(uint16_t CCR_value);
void MC_FOC_HF_TIMx_SetDutyCycle_CH2(uint16_t CCR_value);
void MC_FOC_HF_TIMx_SetDutyCycle_CH3(uint16_t CCR_value);
void  MC_FOC_EnableInputs();
void MC_FOC_ADC_Channel(uint32_t adc_ch);

#endif /* INC_STM32F401_NUCLEO_IHM07M1_ENIB_H_ */
