/*
 * quadEncoder.h
 *
 *  Created on: 30 juin 2016
 *      Author: kerhoas
 */

#ifndef INC_QUADENCODER_H_
#define INC_QUADENCODER_H_



#include "main.h"

void quadEncoder_Init(void);
uint16_t quadEncoder_GetPos16(void);
int32_t quadEncoder_GetPos32(void);
int16_t quadEncoder_GetSpeed(void);
void quadEncoder_CallbackIndexZ(void);
void quadEncoder_PosCalc(int*);


#endif /* INC_QUADENCODER_H_ */




