/* ******************************************/
/*  Author   : Ahmed Elbadry                */
/*  Date     : 28/12/2018					*/
/*  Version  : V01						    */
/********************************************/

#define F_CPU 8000000UL

#include <util/delay.h>

#include "BIT_MATH.h"
#include "STD_Types.h"
#include "DIO_int.h"
#include "LCD_int.h"

#define F_CPU 8000000UL

int main()

{

	DIO_vid_Init();
	LCD_vidInit();

	LCD_vidWriteCharacter('A');

	LCD_vidGoToRowCol(1 , 5);
	LCD_vidWriteCharacter('B');
	_delay_ms(3000);
	LCD_vidClearScreen();
	while(1)
	{
		LCD_vidGoToRowCol(0 , 5);
		LCD_vidWriteString("Embedded");
		_delay_ms(2000);
		LCD_vidGoToRowCol(1 , 5);
		LCD_vidWriteString("System");
		_delay_ms(2000);
		LCD_vidClearScreen();
		LCD_vidGoToRowCol(0 , 5);
		LCD_vidWriteString("TESTONE");
		_delay_ms(2000);
		LCD_vidGoToRowCol(1 , 5);
		LCD_vidWriteString("IS_IT_OK");
		_delay_ms(2000);

	}

	return 0 ;
}
