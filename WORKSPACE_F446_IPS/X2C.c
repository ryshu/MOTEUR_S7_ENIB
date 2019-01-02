/* This file is part of X2C. http://www.mechatronic-simulation.org/                                                   */

/* Model: stm32_f446_x2c                                                                                              */
/* Date:  2018-11-21 18:27                                                                                            */

/* X2C-Version: 910                                                                                                   */

#include "X2C.h"


/*                                                       Inports                                                      */
/*--------------------------------------------------------------------------------------------------------------------*/
TInports Inports;

/*                                                      Outports                                                      */
/*--------------------------------------------------------------------------------------------------------------------*/
TOutports Outports;

/**********************************************************************************************************************/
/**                                              Global Variables Block                                              **/
/**********************************************************************************************************************/
CONSTANT_FIP16                TConstant31;
CONSTANT_FIP16                TConstant32;
CONSTANT_FIP16                TConstant29;
SUB_FIP16                     TSub;
CONSTANT_FIP16                TConstant23;
CONSTANT_FIP16                TConstant24;
CONSTANT_FIP16                TConstant30;
CONSTANT_FIP16                TConstant33;
ADD_FIP16                     TAdd;
SHIFT_RIGHT_INT16             Tshift_right;
SHIFT_LEFT_INT16              Tshift_left;
CONSTANT_FIP16                TConstant27;
CONSTANT_FIP16                TConstant26;
SCOPE_MAIN                    TScope;

/* Block function table                                                                                               */
#define END_BLOCKFUNCTIONS { (uint16)0, (void (*)(void*))0, (void (*)(void*))0, \
    (uint8 (*)(void*, uint8[]))0, (uint8 (*)(void*, uint8[], uint8))0, (void* (*)(void*, uint16))0 }

const tBlockFunctions blockFunctionTable[] = {
    FUNCTIONS,
    END_BLOCKFUNCTIONS
};

/* Parameter identifier table                                                                                         */
#define END_PARAMETERTABLE { (uint16)0, (void*)0 }

const tParameterTable parameterIdTable[] = {
    PARAMETER_TABLE,
    END_PARAMETERTABLE
};

/**********************************************************************************************************************/
/**                                                  Initialization                                                  **/
/**********************************************************************************************************************/
void X2C_Init()
{
    /******************************************************************************************************************/
    /**                                          Initialize Block Parameters                                         **/
    /******************************************************************************************************************/

    /* Block Constant31                                                                                               */
    /* Value = 0.03125                                                                                                */
    TConstant31.K = 1024;

    /* Block Constant32                                                                                               */
    /* Value = 0.0625                                                                                                 */
    TConstant32.K = 2048;

    /* Block Constant29                                                                                               */
    /* Value = 0.0312                                                                                                 */
    TConstant29.K = 1022;

    /* Block Sub                                                                                                      */

    /* Block Constant23                                                                                               */
    /* Value = 0.04                                                                                                   */
    TConstant23.K = 1311;

    /* Block Constant24                                                                                               */
    /* Value = 0.1                                                                                                    */
    TConstant24.K = 3277;

    /* Block Constant30                                                                                               */
    /* Value = 0.1                                                                                                    */
    TConstant30.K = 3277;

    /* Block Constant33                                                                                               */
    /* Value = 0.1                                                                                                    */
    TConstant33.K = 3277;

    /* Block Add                                                                                                      */

    /* Block shift_right                                                                                              */
    /* shift_Val = 5.0                                                                                                */
    Tshift_right.shift_V = 5;

    /* Block shift_left                                                                                               */
    /* shift_Val = 4.0                                                                                                */
    Tshift_left.shift_V = 4;

    /* Block Constant27                                                                                               */
    /* Value = 0.044                                                                                                  */
    TConstant27.K = 1442;

    /* Block Constant26                                                                                               */
    /* Value = 0.0312                                                                                                 */
    TConstant26.K = 1022;


    /******************************************************************************************************************/
    /**                                               Link Block Inputs                                              **/
    /******************************************************************************************************************/

    /* Block Constant31                                                                                               */

    /* Block Constant32                                                                                               */

    /* Block Constant29                                                                                               */

    /* Block Sub                                                                                                      */
    TSub.Plus                        = &(Inports.pot);
    TSub.Minus                       = &TConstant32.Out;

    /* Block Constant23                                                                                               */

    /* Block Constant24                                                                                               */

    /* Block Constant30                                                                                               */

    /* Block Constant33                                                                                               */

    /* Block Add                                                                                                      */
    TAdd.In1                         = &Tshift_right.out;
    TAdd.In2                         = &TConstant31.Out;

    /* Block shift_right                                                                                              */
    Tshift_right.in                  = &Tshift_left.out;

    /* Block shift_left                                                                                               */
    Tshift_left.in                   = &TSub.Out;

    /* Block Constant27                                                                                               */

    /* Block Constant26                                                                                               */

    /******************************************************************************************************************/
    /**                                                 Link Outports                                                **/
    /******************************************************************************************************************/
    Outports.pduty_3                  = &TConstant29.Out;
    Outports.pIQ_mes                  = &TConstant33.Out;
    Outports.pduty_2                  = &TConstant26.Out;
    Outports.pduty_1                  = &TAdd.Out;

    /******************************************************************************************************************/
    /**                                           Run Block Init Functions                                           **/
    /******************************************************************************************************************/
    Constant_FiP16_Init(&TConstant31);
    Constant_FiP16_Init(&TConstant32);
    Constant_FiP16_Init(&TConstant29);
    Sub_FiP16_Init(&TSub);
    Constant_FiP16_Init(&TConstant23);
    Constant_FiP16_Init(&TConstant24);
    Constant_FiP16_Init(&TConstant30);
    Constant_FiP16_Init(&TConstant33);
    Add_FiP16_Init(&TAdd);
    shift_right_INT16_Init(&Tshift_right);
    shift_left_INT16_Init(&Tshift_left);
    Constant_FiP16_Init(&TConstant27);
    Constant_FiP16_Init(&TConstant26);
    Scope_Main_Init(&TScope);
}

/**********************************************************************************************************************/
/**                                            Run Block Update Functions                                            **/
/**********************************************************************************************************************/
void X2C_Update(void)
{
    X2C_Update_1();

}

/* X2C_Update for blocks with 1*Ts                                                                                    */
void X2C_Update_1(void)
{
    Sub_FiP16_Update(&TSub);
    shift_left_INT16_Update(&Tshift_left);
    shift_right_INT16_Update(&Tshift_right);
    Add_FiP16_Update(&TAdd);
    Scope_Main_Update(&TScope);
}

