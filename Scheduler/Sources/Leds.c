#include "Leds.h"
#include "stdtypedef.h"
#include "MPC5606B.h"

void Init_Leds()
{
	T_UBYTE lub_count;
	ME.RUN[0].R = 0x001F0074;       	/* RUN0 cfg: 16MHzIRCON,OSC0ON,PLL0ON,syclk=PLL */
	ME.RUNPC[0].R = 0x00000010; 	  	/* Peri. Cfg. 0 settings: only run in RUN0 mode */
	ME.PCTL[64].R = 0x0000;         	/* MPC56xxB/S SIUL:  select ME.RUNPC[0] */	
	ME.PCTL[65].R = 0x0000;
	ME.PCTL[66].R = 0x0000;
	ME.PCTL[67].R = 0x0000;
	ME.PCTL[68].R = 0x0000;         	/* MPC56xxB/S SIUL:  select ME.RUNPC[0] */	
	ME.PCTL[69].R = 0x0000;
	ME.PCTL[70].R = 0x0000;
	ME.PCTL[71].R = 0x0000;
	ME.MCTL.R = 0x40005AF0;         	/* Enter RUN0 Mode & Key */
	ME.MCTL.R = 0x4000A50F;         	/* Enter RUN0 Mode & Inverted Key */  
	
	
	for(lub_count = 68; lub_count <= 71; lub_count++)
	{
		SIU.PCR[lub_count].R = 0x0201;
		SIU.GPDO[lub_count].B.PDO = 1;
	}	
}

void Led_Toggle(T_SBYTE lsb_led)
{
	SIU.GPDO[lsb_led].B.PDO ^= 1;;
}


