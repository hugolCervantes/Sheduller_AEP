/*
 * Timer.h
 *
 *  Created on: Nov 3, 2015
 *      Author: Isa
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "stdtypedef.h"
#include "MPC5606B.h"

//Macros for channels of timer
#define TM_1MS		0
#define	TM_400MS 	1
#define TM_500MS	2
#define	TM_5S		3

void Init_STM();
void Restart_STM(T_UBYTE);
T_UBYTE Flag_STM(T_UBYTE);

#endif /* TIMER_H_ */
