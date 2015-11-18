/*
 * Init_all_system.c
 *
 *  Created on: Nov 17, 2015
 *      Author: emma
 */

#include "Mal\Init_all_system.h"

void Init_system(void)
{
	Init_STM();
	Init_Leds();
	INTC_InstallINTCInterruptHandler(Interrupt_Flag,30,1);

}

void Run_system(void)
{
	Run_Tasks();
}
