/*
 *  Created on: 17/3/2018
 *  Author: Ahmed Elbadry
 *  Version : v01
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_int.h"
#include "GIE_priv.h"
#include "GIE_config.h"




void GIE_voidEnable(void)
{
	SET_BIT(SREG , I_BIT) ;
}


void GIE_voidDisable(void)
{
	
	CLEAR_BIT(SREG , I_BIT);
}