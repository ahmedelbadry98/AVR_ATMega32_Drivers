/* ******************************************/
/*  Author   : Ahmed Elbadry                */
/*  Date     : 29/12/2018					*/
/*  Version  : V01						    */
/********************************************/


#include "BIT_MATH.h"
#include "STD_Types.h"

#include <util/delay.h>

/*
#define F_CPU 8000000UL

#include "util/delay.h"
 */

#include "DIO_int.h"
#include "LCD_int.h"
#include "KeyPad_int.h"



uint8 Keypad_uint8_AdjustKey2(uint8 Copy_uint8_ButtonNo);


uint8 Keypad_uint8_AdjustKey2(uint8 Copy_uint8_ButtonNo)
{

	switch(Copy_uint8_ButtonNo)
	{
	case 0 :
		Copy_uint8_ButtonNo =  1 ;
		break ;
	case 1 :
		Copy_uint8_ButtonNo =  2 ;
		break ;
	case 2 :
		Copy_uint8_ButtonNo =  3 ;
		break ;
	case 3 :
		Copy_uint8_ButtonNo =  '+' ;
		break ;
	case 4 :
		Copy_uint8_ButtonNo =  4 ;
		break ;
	case 5 :
		Copy_uint8_ButtonNo =  5 ;
		break ;
	case 6 :
		Copy_uint8_ButtonNo =  6 ;
		break ;
	case 7 :
		Copy_uint8_ButtonNo =  '-' ;
		break ;
	case 8 :
		Copy_uint8_ButtonNo =  7 ;
		break ;
	case 9 :
		Copy_uint8_ButtonNo =  8 ;
		break ;
	case 10 :
		Copy_uint8_ButtonNo =  9 ;
		break ;
	case 11 :
		Copy_uint8_ButtonNo =  '*' ;
		break ;
	case 12 :
		Copy_uint8_ButtonNo =  '#' ;
		break ;
	case 13 :
		Copy_uint8_ButtonNo =  0 ;
		break ;
	case 14 :
		Copy_uint8_ButtonNo =  '=' ;
		break ;
	case 15 :
		Copy_uint8_ButtonNo =  '/' ;
		break ;

	} // end of switch

	return Copy_uint8_ButtonNo ;


}




uint8 Keypad_uint8_AdjustKey(uint8 Copy_uint8_ButtonNo);


uint8 Keypad_uint8_AdjustKey(uint8 Copy_uint8_ButtonNo)
{

	switch(Copy_uint8_ButtonNo)
	{
	case 0 :
		Copy_uint8_ButtonNo =  '1' ;
		break ;
	case 1 :
		Copy_uint8_ButtonNo =  '2' ;
		break ;
	case 2 :
		Copy_uint8_ButtonNo =  '3' ;
		break ;
	case 3 :
		Copy_uint8_ButtonNo =  '+' ;
		break ;
	case 4 :
		Copy_uint8_ButtonNo =  '4' ;
		break ;
	case 5 :
		Copy_uint8_ButtonNo =  '5' ;
		break ;
	case 6 :
		Copy_uint8_ButtonNo =  '6' ;
		break ;
	case 7 :
		Copy_uint8_ButtonNo =  '-' ;
		break ;
	case 8 :
		Copy_uint8_ButtonNo =  '7' ;
		break ;
	case 9 :
		Copy_uint8_ButtonNo =  '8' ;
		break ;
	case 10 :
		Copy_uint8_ButtonNo =  '9' ;
		break ;
	case 11 :
		Copy_uint8_ButtonNo =  '*' ;
		break ;
	case 12 :
		Copy_uint8_ButtonNo =  '#' ;
		break ;
	case 13 :
		Copy_uint8_ButtonNo =  '0' ;
		break ;
	case 14 :
		Copy_uint8_ButtonNo =  '=' ;
		break ;
	case 15 :
		Copy_uint8_ButtonNo =  '/' ;
		break ;

	} // end of switch

	return Copy_uint8_ButtonNo ;


}




void main()
{

	uint8 Local_uint8Index ;
	uint16 Local_uint16RetValue = 0 ;
	uint8 Local_ones ;
	uint8 Local_tens ;
	DIO_vid_Init();
	LCD_vidInit();
	KeyPad_voidInit();

	uint8 i=0;
	uint8 arr[16];
	uint16 result;

	LCD_vidWriteString("HELLO BADRY");

	_delay_ms(2000);
	LCD_vidClearScreen();




	while(1)
	{
		Local_uint16RetValue = KeyPad_uint16GetStatus();
		_delay_ms(150);



		for(Local_uint8Index = 0 ; Local_uint8Index < 16 ; Local_uint8Index++)
		{
			if( GET_BIT(Local_uint16RetValue , Local_uint8Index) )
			{

					LCD_vidGoToRowCol(0 , 0);
					LCD_vidWriteCharacter(Keypad_uint8_AdjustKey(Local_uint8Index));
					//arr[i]=Keypad_uint8_AdjustKey2(Local_uint8Index) ;
					arr[i]=Local_uint8Index;
					i++;
					LCD_vidWriteCharacter(' ');
					_delay_ms(500);

					if(Local_uint8Index == 12){LCD_vidClearScreen(); i=0;}
if(Local_uint8Index == 14){

					for(int ii=0;ii<4;ii++){
						LCD_vidGoToRowCol(1 , ii);
						LCD_vidWriteCharacter(Keypad_uint8_AdjustKey(arr[ii]));
						LCD_vidWriteCharacter(' ');
						_delay_ms(700);

					                       }
					LCD_vidGoToRowCol(1 , 4);
					if(arr[1]==3){result=(arr[0]+arr[2]);}
					if(arr[1]==7){result=(arr[0]-arr[2]);}
					if(arr[1]==11){result=(arr[0]*arr[2]);}
					if(arr[1]==11){result=(arr[0]/arr[2]);}

					if(result>9){Local_ones = (result) % 10 ;
					Local_tens = result / 10 ;
					LCD_vidWriteCharacter(Local_tens + 48);
					LCD_vidWriteCharacter(Local_ones + '0' );
					_delay_ms(500);}

					else LCD_vidWriteCharacter(result + '0');
					//if(arr[1]==15){LCD_vidWriteCharacter((arr[0]/arr[2])+'0');}
                        }



			}

			}

		}




	}

