/*
 * config.h
 *
 *  Created on: 30 juin 2016
 *      Author: kerhoas
 */

#ifndef INC_CONFIG_H_
#define INC_CONFIG_H_

#include <math.h>


#define USE_MOTOR	0


#define	USE_USART_STLINK 1
#define USART2_BAUDRATE			115200
#define CAN_BAUDRATE	500000

//========================================================
//					LIAISON I2C
//========================================================
#define I2C1_CLOCKSPEED			60000
#define I2C2_CLOCKSPEED			60000

//========================================================
//				PWM (TIMER 1)
//========================================================

#define	N_BITS_COUNT			11
#define PWM_COUNT_PERIOD		(unsigned int) pow(2,N_BITS_COUNT)
#define ADJUST 				(1100/1000)

//=========================================================
//				TICK TIMER
//=========================================================

#define TICKTIMER_PERIOD_US		50 //10

//=========================================================
//				PID
//=========================================================


#define FTBO_CURRENT		1
#define FTBF_CURRENT		0

#define FTBO_SPEED				1
#define FTBF_SPEED				0
#define PID_SPEED_KP_FLOAT	0.5
#define PID_SPEED_KI_FLOAT	0.5//0.5 //(0.002/(0.1*0.015))


#define  PID_SPEED_KP		(int32_t)(0.5*(1<<31))
#define  PID_SPEED_KI		(int32_t)((1<<31)*(0.002/(0.1*0.030)))
#define  PID_SPEED_KD		0


#define CURRENT_MES_SHIFT	20//21

#define IQ_REF_MIN			(-1000<<20)
#define IQ_REF_MAX			(1000<<20)

#define IQ_CDE_MIN			-0x7FFFFFFF
#define IQ_CDE_MAX			 0x7FFFFFFF

#define PULSE_AMP			1000
#define USE_PULSE			1



//============================================================
//				MOTOR CARACTERISTICS
//============================================================

#define POLE_PAIR		4
#define ENC_RESOL		2000
#define OFFSET_POS	(int)(0.75*(ENC_RESOL*4)/POLE_PAIR)
#define GAIN_POS	(int)(pow(2,31)*POLR_PAIR/(4*ENC_RESOL))


#endif /* INC_CONFIG_H_ */
