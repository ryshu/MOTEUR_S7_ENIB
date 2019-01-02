/* This file is part of X2C. http://www.mechatronic-simulation.org/                                                   */

/* Model: stm32_f446_x2c                                                                                              */
/* Date:  2018-11-21 20:53                                                                                            */

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
SPACE_VECTOR_INT16            Tspace_vector;
SIN_INT16                     Tsin;
COS_INT16                     Tcos;
ADD_FIP16                     TSuperBlock__Add;
SHIFT_RIGHT_INT16             TSuperBlock__shift_right;
CONSTANT_FIP16                TSuperBlock__Constant31;
SHIFT_RIGHT_INT16             TSuperBlock1__shift_right;
CONSTANT_FIP16                TSuperBlock1__Constant31;
ADD_FIP16                     TSuperBlock1__Add;
PARK_TRANSF_INV_INT16         Tpark_transf_inv;
SUB_FIP16                     TSub;
SUB_FIP16                     TSub1;
CONSTANT_FIP16                TConstant30;
PARK_TRANSF_INT16             Tpark_transf;
CLARKE_INV_INT16              Tclarke_inv;
CLARKE_INT16                  Tclarke;
CONSTANT_FIP16                TConstant23;
SUB_FIP16                     TSub2;
CONSTANT_FIP16                TConstant24;
CONSTANT_FIP16                TSuperBlock2__Constant31;
SHIFT_RIGHT_INT16             TSuperBlock2__shift_right;
ADD_FIP16                     TSuperBlock2__Add;
PID_INT16                     Tpid;
CONSTANT_FIP16                TConstant31;
SHIFT_LEFT_INT16              Tshift_left;
SHIFT_LEFT_INT16              Tshift_left1;
CONSTANT_FIP16                TConstant33;
PID_INT16                     Tpid1;
PID_INT16                     Tpid2;
CONSTANT_FIP16                TConstant27;
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

    /* Block space_vector                                                                                             */

    /* Block sin                                                                                                      */

    /* Block cos                                                                                                      */

    /* Block SuperBlock__Add                                                                                          */

    /* Block SuperBlock__shift_right                                                                                  */
    /* shift_Val = 5.0                                                                                                */
    TSuperBlock__shift_right.shift_V = 5;

    /* Block SuperBlock__Constant31                                                                                   */
    /* Value = 0.03125                                                                                                */
    TSuperBlock__Constant31.K = 1024;

    /* Block SuperBlock1__shift_right                                                                                 */
    /* shift_Val = 5.0                                                                                                */
    TSuperBlock1__shift_right.shift_V = 5;

    /* Block SuperBlock1__Constant31                                                                                  */
    /* Value = 0.03125                                                                                                */
    TSuperBlock1__Constant31.K = 1024;

    /* Block SuperBlock1__Add                                                                                         */

    /* Block park_transf_inv                                                                                          */

    /* Block Sub                                                                                                      */

    /* Block Sub1                                                                                                     */

    /* Block Constant30                                                                                               */
    /* Value = 0.0                                                                                                    */
    TConstant30.K = 0;

    /* Block park_transf                                                                                              */

    /* Block clarke_inv                                                                                               */

    /* Block clarke                                                                                                   */

    /* Block Constant23                                                                                               */
    /* Value = 0.03                                                                                                   */
    TConstant23.K = 983;

    /* Block Sub2                                                                                                     */

    /* Block Constant24                                                                                               */
    /* Value = 0.1                                                                                                    */
    TConstant24.K = 3277;

    /* Block SuperBlock2__Constant31                                                                                  */
    /* Value = 0.03125                                                                                                */
    TSuperBlock2__Constant31.K = 1024;

    /* Block SuperBlock2__shift_right                                                                                 */
    /* shift_Val = 5.0                                                                                                */
    TSuperBlock2__shift_right.shift_V = 5;

    /* Block SuperBlock2__Add                                                                                         */

    /* Block pid                                                                                                      */
    /* Kp = 9830.0                                                                                                    */
    /* Ki = 125.0                                                                                                     */
    /* Kd = 0.0                                                                                                       */
    /* ts_fact = 1.0                                                                                                  */
    Tpid.KP = 9830;
    Tpid.KI = 125;
    Tpid.KD = 0;
    Tpid.i_old = 0;
    Tpid.d_old = 0;

    /* Block Constant31                                                                                               */
    /* Value = 0.1                                                                                                    */
    TConstant31.K = 3277;

    /* Block shift_left                                                                                               */
    /* shift_Val = 4.0                                                                                                */
    Tshift_left.shift_V = 4;

    /* Block shift_left1                                                                                              */
    /* shift_Val = 4.0                                                                                                */
    Tshift_left1.shift_V = 4;

    /* Block Constant33                                                                                               */
    /* Value = 0.1                                                                                                    */
    TConstant33.K = 3277;

    /* Block pid1                                                                                                     */
    /* Kp = 16384.0                                                                                                   */
    /* Ki = 0.0                                                                                                       */
    /* Kd = 0.0                                                                                                       */
    /* ts_fact = 1.0                                                                                                  */
    Tpid1.KP = 16384;
    Tpid1.KI = 0;
    Tpid1.KD = 0;
    Tpid1.i_old = 0;
    Tpid1.d_old = 0;

    /* Block pid2                                                                                                     */
    /* Kp = 16384.0                                                                                                   */
    /* Ki = 0.0                                                                                                       */
    /* Kd = 0.0                                                                                                       */
    /* ts_fact = 1.0                                                                                                  */
    Tpid2.KP = 16384;
    Tpid2.KI = 0;
    Tpid2.KD = 0;
    Tpid2.i_old = 0;
    Tpid2.d_old = 0;

    /* Block Constant27                                                                                               */
    /* Value = 0.125                                                                                                  */
    TConstant27.K = 4096;


    /******************************************************************************************************************/
    /**                                               Link Block Inputs                                              **/
    /******************************************************************************************************************/

    /* Block space_vector                                                                                             */
    Tspace_vector.a                  = &Tclarke_inv.a;
    Tspace_vector.b                  = &Tclarke_inv.b;
    Tspace_vector.c                  = &Tclarke_inv.c;

    /* Block sin                                                                                                      */
    Tsin.theta                       = &(Inports.theta_elec);

    /* Block cos                                                                                                      */
    Tcos.theta                       = &(Inports.theta_elec);

    /* Block SuperBlock__Add                                                                                          */
    TSuperBlock__Add.In1             = &TSuperBlock__shift_right.out;
    TSuperBlock__Add.In2             = &TSuperBlock__Constant31.Out;

    /* Block SuperBlock__shift_right                                                                                  */
    TSuperBlock__shift_right.in      = &Tspace_vector.duty_2;

    /* Block SuperBlock__Constant31                                                                                   */

    /* Block SuperBlock1__shift_right                                                                                 */
    TSuperBlock1__shift_right.in     = &Tspace_vector.duty_3;

    /* Block SuperBlock1__Constant31                                                                                  */

    /* Block SuperBlock1__Add                                                                                         */
    TSuperBlock1__Add.In1            = &TSuperBlock1__shift_right.out;
    TSuperBlock1__Add.In2            = &TSuperBlock1__Constant31.Out;

    /* Block park_transf_inv                                                                                          */
    Tpark_transf_inv.d               = &Tpid1.Out;
    Tpark_transf_inv.q               = &Tpid2.Out;
    Tpark_transf_inv.sin_theta       = &Tsin.sin_theta;
    Tpark_transf_inv.cos_theta       = &Tcos.cos_theta;

    /* Block Sub                                                                                                      */
    TSub.Plus                        = &TConstant30.Out;
    TSub.Minus                       = &Tpark_transf.d;

    /* Block Sub1                                                                                                     */
    TSub1.Plus                       = &Tpid.Out;
    TSub1.Minus                      = &Tpark_transf.q;

    /* Block Constant30                                                                                               */

    /* Block park_transf                                                                                              */
    Tpark_transf.alpha               = &Tclarke.alpha;
    Tpark_transf.beta                = &Tclarke.beta;
    Tpark_transf.sin_theta           = &Tsin.sin_theta;
    Tpark_transf.cos_theta           = &Tcos.cos_theta;

    /* Block clarke_inv                                                                                               */
    Tclarke_inv.alpha                = &Tpark_transf_inv.alpha;
    Tclarke_inv.beta                 = &Tpark_transf_inv.beta;

    /* Block clarke                                                                                                   */
    Tclarke.a                        = &(Inports.Ia);
    Tclarke.b                        = &(Inports.Ib);

    /* Block Constant23                                                                                               */

    /* Block Sub2                                                                                                     */
    TSub2.Plus                       = &Tshift_left.out;
    TSub2.Minus                      = &Tshift_left1.out;

    /* Block Constant24                                                                                               */

    /* Block SuperBlock2__Constant31                                                                                  */

    /* Block SuperBlock2__shift_right                                                                                 */
    TSuperBlock2__shift_right.in     = &Tspace_vector.duty_1;

    /* Block SuperBlock2__Add                                                                                         */
    TSuperBlock2__Add.In1            = &TSuperBlock2__shift_right.out;
    TSuperBlock2__Add.In2            = &TSuperBlock2__Constant31.Out;

    /* Block pid                                                                                                      */
    Tpid.In                          = &TSub2.Out;

    /* Block Constant31                                                                                               */

    /* Block shift_left                                                                                               */
    Tshift_left.in                   = &(Inports.pulse);

    /* Block shift_left1                                                                                              */
    Tshift_left1.in                  = &(Inports.speed);

    /* Block Constant33                                                                                               */

    /* Block pid1                                                                                                     */
    Tpid1.In                         = &TSub.Out;

    /* Block pid2                                                                                                     */
    Tpid2.In                         = &TSub1.Out;

    /* Block Constant27                                                                                               */

    /******************************************************************************************************************/
    /**                                                 Link Outports                                                **/
    /******************************************************************************************************************/
    Outports.pduty_3                  = &TSuperBlock1__Add.Out;
    Outports.pIQ_mes                  = &TConstant33.Out;
    Outports.pduty_2                  = &TSuperBlock__Add.Out;
    Outports.pduty_1                  = &TSuperBlock2__Add.Out;

    /******************************************************************************************************************/
    /**                                           Run Block Init Functions                                           **/
    /******************************************************************************************************************/
    space_vector_INT16_Init(&Tspace_vector);
    sin_INT16_Init(&Tsin);
    cos_INT16_Init(&Tcos);
    Add_FiP16_Init(&TSuperBlock__Add);
    shift_right_INT16_Init(&TSuperBlock__shift_right);
    Constant_FiP16_Init(&TSuperBlock__Constant31);
    shift_right_INT16_Init(&TSuperBlock1__shift_right);
    Constant_FiP16_Init(&TSuperBlock1__Constant31);
    Add_FiP16_Init(&TSuperBlock1__Add);
    park_transf_inv_INT16_Init(&Tpark_transf_inv);
    Sub_FiP16_Init(&TSub);
    Sub_FiP16_Init(&TSub1);
    Constant_FiP16_Init(&TConstant30);
    park_transf_INT16_Init(&Tpark_transf);
    clarke_inv_INT16_Init(&Tclarke_inv);
    clarke_INT16_Init(&Tclarke);
    Constant_FiP16_Init(&TConstant23);
    Sub_FiP16_Init(&TSub2);
    Constant_FiP16_Init(&TConstant24);
    Constant_FiP16_Init(&TSuperBlock2__Constant31);
    shift_right_INT16_Init(&TSuperBlock2__shift_right);
    Add_FiP16_Init(&TSuperBlock2__Add);
    pid_INT16_Init(&Tpid);
    Constant_FiP16_Init(&TConstant31);
    shift_left_INT16_Init(&Tshift_left);
    shift_left_INT16_Init(&Tshift_left1);
    Constant_FiP16_Init(&TConstant33);
    pid_INT16_Init(&Tpid1);
    pid_INT16_Init(&Tpid2);
    Constant_FiP16_Init(&TConstant27);
    Scope_Main_Init(&TScope);
}

/**********************************************************************************************************************/
/**                                            Run Block Update Functions                                            **/
/**********************************************************************************************************************/
static uint16 cnt_20 = X2C_UPDATE_20_DIVIDER - 1;
void X2C_Update(void)
{
    X2C_Update_1();
    if (cnt_20 == 0)
    {
        cnt_20 = X2C_UPDATE_20_DIVIDER;
        X2C_Update_20();
    }

    cnt_20--;
}

/* X2C_Update for blocks with 1*Ts                                                                                    */
void X2C_Update_1(void)
{
    shift_left_INT16_Update(&Tshift_left);
    Sub_FiP16_Update(&TSub2);
    clarke_INT16_Update(&Tclarke);
    cos_INT16_Update(&Tcos);
    sin_INT16_Update(&Tsin);
    park_transf_INT16_Update(&Tpark_transf);
    pid_INT16_Update(&Tpid);
    Sub_FiP16_Update(&TSub);
    Sub_FiP16_Update(&TSub1);
    pid_INT16_Update(&Tpid1);
    pid_INT16_Update(&Tpid2);
    park_transf_inv_INT16_Update(&Tpark_transf_inv);
    clarke_inv_INT16_Update(&Tclarke_inv);
    space_vector_INT16_Update(&Tspace_vector);
    shift_right_INT16_Update(&TSuperBlock1__shift_right);
    shift_right_INT16_Update(&TSuperBlock2__shift_right);
    shift_right_INT16_Update(&TSuperBlock__shift_right);
    Add_FiP16_Update(&TSuperBlock1__Add);
    Add_FiP16_Update(&TSuperBlock2__Add);
    Add_FiP16_Update(&TSuperBlock__Add);
    Scope_Main_Update(&TScope);
}

/* X2C_Update for blocks with 20*Ts                                                                                   */
void X2C_Update_20(void)
{
    shift_left_INT16_Update(&Tshift_left1);
}

