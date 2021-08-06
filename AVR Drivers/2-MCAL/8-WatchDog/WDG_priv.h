/* ******************************************/
/*  Author   : Ahmed Elbadry                */
/*  Date     : 13/1/2019					*/
/*  Version  : V01						    */
/********************************************/

#ifndef WDG_PRIV_H_
#define WDG_PRIV_H_

#define WDTCR    (*((volatile uint8 *)0x21))
//#define MCUCSR    (*((volatile uint8 *)0x54))


#define WDG_TIME_OUT_163_MS  1
#define WDG_TIME_OUT_325_MS  5
#define WDG_TIME_OUT_65_MS   7
#define WDG_TIME_OUT_13_S    9
#define WDG_TIME_OUT_26_S    11
#define WDG_TIME_OUT_52_S    14
#define WDG_TIME_OUT_1_S     20
#define WDG_TIME_OUT_21_S    25





#endif /* WDG_PRIV_H_ */
