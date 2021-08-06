/* ******************************************/
/*  Author   : Ahmed Elbadry                */
/*  Date     : 13/1/2019					*/
/*  Version  : V01						    */
/********************************************/

#include "STD_Types.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_int.h"
#include "WDG_int.h"


int main()
{

	DIO_vid_Init();

	WDG_On();
	DIO_vid_SetPinValue(DIO_uint8_PIN_0 , DIO_uint8_HIGH);
	_delay_ms(1000);
	//WDG_Refresh();
	DIO_vid_SetPinValue(DIO_uint8_PIN_0 , DIO_uint8_LOW);
	_delay_ms(1000);


	/* Without disable The WDG timer the system will remain reset and the led will remain Toggle */
	WDG_Off();


	while(1)
	{
		DIO_vid_SetPinValue(DIO_uint8_PIN_8 , DIO_uint8_HIGH);
		_delay_ms(1000);
		DIO_vid_SetPinValue(DIO_uint8_PIN_8 , DIO_uint8_LOW);
		_delay_ms(1000);


	}


	return 0 ;
}
