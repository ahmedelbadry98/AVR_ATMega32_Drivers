/* ******************************************/
/*  Author   : Ahmed Elbadry                */
/*  Date     : 28/12/2018					*/
/*  Version  : V01						    */
/********************************************/

#ifndef LCD_INT_H_
#define LCD_INT_H_


void LCD_vidInit(void);

void LCD_vidWriteCharacter(uint8 Copy_uint8data);

void LCD_vidWriteCommand(uint8 Copy_uint8cmd);

void LCD_vidWriteString(uint8 * Copy_pString);

void LCD_vidGoToRowCol(uint8 Copy_uint8Row , uint8 Copy_uint8Col );

void LCD_vidClearScreen(void);

#endif /* LCD_INT_H_ */
