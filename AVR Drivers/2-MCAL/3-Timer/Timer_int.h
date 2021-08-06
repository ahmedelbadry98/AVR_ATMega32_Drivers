/* ******************************************/
/*  Author   : Ahmed Elbadry                */
/*  Date     : 23/3/2018					*/
/*  Version  : V01						    */
/********************************************/


#ifndef _TIMER0_INT_H
#define _TIMER0_INT_H


void TIMER0_void_Init(void);

void TIMER0_void_SetTimerReg(uint8 Copy_uint8Val);

void TIMER0_void_SetCompareVal(uint8 Copy_uint8Val);

void TIMER0_void_EnableOVInt(void);

void TIMER0_void_DisableOVInt(void);

void TIMER0_void_EnableCTCInt(void);

void TIMER0_void_DisableCTCInt(void);

void TIMER0_void_SetOVCallBack(void (*Copy_ptr) (void) ) ;

void TIMER0_void_SetCTCCallBack(void (*Copy_ptr) (void) ) ;


#endif