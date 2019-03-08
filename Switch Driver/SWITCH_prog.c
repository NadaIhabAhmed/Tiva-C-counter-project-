#include "SWITCH_interface.h"
#include "SWITCH_config.h"
//#include "BITS.h"
#include "tm4c123gh6pm.h"
#include "stdint.h"
#include "macros.h"

void SWITCH_voidInit(void)
{
  uint32_t delay;
	SET_BIT(SYSCTL_RCGCGPIO_R, 0); //1.  or SYSCTL_RCGCGPIO_R |= 0x01; -> mask of port a (set porta to one to enable it's clock)
	delay = 1; // dummy peripheral or use the other way
	GPIO_PORTA_LOCK_R = 0X4C4F434B; // unlock porta
	GPIO_PORTA_CR_R |= 0X7c; //commit register (here i'm oring so that i'm setting just one bit without affecting the other bits)
	GPIO_PORTA_AFSEL_R = 0; //2. don't want an alternative function (GPIO MODE)
	GPIO_PORTA_PCTL_R = 0; // 3. don't want an alternative function
	GPIO_PORTA_AMSEL_R = 0; // 4. not in analog mode
	GPIO_PORTA_DIR_R |= 0x00; // pin are output 00000000
	GPIO_PORTA_DEN_R |= 0X7c; // pin are digital 00000100
	GPIO_PORTA_PUR_R = 0X7c; //  pull up resistor 00000100
}



