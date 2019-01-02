/**
 * @file
 * @brief Generated model file.

 * Date:  2018-11-21 20:53
 * X2C-Version: 910
 */
/* This file is part of X2C. http://www.mechatronic-simulation.org/                                                   */

/* Model: stm32_f446_x2c                                                                                              */
/* Date:  2018-11-21 20:53                                                                                            */

/* X2C-Version: 910                                                                                                   */

#ifndef __X2C_H__
#define __X2C_H__

/**********************************************************************************************************************/
/**     Includes                                                                                                     **/
/**********************************************************************************************************************/
#include "space_vector_INT16.h"
#include "sin_INT16.h"
#include "cos_INT16.h"
#include "Add_FiP16.h"
#include "shift_right_INT16.h"
#include "Constant_FiP16.h"
#include "park_transf_inv_INT16.h"
#include "Sub_FiP16.h"
#include "park_transf_INT16.h"
#include "clarke_inv_INT16.h"
#include "clarke_INT16.h"
#include "pid_INT16.h"
#include "shift_left_INT16.h"
#include "Scope_Main.h"
#include "CommonFcts.h"

/**********************************************************************************************************************/
/**     Defines                                                                                                      **/
/**********************************************************************************************************************/
#define FUNCTIONS SPACE_VECTOR_INT16_FUNCTIONS , \
                  SIN_INT16_FUNCTIONS , \
                  COS_INT16_FUNCTIONS , \
                  ADD_FIP16_FUNCTIONS , \
                  SHIFT_RIGHT_INT16_FUNCTIONS , \
                  CONSTANT_FIP16_FUNCTIONS , \
                  PARK_TRANSF_INV_INT16_FUNCTIONS , \
                  SUB_FIP16_FUNCTIONS , \
                  PARK_TRANSF_INT16_FUNCTIONS , \
                  CLARKE_INV_INT16_FUNCTIONS , \
                  CLARKE_INT16_FUNCTIONS , \
                  PID_INT16_FUNCTIONS , \
                  SHIFT_LEFT_INT16_FUNCTIONS , \
                  SCOPE_MAIN_FUNCTIONS 

#define PARAMETER_TABLE { (uint16)1, &TConstant23 } , \
                        { (uint16)2, &TConstant24 } , \
                        { (uint16)3, &TConstant27 } , \
                        { (uint16)4, &TConstant30 } , \
                        { (uint16)5, &TConstant31 } , \
                        { (uint16)6, &TConstant33 } , \
                        { (uint16)7, &TSub } , \
                        { (uint16)8, &TSub1 } , \
                        { (uint16)9, &TSub2 } , \
                        { (uint16)10, &TSuperBlock1__Add } , \
                        { (uint16)11, &TSuperBlock1__Constant31 } , \
                        { (uint16)12, &TSuperBlock1__shift_right } , \
                        { (uint16)13, &TSuperBlock2__Add } , \
                        { (uint16)14, &TSuperBlock2__Constant31 } , \
                        { (uint16)15, &TSuperBlock2__shift_right } , \
                        { (uint16)16, &TSuperBlock__Add } , \
                        { (uint16)17, &TSuperBlock__Constant31 } , \
                        { (uint16)18, &TSuperBlock__shift_right } , \
                        { (uint16)19, &Tclarke } , \
                        { (uint16)20, &Tclarke_inv } , \
                        { (uint16)21, &Tcos } , \
                        { (uint16)22, &Tpark_transf } , \
                        { (uint16)23, &Tpark_transf_inv } , \
                        { (uint16)24, &Tpid } , \
                        { (uint16)25, &Tpid1 } , \
                        { (uint16)26, &Tpid2 } , \
                        { (uint16)27, &Tshift_left } , \
                        { (uint16)28, &Tshift_left1 } , \
                        { (uint16)29, &Tsin } , \
                        { (uint16)30, &Tspace_vector } , \
                        { (uint16)31, &TScope } , \
                        { (uint16)32, &Inports.Ia } , \
                        { (uint16)33, &Inports.Ib } , \
                        { (uint16)34, &Inports.pot } , \
                        { (uint16)35, &Inports.pulse } , \
                        { (uint16)36, &Inports.speed } , \
                        { (uint16)37, &Inports.theta_elec } , \
                        { (uint16)38, &Outports.pduty_3 } , \
                        { (uint16)39, &Outports.pIQ_mes } , \
                        { (uint16)40, &Outports.pduty_2 } , \
                        { (uint16)41, &Outports.pduty_1 } 

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

#define X2C_UPDATE_20_DIVIDER 20

/**********************************************************************************************************************/
/**     Prototypes                                                                                                   **/
/**********************************************************************************************************************/
void X2C_Init(void);
void X2C_Update(void);
void X2C_Update_1(void);
void X2C_Update_20(void);


#endif
