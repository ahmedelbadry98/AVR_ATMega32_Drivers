/* ******************************************/
/*  Author   : Ahmed Elbadry                */
/*  Date     : 13/1/2019					*/
/*  Version  : V01						    */
/********************************************/

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "WDG_int.h"
#include "WDG_priv.h"
#include "WDG_config.h"





void WDG_On(void)
{

	#if WDG_TIME_OUT == WDG_TIME_OUT_163_MS
		CLEAR_BIT(WDTCR , 0);
		CLEAR_BIT(WDTCR , 1);
		CLEAR_BIT(WDTCR , 2);
	#elif 	WDG_TIME_OUT == WDG_TIME_OUT_325_MS
		SET_BIT(WDTCR , 0);
		CLEAR_BIT(WDTCR , 1);
		CLEAR_BIT(WDTCR , 2);
	#elif 	WDG_TIME_OUT == WDG_TIME_OUT_65_MS
		CLEAR_BIT(WDTCR , 0);
		SET_BIT(WDTCR , 1);
		CLEAR_BIT(WDTCR , 2);
	#elif 	WDG_TIME_OUT == WDG_TIME_OUT_13_MS
		SET_BIT(WDTCR , 0);
		SET_BIT(WDTCR , 1);
		CLEAR_BIT(WDTCR , 2);
	#elif 	WDG_TIME_OUT == WDG_TIME_OUT_26_MS
		CLEAR_BIT(WDTCR , 0);
		CLEAR_BIT(WDTCR , 1);
		SET_BIT(WDTCR , 2);
	#elif 	WDG_TIME_OUT == WDG_TIME_OUT_52_MS
		SET_BIT(WDTCR , 0);
		CLEAR_BIT(WDTCR , 1);
		SET_BIT(WDTCR , 2);
	#elif 	WDG_TIME_OUT == WDG_TIME_OUT_1_S
		CLEAR_BIT(WDTCR , 0);
		SET_BIT(WDTCR , 1);
		SET_BIT(WDTCR , 2);
	#elif 	WDG_TIME_OUT == WDG_TIME_OUT_21_S
		SET_BIT(WDTCR , 0);
		SET_BIT(WDTCR , 1);
		SET_BIT(WDTCR , 2);

	#endif

		/* Enable WDG timer */
		SET_BIT(WDTCR , 3);
}

void WDG_Off(void)
{
	/*At the same operation write one on bit 3(WDE) and  4(WDTOE) */
	WDTCR = 0xFF ;
	/* Turn off WDT */
	WDTCR = 0x00 ;
}

void WDG_Refresh(void)
{
	/* This instruction is to refresh the WDG */
	asm("WDR") ;

}
