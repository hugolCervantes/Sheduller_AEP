/*
 * OS_Init.c
 *
 *  Created on: Nov 17, 2015
 *      Author: Isa
 */

#include "OS_Init.h"
#include "stdtypedef.h"
#include "STM_Timer.h"
/*
T_UBYTE rub_tickFlag;

void Interrupt_Flag(void)
{ 
	if (STM.CH[0].CIR.B.CIF)
	{
		rub_tickFlag = 1;
		STM.CH[0].CIR.B.CIF = 1;	//Clear interrupt flag 
		STM.CNT.R = 0; 				//Reset counter
	}
}
*/
