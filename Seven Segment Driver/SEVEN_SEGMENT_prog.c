#include "SEVEN_SEGMENT_interface.h"
#include "SEVEN_SEGMENT_config.h"
//#include "BITS.h"
#include "tm4c123gh6pm.h"
#include "stdint.h"
#include "macros.h"

#define OUTPUT 1
#define INPUT  0
#define HIGH   1
#define LOW    0

	
void SEVEN_SEGMENT_voidInit(void)
{
  uint32_t delay;
	SET_BIT(SYSCTL_RCGCGPIO_R, 1); //1.  or SYSCTL_RCGCGPIO_R |= 0x02; -> mask of port b (set portb to one to enable it's clock)
	delay = 1; // dummy peripheral or use the other way
	GPIO_PORTB_LOCK_R = 0X4C4F434B; // unlock portb
	GPIO_PORTB_CR_R = 0XFF; //commit register
	GPIO_PORTB_AFSEL_R = 0; //2. don't want an alternative function (GPIO MODE)
	GPIO_PORTB_PCTL_R = 0; // 3. don't want an alternative function
	GPIO_PORTB_AMSEL_R = 0; // 4. not in analog mode
	GPIO_PORTB_DIR_R = 0xFF; // pin are output
	GPIO_PORTB_DEN_R = 0XFF; // pin are digital
	//GPIO_PORTB_PUR_R = 0X11; //  pull up resistor
	
	SET_BIT(SYSCTL_RCGCGPIO_R, 4); //1.  or SYSCTL_RCGCGPIO_R |= 0x02; -> mask of port b (set portb to one to enable it's clock)
	delay = 1; // dummy peripheral or use the other way
	GPIO_PORTE_LOCK_R = 0X4C4F434B; // unlock portb
	GPIO_PORTE_CR_R = 0XFF; //commit register
	GPIO_PORTE_AFSEL_R = 0; //2. don't want an alternative function (GPIO MODE)
	GPIO_PORTE_PCTL_R = 0; // 3. don't want an alternative function
	GPIO_PORTE_AMSEL_R = 0; // 4. not in analog mode
	GPIO_PORTE_DIR_R = 0xFF; // pin are output
	GPIO_PORTE_DEN_R = 0XFF; // pin are digital
	//GPIO_PORTE_PUR_R = 0X11; //  pull up resistor
	
	SET_BIT(SYSCTL_RCGCGPIO_R, 3); //1.  or SYSCTL_RCGCGPIO_R |= 0x02; -> mask of port b (set portb to one to enable it's clock)
	delay = 1; // dummy peripheral or use the other way
	GPIO_PORTD_LOCK_R = 0X4C4F434B; // unlock portb
	GPIO_PORTD_CR_R = 0XFF; //commit register
	GPIO_PORTD_AFSEL_R = 0; //2. don't want an alternative function (GPIO MODE)
	GPIO_PORTD_PCTL_R = 0; // 3. don't want an alternative function
	GPIO_PORTD_AMSEL_R = 0; // 4. not in analog mode
	GPIO_PORTD_DIR_R = 0xFF; // pin are output
	GPIO_PORTD_DEN_R = 0XFF; // pin are digital
	//GPIO_PORTD_PUR_R = 0X11; //  pull up resistor
	
	SET_BIT(SYSCTL_RCGCGPIO_R, 5); //1.  or SYSCTL_RCGCGPIO_R |= 0x02; -> mask of port b (set portb to one to enable it's clock)
	delay = 1; // dummy peripheral or use the other way
	GPIO_PORTF_LOCK_R = 0X4C4F434B; // unlock portb
	GPIO_PORTF_CR_R = 0X0F; //commit register
	GPIO_PORTF_AFSEL_R = 0; //2. don't want an alternative function (GPIO MODE)
	GPIO_PORTF_PCTL_R = 0; // 3. don't want an alternative function
	GPIO_PORTF_AMSEL_R = 0; // 4. not in analog mode
	GPIO_PORTF_DIR_R = 0x0F; // pin are output
	GPIO_PORTF_DEN_R = 0X0F; // pin are digital
	//GPIO_PORTF_PUR_R = 0X11; //  pull up resistor


}
void SEVEN_SEGMENT_voidWriteNumber_1(int Number)
{
	switch (Number)
	{
		case 0 :
            GPIO_PORTB_DATA_R = 0XA0;
			break;
		case 1 :
            GPIO_PORTB_DATA_R = 0XF9;
			break;
		case 2 :
            GPIO_PORTB_DATA_R = 0XC4;
			break;
		case 3 :
            GPIO_PORTB_DATA_R = 0Xd0;
			break;
		case 4 :
            GPIO_PORTB_DATA_R = 0X99;
			break;
		case 5 :
            GPIO_PORTB_DATA_R = 0X92;
			break;
		case 6 :
            GPIO_PORTB_DATA_R = 0X82;
			break;
		case 7 :
            GPIO_PORTB_DATA_R = 0XF8;
			break;
		case 8 :
            GPIO_PORTB_DATA_R = 0X80;
			break;
		case 9 :
            GPIO_PORTB_DATA_R = 0X90;
			break;
	}
}
void SEVEN_SEGMENT_voidWriteNumber_2(int Number)
{
	switch (Number)
	{
		case 0 :
            GPIO_PORTE_DATA_R = 0X20;
            GPIO_PORTF_DATA_R = 0X02;
			break;
		case 1 :
            GPIO_PORTE_DATA_R = 0X39;
            GPIO_PORTF_DATA_R = 0X03;
			break;
		case 2 :
            GPIO_PORTE_DATA_R = 0X04;
            GPIO_PORTF_DATA_R = 0X03;
			break;
		case 3 :
            GPIO_PORTE_DATA_R = 0X10;
            GPIO_PORTF_DATA_R = 0X03;
			break;
		case 4 :
            GPIO_PORTE_DATA_R = 0X29;
            GPIO_PORTF_DATA_R = 0X02;
			break;
		case 5 :
            GPIO_PORTE_DATA_R = 0X22;
            GPIO_PORTF_DATA_R = 0X02;
			break;
		case 6 :
            GPIO_PORTE_DATA_R = 0X02;
            GPIO_PORTF_DATA_R = 0X02;
			break;
		case 7 :
            GPIO_PORTE_DATA_R = 0X38;
            GPIO_PORTF_DATA_R = 0X03;
			break;
		case 8 :
            GPIO_PORTE_DATA_R = 0X00;
            GPIO_PORTF_DATA_R = 0X02;
			break;
		case 9 :
            GPIO_PORTE_DATA_R = 0X10;
            GPIO_PORTF_DATA_R = 0X02;
			break;
	}
}
void SEVEN_SEGMENT_voidWriteNumber_3(int Number)
{
	switch (Number)
	{
		case 0 :
            GPIO_PORTE_DATA_R = 0X80;
            GPIO_PORTF_DATA_R = 0X08;
			break;
		case 1 :
            GPIO_PORTE_DATA_R = 0Xc9;
            GPIO_PORTF_DATA_R = 0X0c;
			break;
		case 2 :
            GPIO_PORTE_DATA_R = 0X04;
            GPIO_PORTF_DATA_R = 0X0c;
			break;
		case 3 :
            GPIO_PORTE_DATA_R = 0X40;
            GPIO_PORTF_DATA_R = 0X0c;
			break;
		case 4 :
            GPIO_PORTE_DATA_R = 0X49;
            GPIO_PORTF_DATA_R = 0X08;
			break;
		case 5 :
            GPIO_PORTE_DATA_R = 0X42;
            GPIO_PORTF_DATA_R = 0X08;
			break;
		case 6 :
            GPIO_PORTE_DATA_R = 0X02;
            GPIO_PORTF_DATA_R = 0X08;
			break;
		case 7 :
            GPIO_PORTE_DATA_R = 0Xc8;
            GPIO_PORTF_DATA_R = 0X0c;
			break;
		case 8 :
            GPIO_PORTE_DATA_R = 0X00;
            GPIO_PORTF_DATA_R = 0X08;
			break;
		case 9 :
            GPIO_PORTE_DATA_R = 0X40;
            GPIO_PORTF_DATA_R = 0X08;
			break;
	}
}

void SEVEN_SEGMENT_voidClearSegment(void)
{
	
    GPIO_PORTB_DATA_R = 0XFF;
    GPIO_PORTE_DATA_R = 0XFF;
    GPIO_PORTD_DATA_R = 0XFF;
    GPIO_PORTF_DATA_R = 0XFF;
}

