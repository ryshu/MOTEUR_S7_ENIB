/**
 * @file
 * @brief Generated model file.

 * Date:  2018-11-21 18:27
 * X2C-Version: 910
 */
/* This file is part of X2C. http://www.mechatronic-simulation.org/                                                   */

/* Model: stm32_f446_x2c                                                                                              */
/* Date:  2018-11-21 18:27                                                                                            */

/* X2C-Version: 910                                                                                                   */

#ifndef __X2C_H__
#define __X2C_H__

/**********************************************************************************************************************/
/**     Includes                                                                                                     **/
/**********************************************************************************************************************/
#include "Constant_FiP16.h"
#include "Sub_FiP16.h"
#include "Add_FiP16.h"
#include "shift_right_INT16.h"
#include "shift_left_INT16.h"
#include "Scope_Main.h"
#include "CommonFcts.h"

/**********************************************************************************************************************/
/**     Defines                                                                                                      **/
/**********************************************************************************************************************/
#define FUNCTIONS CONSTANT_FIP16_FUNCTIONS , \
                  SUB_FIP16_FUNCTIONS , \
                  ADD_FIP16_FUNCTIONS , \
                  SHIFT_RIGHT_INT16_FUNCTIONS , \
                  SHIFT_LEFT_INT16_FUNCTIONS , \
                  SCOPE_MAIN_FUNCTIONS 

#define PARAMETER_TABLE { (uint16)1, &TAdd } , \
                        { (uint16)2, &TConstant23 } , \
                        { (uint16)3, &TConstant24 } , \
                        { (uint16)4, &TConstant26 } , \
                        { (uint16)5, &TConstant27 } , \
                        { (uint16)6, &TConstant29 } , \
                        { (uint16)7, &TConstant30 } , \
                        { (uint16)8, &TConstant31 } , \
                        { (uint16)9, &TConstant32 } , \
                        { (uint16)10, &TConstant33 } , \
                        { (uint16)11, &TSub } , \
                        { (uint16)12, &Tshift_left } , \
                        { (uint16)13, &Tshift_right } , \
                        { (uint16)14, &TScope } , \
                        { (uint16)15, &Inports.Ia } , \
                        { (uint16)16, &Inports.Ib } , \
                        { (uint16)17, &Inports.pot } , \
                        { (uint16)18, &Inports.pulse } , \
                        { (uint16)19, &Inports.speed } , \
                        { (uint16)20, &Inports.theta_elec } , \
                        { (uint16)21, &Outports.pduty_3 } , \
                        { (uint16)22, &Outports.pIQ_mes } , \
                        { (uint16)23, &Outports.pduty_2 } , \
                        { (uint16)24, &Outports.pduty_1 } 

/**********************************************************************************************************************/
/**     Typdefs                                                                                                      **/
/**********************************************************************************************************************/

/* Inport structure                                                                                                   */
typedef struct 
{
    int16 theta_elec;
    int16 speed;
    int16 pot;
    int16 Ia;
    int16 Ib;
    int16 pulse;
} TInports;

/* Outport structure                                                                                                  */
typedef struct 
{
    int16* pduty_3;
    int16* pIQ_mes;
    int16* pduty_2;
    int16* pduty_1;
} TOutports;

/**********************************************************************************************************************/
/**     Externals                                                                                                    **/
/**********************************************************************************************************************/
extern TInports Inports;
extern TOutports Outports;
extern const tBlockFunctions blockFunctionTable[];
extern const tParameterTable parameterIdTable[];


/**********************************************************************************************************************/
/**     Prototypes                                                                                                   **/
/**********************************************************************************************************************/
void X2C_Init(void);
void X2C_Update(void);
void X2C_Update_1(void);


#endif
