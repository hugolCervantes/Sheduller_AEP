/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: task.c 
 * $Revision: version 1.0 
 * $Author: Mar�a Isamar Salda�a G�lvez / Oswaldo Garc�a Cervantes $
 * $Date: 13/11/15 
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** This file contains the functions necessary to configure the scheduler's 
 * tasks, the user only can use this .c to add new tasks.
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
#include "Application\task.h"
#include "Mal\kernel.h"
/* Constants and types  */
/*============================================================================*/


/* Variables */
/*============================================================================*/
T_SBYTE rsb_Bttn = 0;
T_SBYTE rsb_CountMs = 0;
T_SBYTE rsb_Led = 0;


T_UBYTE rub_downPress = 0;
T_UBYTE rub_downPress_v = 0;
T_UBYTE rub_countD_man = 0; //Counter down manual
T_UBYTE rub_bandD_m = 0;

T_UBYTE rub_upPress = 0;
T_UBYTE rub_upPress_v = 0;
T_UBYTE rub_countU_man = 0; //Counter up manual
T_UBYTE rub_bandU_m = 0;

T_UBYTE rub_antipPress = 0;
T_UBYTE rub_antipPress_v = 0;
T_UBYTE rub_countFor = 0;
T_UBYTE rub_cont5s = 0;


/* Private functions prototypes */
/*============================================================================*/


/* Inline functions */
/*============================================================================*/


/* Private functions */
/*============================================================================*/

/* Exported functions */
/*============================================================================*/

/*In this part you can add a new function, if you like a new task
 * 
 * **First: You can do add a new task function in the low part
 * **Second: You can add a function in the struct 
 */ 

const s_task task_list[num_tasks] = {
	
/*  Name task	           		|Period	              |Offset			*/		
	{task1_Pb_Up,	        	 10,			        1},
	{task2_Pb_Down,		         10,			        2},
	{task3_Pb_AntiP,		     10,			        3},
	{task4_State_Machine,		 400,			        4}

};


/*Tasks of the scheduller*/

void task1_Pb_Up(void){    			//Valid Push Button Up  
	if( !PButt_Press(PBUTT_UP) && rub_upPress == 1 && rub_antipPress_v == 0 && rub_antipPress_v == 0)
		{
			rub_upPress_v = 1;
			rub_upPress = 0;
			//rub_upPress_v = 0;
		}
		else if( !PButt_Press(PBUTT_UP) && rub_antipPress_v == 0)
		{
			rub_upPress = 1;
			
			/* make sure the other valid press doesn�t count on machine states*/
			rub_downPress = 0;
		}
		
		
		
		if(rub_upPress_v == 1 && PButt_Press(PBUTT_UP) && rub_countU_man < 50 && rub_bandU_m == 0)//up auto
		{//////////////
			rub_upPress_v = 0;
			rsb_Bttn = 'b';
			Led_Off(LED_BLUE_UP);
		}
		
		if(!PButt_Press(PBUTT_UP) && rub_upPress_v == 1 && rub_countU_man < 50)
		{
			rub_countU_man++;
		}
		
		if(rub_countU_man == 50 && !PButt_Press(PBUTT_UP))//up manual
		{
			rsb_Bttn = 'u';
			rub_bandU_m = 1;
			Led_Off(LED_BLUE_UP);
		}

}

void task2_Pb_Down(void){   		//Valid Push Button Down
	if( !PButt_Press(PBUTT_DOWN) && rub_downPress == 1 && rub_antipPress_v == 0)
	{
		rub_downPress_v = 1;
		rub_downPress = 0;
		
	}
	else if( !PButt_Press(PBUTT_DOWN) && rub_antipPress_v == 0)
	{
		rub_downPress = 1;
		
		/* make sure the other valid press doesn�t count on machine states*/
		rub_upPress = 0;
	}
	
	
	
	if(rub_downPress_v == 1 && PButt_Press(PBUTT_DOWN) && rub_countD_man < 50 && rub_bandD_m == 0)//down auto
	{
		rub_downPress_v = 0;
		rsb_Bttn = 'c';
		Led_Off(LED_GREEN_DOWN);
	}
	
	if(!PButt_Press(PBUTT_DOWN) && rub_downPress_v == 1 && rub_countD_man < 50)
	{
		rub_countD_man++;
	}
	
	if(rub_countD_man == 50 && !PButt_Press(PBUTT_DOWN))//down manual
	{
		rsb_Bttn = 'd';
		rub_bandD_m = 1;
		Led_Off(LED_GREEN_DOWN);
		
	}

	

}

void task3_Pb_AntiP(void){    		//Valid Push Button Antipinch

	if( !PButt_Press(PBUTT_APINCH) && rub_antipPress == 1)
		{
			rub_antipPress_v = 1;
			rub_antipPress = 0;
			rsb_Bttn = 'a';
			Led_Off(LED_GREEN_DOWN);
			Led_On(LED_BLUE_UP);
		}
		else if( !PButt_Press(PBUTT_APINCH) )
		{
			rub_antipPress = 1;
		}
}

void task4_State_Machine(void){     //Task 4
	switch (rsb_Bttn) {
		case 'u'://up 
			
			if(rub_antipPress_v == 1)
			{
				rsb_Bttn = 'a';
				break;
			}
			if(rsb_Led >= 0 && !PButt_Press(PBUTT_UP) &&  rub_antipPress_v == 0)////?
			{
				Led_On(rsb_Led);
				if(rsb_Led != 0)
				{
					rsb_Led--;
				}
				rsb_CountMs = 0;
				rub_bandU_m = 0;
			}
			if(PButt_Press(PBUTT_UP))
			{
				rub_bandU_m = 0;
				rub_upPress_v = 0;
				rub_countU_man = 0;
				Led_On(LED_BLUE_UP);
			}
			
			break;
		case 'd'://down 
			
			if(rsb_Led <= 9 && !PButt_Press(PBUTT_DOWN) && rub_antipPress_v == 0)
			{
				Led_Off(rsb_Led);
				if(rsb_Led != 9)
				{
					rsb_Led++;
				}
				rsb_CountMs = 0;
				rub_bandD_m = 0;
			}
			if(PButt_Press(PBUTT_DOWN))
			{
				rub_bandD_m = 0;
				rub_downPress_v = 0;
				rub_countD_man = 0;
				Led_On(LED_GREEN_DOWN);	
			}
			
			//}
			
			break;
		case 'b'://up auto
			
			if(rsb_Led >= 0 /*&& PButt_Press(PBUTT_UP)*/)
			{
				Led_On(rsb_Led);
				if(rsb_Led != 0)
				{
					rsb_Led--;
				}
				
				rsb_CountMs = 0;
				if(rsb_Led == 0)
				{
					rub_upPress_v = 0;
					Led_On(LED_BLUE_UP);
				}
			}
			
			break;
		case 'c'://down auto
			
			if(rsb_Led <= 9 /*&& PButt_Press(PBUTT_DOWN)*/)
			{
				Led_Off(rsb_Led);
				if(rsb_Led != 9)
				{
					rsb_Led++;
				}
				
				rsb_CountMs = 0;
				if(rsb_Led == 9)
				{
					rub_downPress_v = 0;
					
				}
			}
			if(rsb_Led == 9)
			{
				Led_On(LED_GREEN_DOWN);
			}

			
			break;
		case 'a'://anti pinch
			
			if(rsb_Led <= 9)
			{
				Led_Off(rsb_Led);
				rsb_Led++;
				rsb_Bttn = 'a';
				Led_Off(LED_GREEN_DOWN);
				Led_On(LED_BLUE_UP);
			}
			else
			{
				Led_On(LED_GREEN_DOWN); 
				if(rub_cont5s <= 11)
				{
					rub_cont5s++;
				}
				else
				{
					rsb_Bttn = 0;
					rub_cont5s = 0;
					rub_antipPress_v = 0;//borrar la bandera 
				}
			}
			
			break;
		default://Init state - The window is totally close 
			break;
			
		rsb_Bttn = '0';
	}
}


 /* Notice: the file ends with a blank new line to avoid compiler warnings */

