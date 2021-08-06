/* ******************************************/
/*  Author   : Ahmed Elbadry                */
/*  Date     : 1/2/2019 					*/
/*  Version  : V01						    */
/********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "EEPROM_int.h"
#include "EEPROM_priv.h"
#include "EEPROM_config.h"
#include "TWI_int.h"
#include "DIO_int.h"
void EEPROM_voidInit(void)
{
	TWI_voidInit();
}


void EEPROM_VoidWriteByte(uint16 Copy_Location , uint8 Copy_Data)
{

	uint8 SLA_W = 0b10100000 ;
	uint8 P0 = GET_BIT(Copy_Location , 8);
	uint8 P1 = GET_BIT(Copy_Location , 9);
	SLA_W |= ((P0<<1) | (P1<<2));
	TWI_voidSendStart();
	if(True == TWI_uint8CheckStatus(StrConTx))
	{

		TWI_voidSendByte(SLA_W);
		if(True == TWI_uint8CheckStatus(SlA_W_Ack))
		{
			TWI_voidSendByte((uint8)  Copy_Location);
			if(True == TWI_uint8CheckStatus(Data_TX_Ack))
			{
				TWI_voidSendByte(Copy_Data);
				if(True == TWI_uint8CheckStatus(Data_TX_Ack))
				{
					TWI_voidSendStop();
				}
			}
		}
	}
}

uint8 EEPROM_uint8ReadByte(uint16 Copy_Location)
{

	uint8 RetVal ;
	uint8 SLA_W = 0b10100000;
	uint8 SLA_R ;
	uint8 P0 = GET_BIT(Copy_Location , 8);
	uint8 P1 = GET_BIT(Copy_Location , 9);
	SLA_W |= (P0<<1) | (P1<<2);
	SLA_R = SLA_W + 1 ;
	TWI_voidSendStart();
	if(True == TWI_uint8CheckStatus(StrConTx))
	{
		TWI_voidSendByte(SLA_W);
		if(True == TWI_uint8CheckStatus(SlA_W_Ack))
		{
			TWI_voidSendByte((uint8)  Copy_Location);
			if(True == TWI_uint8CheckStatus(Data_TX_Ack))
			{
				TWI_voidSendStart();
				if(True == TWI_uint8CheckStatus(RepStrConTx))
				{
					TWI_voidSendByte(SLA_R);
					if(True == TWI_uint8CheckStatus(SLA_R_W_ACK)) //0x40
					{
						RetVal = TWI_uint8ReceiveByteWithNoAck();
						TWI_voidSendStop();
					}
				}
			}
		}
	}

	return RetVal ;
}

