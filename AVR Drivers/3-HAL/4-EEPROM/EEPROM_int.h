/* ******************************************/
/*  Author   : Ahmed Elbadry                */
/*  Date     : 1/2/2019 					*/
/*  Version  : V01						    */
/********************************************/

#ifndef EEPROM_INT_H_
#define EEPROM_INT_H_

void EEPROM_voidInit(void);
void EEPROM_VoidWriteByte(uint16 Copy_Location , uint8 Copy_Data);
uint8 EEPROM_uint8ReadByte(uint16 Copy_Location);

#endif /* EEPROM_INT_H_ */
