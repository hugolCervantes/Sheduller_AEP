/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: task.h $
 * $Revision: version 1.0 $
 * $Author: María Isamar Saldaña Gálvez / Oswaldo García Cervantes $
 * $Date: 13/11/15 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** Headers of task.c, includes the enum necessary to configure the number 
 * of tasks
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
 * $Log: task.h  $
  ============================================================================*/
#ifndef TASK_H_
#define TASK_H_

/* Includes */
/*============================================================================*/
#include "stdtypedef.h"

/* Constants and types */
/*============================================================================*/
typedef struct{
	void (* tasks)();
	T_BIT_STRUCT period;
	T_BIT_STRUCT offset;
	
}s_task; 

typedef enum{
	task1,
	task2,
	task3,
	task4,
	num_tasks
}e_task;



/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/
void Run_Tasks();
void task_led1();
void task_led2();
void task_led3();
void task_led4();
void Interrupt_Flag(void);
#endif /* TASK_H_ */  /* Notice: the file ends with a blank new line to avoid compiler warnings */









