/* ******************************************/
/*  Author   : Ahmed Elbadry                */
/*  Date     : 21/2/2019					*/
/*  Version  : V01						    */
/********************************************/

#include <util/delay.h>

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_int.h"
#include "SSegment_int.h"


#define START 0
#define END 9

int main(void)
{
	uint8 Local_uint8_LoopIndex ;

	DIO_vid_Init();

	while(1)
	{

		for(Local_uint8_LoopIndex = START ; Local_uint8_LoopIndex <= END ; Local_uint8_LoopIndex++)
		{
			Ssegment_void_WriteNum(SSEGMENT_ONE , Local_uint8_LoopIndex);
			_delay_ms(1000);
		}



	}


	return 0 ;
}


