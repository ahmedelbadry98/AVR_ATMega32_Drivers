/*
 * main.c
 *
 *  Created on: Feb 1, 2019
 *      Author: Mohamed Sobhy
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "DIO_int.h"
#include "TWI_int.h"
#include "EEPROM_int.h"
#include "LCD_int.h"


int main(void)
{
	uint8 arr[8] = {0} ;
	DIO_vid_Init();
	TWI_voidInit();
	EEPROM_voidInit();
	LCD_vidInit();

	/*Test LCD*/
	LCD_vidWriteCharacter('A');
	LCD_vidWriteCharacter('B');
	_delay_ms(2000);
	LCD_vidClearScreen();
/*
 *
 * Write data to EEPROM character by character
 *
 * */
	EEPROM_VoidWriteByte(0x0000 , 'E');
	_delay_ms(1);
	EEPROM_VoidWriteByte(0x0001 , 'M');
	_delay_ms(1);
	EEPROM_VoidWriteByte(0x0002 , 'B');
	_delay_ms(1);
	EEPROM_VoidWriteByte(0x0003 , 'E');
	_delay_ms(1);
	EEPROM_VoidWriteByte(0x0004 , 'D');
	_delay_ms(1);
	EEPROM_VoidWriteByte(0x0005 , 'D');
	_delay_ms(1);
	EEPROM_VoidWriteByte(0x0006 , 'E');
	_delay_ms(1);
	EEPROM_VoidWriteByte(0x0007 , 'D');


	_delay_ms(3000);

	/*
	 *
	 * Read data from EEPROM character by character
	 * And store it to the array
	 * */


	 arr[0]  =  EEPROM_uint8ReadByte(0x0000);
	// _delay_ms(1);
	 arr[1]  =  EEPROM_uint8ReadByte(0x0001);
	// _delay_ms(1);
	 arr[2]  =  EEPROM_uint8ReadByte(0x0002);
	// _delay_ms(1);
	 arr[3]  =  EEPROM_uint8ReadByte(0x0003);
	 //_delay_ms(1);
	 arr[4]  =  EEPROM_uint8ReadByte(0x0004);
	 //_delay_ms(1);
	 arr[5]  =  EEPROM_uint8ReadByte(0x0005);
	 //_delay_ms(1);
	 arr[6]  =  EEPROM_uint8ReadByte(0x0006);
	 //_delay_ms(1);
	 arr[7]  =  EEPROM_uint8ReadByte(0x0007);
	 //_delay_ms(1);

	 /*
	  * Display the data in he array through LCD
	  *
	  * */
	LCD_vidWriteCharacter(arr[0]);
	LCD_vidWriteCharacter(arr[1]);
	LCD_vidWriteCharacter(arr[2]);
	LCD_vidWriteCharacter(arr[3]);
	LCD_vidWriteCharacter(arr[4]);
	LCD_vidWriteCharacter(arr[5]);
	LCD_vidWriteCharacter(arr[6]);
	LCD_vidWriteCharacter(arr[7]);

	while(1)
	{

	}


	return 0 ;

}
