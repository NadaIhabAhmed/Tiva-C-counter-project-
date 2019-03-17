#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "LCD_interface.h"
#include "DIO_interface.h"
#include "macros.h"
#include "DELAY_interface.h"
#include "PORT_interface.h"

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define PORTE 4
#define PORTF 5

uint32_t delay2;


//initialization function...must be called when using LCD
void LCD_voidInit(void)//any pin that i will use must set it's direction first 'OUTPUT'
{
	//LCD initialization
	Port_Init(1); // PORTB initialization
	Port_SetPinDirection(PORTB, 0xFF, 1); // PORTB FROM PB0 -> PB7 ARE OUTPUT
	
	//SWITCHES 
	Port_Init(0); //PORTA initialization
	Port_SetPinDirection(PORTA, 0X1C, 0); // PA2, PA3, PA4 are input
	Port_SetPinPullUp(PORTA, 0X1C, 1); // PA2, PA3, PA4 are input pull up
	

	LCD_voidSendCommand(MODE_8_BIT);// defines 5x7 pixels
	Delay_ms(5);
	LCD_voidSendCommand(DISPLAY_ON_CURSOR_OFF);
	Delay_ms(5);
	LCD_voidSendCommand(CLEAR_SCREEN);//#define CLEAR_SCREEN 0x01....put it in LCD_interface.h not in the config.h cause it will not be change
	Delay_ms(5);//clear bit

}
void LCD_voidWriteCharacter(char Character)
{
	//SET_BIT(GPIO_PORTA_DATA_R, 7);
	DIO_WrirePort(PORTA, 0x80, 1);
	GPIO_PORTB_DATA_R = 0;
	//GPIO_PORTB_DATA_R = Character;
	DIO_WrirePort(1, Character, 1);
	//SET_BIT(GPIO_PORTA_DATA_R, 5);
	DIO_WrirePort(0, 0X20, 1);
	Delay_ms(2);
	//CLEAR_BIT(GPIO_PORTA_DATA_R, 5);
	DIO_WrirePort(0, 0X20, 0);
}

void LCD_voidSendCommand(int Command)
{
	//CLEAR_BIT(GPIO_PORTA_DATA_R, 7);
	DIO_WrirePort(0, 0X80, 0);
	GPIO_PORTB_DATA_R = Command;
	//DIO_WrirePort(1, Command, 1);
	//SET_BIT(GPIO_PORTA_DATA_R, 5);
	DIO_WrirePort(0, 0X20, 1);
	Delay_ms(2);
	//CLEAR_BIT(GPIO_PORTA_DATA_R, 5);
	DIO_WrirePort(0, 0X20, 0);

}

void LCD_voidWriteString(char * String)//like char star
{
	while((*String) != '\0')
	{
		LCD_voidWriteCharacter(*String);
		String++;
	}
}

