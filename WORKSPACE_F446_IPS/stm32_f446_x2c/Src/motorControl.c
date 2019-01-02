/*
 * motorControl.c
 *
 *  Created on: 29 nov. 2016
 *      Author: kerhoas
 */
#include "motorControl.h"
#include "arm_common_tables.h"
#include "arm_math.h"


//============================================================================
//	SVGen DQ --> cf ftp://ftp.ti.com/pub/dml/DMLrequest/Christy_FTP-10-30-12/controlSUITE/libs/app_libs/motor_control/math_blocks/v2.1/~Docs/svgen_dq.pdf
// https://www.microchip.com/forums/download.axd?file=0;723179
//============================================================================

void calculateSpaceVector_q31(q31_t alpha, q31_t beta, q31_t* T )
{

    q31_t Va,Vb,Vc,t1,t2, interne, zero99, zero5;
    uint32_t Sector = 0;  // Sector is treated as Q0 - independently with global Q
    q31_t product1, product2;

    zero99=0x7FFFFFFF;
    zero5=0x40000000;

      // Inverse clarke transformation
    Va = beta;
    product1 = (q31_t) (((q63_t) (-beta) * (0x40000000)) >> 31);// -beta*0.5
    product2 = (q31_t) (((q63_t) (alpha) * (0x6ED9EBA1)) >> 31); // alpha*0.866
    Vb = __QADD(product1, product2);
    Vc = __QSUB(product1, product2);

      // 60 degree Sector determination
    if (Va> 0)
       Sector = 1;
    if (Vb> 0)
       Sector = Sector + 2;
    if (Vc> 0)
       Sector = Sector + 4;

    Va = beta;
    product1 = (q31_t) (((q63_t) (beta) * (0x40000000)) >> 31);
    product2 = (q31_t) (((q63_t) (alpha) * (0x6ED9EBA1)) >> 31);
    Vb = __QADD(product1, product2);
    Vc = __QSUB(product1, product2);

    if (Sector==0)  // Sector 0: this is special case for (Ualpha,Ubeta) = (0,0)
    {
       T[0] =  0x40000000; // 0.5
       T[1] =  0x40000000;
       T[2] =  0x40000000;
    }
    if (Sector==1)  // Sector 1: t1=Z and t2=Y (abc ---> Tb,Ta,Tc)
    {
       t1 = Vc;
       t2 = Vb;
       arm_sub_q31(&zero99,&t1,&interne,1);
       arm_sub_q31(&interne,&t2,&T[1],1);
       T[1] = T[1]>>1;      			// tbon = (1-t1-t2)/2
       arm_add_q31(&T[1],&t1,&T[0],1);	// taon = tbon+t1
       arm_add_q31(&T[0],&t2,&T[2],1);// tcon = taon+t2
    }
    else if (Sector==2)  // Sector 2: t1=Y and t2=-X (abc ---> Ta,Tc,Tb)
    {
       t1 = Vb;
       t2 = -Va;
       arm_sub_q31(&zero99,&t1,&interne,1);
       arm_sub_q31(&interne,&t2,&T[0],1);
       T[0] = T[0]>>1;      			// taon = (1-t1-t2)/2
       arm_add_q31(&T[0],&t1,&T[2],1);	// tcon = taon+t1
       arm_add_q31(&T[2],&t2,&T[1],1);	// tbon = tcon+t2

    }
    else if (Sector==3)  // Sector 3: t1=-Z and t2=X (abc ---> Ta,Tb,Tc)
    {
       t1 = -Vc;
       t2 = Va;
       arm_sub_q31(&zero99,&t1,&interne,1);
       arm_sub_q31(&interne,&t2,&T[0],1);
       T[0] = T[0]>>1;      			// taon = (1-t1-t2)/2
       arm_add_q31(&T[0],&t1,&T[1],1); // tbon = taon+t1
       arm_add_q31(&T[1],&t2,&T[2],1);// tcon = tbon+t2

    }
    else if (Sector==4)  // Sector 4: t1=-X and t2=Z (abc ---> Tc,Tb,Ta)
    {
       t1 = -Va;
       t2 = Vc;
       arm_sub_q31(&zero99,&t1,&interne,1);
       arm_sub_q31(&interne,&t2,&T[2],1);
       T[2] = T[2]>>1;      			// tcon = (1-t1-t2)/2
       arm_add_q31(&T[2],&t1,&T[1],1);	// tbon = tcon+t1
       arm_add_q31(&T[1],&t2,&T[0],1); // taon = tbon+t2
    }
    else if (Sector==5)  // Sector 5: t1=X and t2=-Y (abc ---> Tb,Tc,Ta)
    {
       t1 = Va;
       t2 = -Vb;
       arm_sub_q31(&zero99,&t1,&interne,1);
       arm_sub_q31(&interne,&t2,&T[1],1);
       T[1]=T[1]>>1;      // tbon = (1-t1-t2)/2
       arm_add_q31(&T[1],&t1,&T[2],1);	// tcon = tbon+t1
       arm_add_q31(&T[2],&t2,&T[0],1);	// taon = tcon+t2
    }
    else if (Sector==6)  // Sector 6: t1=-Y and t2=-Z (abc ---> Tc,Ta,Tb)
    {
       t1 = -Vb;
       t2 = -Vc;
       arm_sub_q31(&zero99,&t1,&interne,1);
       arm_sub_q31(&interne,&t2,&T[2],1);
       T[2] = T[2]>>1;      			// tcon = (1-t1-t2)/2
       arm_add_q31(&T[2],&t1,&T[0],1);// taon = tcon+t1
       arm_add_q31(&T[0],&t2,&T[1],1);// tbon = taon+t2
    }
// Convert the unsigned GLOBAL_Q format (ranged (0,1)) -> signed GLOBAL_Q format (ranged (-1,1))
    arm_sub_q31(&T[0],&zero5,&T[0],1);
    arm_sub_q31(&T[1],&zero5,&T[1],1);
    arm_sub_q31(&T[2],&zero5,&T[2],1);

    T[0] = T[0]<<1;
    T[1] = T[1]<<1;
    T[2] = T[2]<<1;
}

//============================================================================
void pwmSetDutyCycle(uint16_t duty_1,uint16_t duty_2,uint16_t duty_3)
{
	htim1.Instance->CCR1 = duty_1*ADJUST;
	htim1.Instance->CCR2 = duty_2*ADJUST;
	htim1.Instance->CCR3 = duty_3*ADJUST;
}
