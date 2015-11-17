
//Header for timer
#include "STM_Timer.h"


void Init_STM()
{
	STM.CNT.R = 0; //Count init in 0
	STM.CH[TM_1MS].CMP.R = 0xFA00; //1msec
	STM.CH[TM_1MS].CCR.B.CEN = 1; //activate comparator
	STM.CR.B.FRZ = 1;//0: timer runs in debug mode
	STM.CR.B.CPS = 0; //prescaler
	STM.CR.B.TEN = 1;//activate timer
	INTC.CPR.R = 0; //activate interrupts

}

void Restart_STM(T_UBYTE lub_channel)
{
	STM.CNT.R = 0; 							//Init in 0
	STM.CH[lub_channel].CIR.B.CIF = 1;		//Clean flag
}

T_UBYTE Flag_STM(T_UBYTE lub_channel)
{
	return STM.CH[lub_channel].CIR.B.CIF;
}
