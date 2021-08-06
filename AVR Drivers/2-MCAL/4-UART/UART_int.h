/* ******************************************/
/*  Author   : Ahmed Elbadry                */
/*  Date     : 11/3/2018					*/
/*  Version  : V01						    */
/********************************************/
#ifndef UART_INT_H_
#define UART_INT_H_


void UART_voidInit(void);

void UART_voidSendByte(uint8 Byte);

uint8 UART_uint8ReceiveByte(void);

uint8 UART_uint8_ReturnUDRValue(void);

void UART_void_SetCBReceive( void (*ptr) (void) );



#endif /* UART_INT_H_ */
