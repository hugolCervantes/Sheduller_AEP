/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: task.c $
 * $Revision: version 1.0 $
 * $Author: María Isamar Saldaña Gálvez / Oswaldo García Cervantes $
 * $Date: 13/11/15 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** This file contains the functions necessary to configure the scheduler's 
 * tasks 
*/
/*============================================================================*/
/* COPYRIGHT (C) CONTINENTAL AUTOMOTIVE 2015                                  */
/* AUTOMOTIVE GROUP, Interior Division, Body and Security                     */
/* ALL RIGHTS RESERVED                                                        */
/*                                                                            */
/* The reproduction, transmission, or use of this document or its content is  */
/* not permitted without express written authority. Offenders will be liable  */
/* for damages.                                                               */
/* All rights, including rights created by patent grant or registration of a  */
/* utility model or design, are reserved.                                     */
/*                                                                            */
/*============================================================================*/
/*============================================================================*/
/*                    REUSE HISTORY - taken over from                         */
/*============================================================================*/
/*  DATABASE           |        PROJECT     | FILE VERSION (AND INSTANCE)     */
/*----------------------------------------------------------------------------*/
/*                     | Scheduler          | 1.0                             */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: task.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "task.h"
#include "OS_Init.h"
#include "STM_Timer.h"////8
#include "Leds.h"


/* Constants and types  */
/*============================================================================*/



/* Variables */
/*============================================================================*/

T_UBYTE rub_cont = 0;
T_ULONG raul_dyn[num_tasks];
T_UBYTE rub_tickFlag;///8

/* Private functions prototypes */
/*============================================================================*/



/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/

/* Exported functions */
/*============================================================================*/
/*  Name task	   |Period	   |Offset			*/
const s_task task_list[num_tasks] = {
	{task_led1,		 250,			10},
	{task_led2,		 500,			20},
	{task_led3,		1000,			30},
	{task_led4,		2000,			40}
};

void Run_Tasks()
{
	while(1){
		if(rub_tickFlag)
		{
			rub_tickFlag = 0;
			for(rub_cont = 0; rub_cont < num_tasks; rub_cont++)
			{
				if(raul_dyn[rub_cont] > 0)
				{
					raul_dyn[rub_cont]--;
				}
				else
				{
					raul_dyn[rub_cont] = task_list[rub_cont].period;
					task_list[rub_cont].tasks();
				}
			}
		}
	}
}

void task_led1(){
	Led_Toggle(68);
}

void task_led2(){
	Led_Toggle(69);
}

void task_led3(){
	Led_Toggle(70);
}

void task_led4(){
	Led_Toggle(71);
}



void Interrupt_Flag(void)///8
{ 
	if(STM.CH[0].CIR.B.CIF){
		rub_tickFlag = 1;
		STM.CNT.R = 0; 				//Init in 0
		STM.CH[0].CIR.B.CIF = 1;	//Clear interrupt flag		
	}

}


 /* Notice: the file ends with a blank new line to avoid compiler warnings */

