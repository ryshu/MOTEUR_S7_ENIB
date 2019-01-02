/*
 * motorControl.h
 *
 *  Created on: 29 nov. 2016
 *      Author: kerhoas
 */

#ifndef INC_MOTORCONTROL_H_
#define INC_MOTORCONTROL_H_

#include "main.h"


void calculateSpaceVector_q31(q31_t alpha, q31_t beta, q31_t* T );
void pwmSetDutyCycle(uint16_t duty_1,uint16_t duty_2,uint16_t duty_3);

#endif /* INC_MOTORCONTROL_H_ */
