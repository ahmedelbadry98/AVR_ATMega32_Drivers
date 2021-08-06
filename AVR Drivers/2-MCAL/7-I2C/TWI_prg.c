/* ******************************************/
/*  Author   : Ahmed Elbadry                */
/*  Date     : 1/2/2019 					*/
/*  Version  : V01						    */
/********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "TWI_int.h"
#include "TWI_priv.h"
#include "TWI_config.h"

void TWI_voidInit(void)
{
	TWCR = (1<<TWEN);
	//bit rate
	TWBR = 10 ;
	//prescaler
	SET_BIT(TWSR , TWPS0);
	CLEAR_BIT(TWSR , TWPS1);
	
	//TWAR = 2 ;//address slave 
}
//slave 
void TWI_voidSetMyAddress(uint8 Copy_MyAdd)
{
	
	TWAR = TWAR & 0x01 ;
	TWAR = TWAR | (Copy_MyAdd << 1) ;


}

void TWI_voidSendStart(void)
{
	//CLEAR_BIT(TWCR , TWINT);
	TWCR =   (1<<TWSTA)  | (1<<TWEN) |(1<<TWINT)  ;
	while(GET_BIT(TWCR , TWINT)  == 0);

}

void TWI_voidSendStop(void)
{
	TWCR =  (1<<TWINT) | (1<<TWEN) | (1<<TWSTO)    ;
	//while(GET_BIT(TWCR , TWINT)  == 0);

}

void TWI_voidSendByte(uint8 Copy_Byte)
{

	TWDR = Copy_Byte ;
	TWCR =   (1<<TWINT)| (1<<TWEN) ;
	while(GET_BIT(TWCR , TWINT)  == 0);

}

uint8 TWI_uint8ReceiveByteWithNoAck(void)
{
	TWCR = (1<<TWINT) | (1<<TWEN)  ;
	while(GET_BIT(TWCR , TWINT)  == 0);
	return TWDR ;
}

uint8 TWI_uint8CheckStatus(tenuI2C_Check Copy_Status)
{
	if( Copy_Status == (TWSR & 0xF8 ) )
	{
		return True ;
	}
	else
	{
		return False ;
	}
}
