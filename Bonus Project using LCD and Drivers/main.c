#include <stdio.h>
#include <stdint.h>
#include "LCD_interface.h"
#include "tm4c123gh6pm.h"
#include "macros.h"
#include "DELAY_interface.h"
#include "DIO_interface.h"

void SystemInit() {}


char buf[50];
int count = 0;
//int flag = 0;

int main()
{
	LCD_voidInit();
	sprintf(buf, "%d", count);
	LCD_voidWriteString(buf);
	while(1)
	{
		/*--------------------Increment while pressing--------------------------*/
		if (DIO_ReadPort(0, 0x04) == STD_LOW) // PA2 Increment
		{
			LCD_voidSendCommand(CLEAR_SCREEN); // clear screen to clear old number and write the new one
			Delay_ms(200); // debouning effect
			count ++;
			sprintf(buf, "%d", count%1000);
			LCD_voidWriteString(buf);
		}
		/*--------------------Decrement on positive edge--------------------------*/
		if (DIO_ReadPort(0, 0x08) == STD_LOW) // PA3 Decrement
		{
			
			LCD_voidSendCommand(CLEAR_SCREEN);
			Delay_ms(200);
			count --;
			sprintf(buf, "%d", count%1000);
			LCD_voidWriteString(buf);
			while(DIO_ReadPort(0, 0x08) == 0);
		}
		/*--------------------Reset on negative edge--------------------------*/
		if (DIO_ReadPort(0, 0x10) == STD_LOW) // PA4 Reset
		{
			Delay_ms(200);
			if (DIO_ReadPort(0, 0x10) != STD_LOW) // Detect negative edge
			{
				LCD_voidSendCommand(CLEAR_SCREEN);
				Delay_ms(200);
				count = 0;
				sprintf(buf, "%d", count%1000);
				LCD_voidWriteString(buf);
			}
		} 		
	}
		
}
