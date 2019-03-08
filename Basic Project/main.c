#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "SEVEN_SEGMENT_interface.h"
#include "SWITCH_interface.h"
#include "DELAY_interface.h"
#include "macros.h"

void SystemInit() {}
int count = 0;
		
	
int main()
{
	SWITCH_voidInit();
	SEVEN_SEGMENT_voidInit();
	
	while(1)
	{//(GPIO_PORTA_DATA_R & 0x7c) == 0x5c
		//(GPIO_PORTA_DATA_R & 0x5c) == 0x58
		//(GPIO_PORTA_DATA_R & 0x5c) == 0x54
		//(GPIO_PORTA_DATA_R & 0x5c) == 0x1c 
		if(!GET_BIT(GPIO_PORTA_DATA_R, 5)) // PA5
		{
			SEVEN_SEGMENT_voidWriteNumber_1(count);
			SEVEN_SEGMENT_voidWriteNumber_2(count);
			SEVEN_SEGMENT_voidWriteNumber_3(count);
		
			if( !GET_BIT(GPIO_PORTA_DATA_R, 2)) // PA2
			{
				Delay(1);
				count ++;
				SEVEN_SEGMENT_voidWriteNumber_1(count % 10); 
				SEVEN_SEGMENT_voidWriteNumber_2(count / 10); 
				SEVEN_SEGMENT_voidWriteNumber_3(count / 100); 
			}
			if(!GET_BIT(GPIO_PORTA_DATA_R, 3)) // PA3
			{
				Delay(1);
				count --;
				SEVEN_SEGMENT_voidWriteNumber_1(count % 10); 
				SEVEN_SEGMENT_voidWriteNumber_2(count / 10); 
				SEVEN_SEGMENT_voidWriteNumber_3(count / 100); 
			}
			
			if(!GET_BIT(GPIO_PORTA_DATA_R, 4)) // PA4
			{
				Delay(1);
				count = 0;
				SEVEN_SEGMENT_voidWriteNumber_1(count);
				SEVEN_SEGMENT_voidWriteNumber_2(count);
				SEVEN_SEGMENT_voidWriteNumber_3(count);
				
			}
		}
		else
		{
				SEVEN_SEGMENT_voidClearSegment();
			
		}

	}
	
}
