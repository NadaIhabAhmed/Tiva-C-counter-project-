#include "tm4c123gh6pm.h"
#include "PORT_interface.h"
#include "macros.h"
#include "DIO_interface.h"

uint8_t delay;

void Port_Init(uint8_t port_index)
{
	switch(port_index)
	{
		case 0:
			SET_BIT(SYSCTL_RCGCGPIO_R, 0); //1.  or SYSCTL_RCGCGPIO_R |= 0x02; -> mask of port b (set portb to one to enable it's clock)
			delay = 1; // dummy peripheral or use the other way
			GPIO_PORTA_LOCK_R = 0X4C4F434B; // unlock portb
			GPIO_PORTA_CR_R = 0Xff; //commit register
			GPIO_PORTA_AFSEL_R = 0; //2. don't want an alternative function (GPIO MODE)
			GPIO_PORTA_PCTL_R = 0; // 3. don't want an alternative function
			GPIO_PORTA_AMSEL_R = 0; // 4. not in analog mode
			GPIO_PORTA_DEN_R = 0Xff; // pin are digital
			break;
		case 1:
			SET_BIT(SYSCTL_RCGCGPIO_R, 1);
			delay = 1; // dummy peripheral or use the other way
			GPIO_PORTB_LOCK_R = 0X4C4F434B; // unlock porta
			GPIO_PORTB_CR_R = 0XFF; //commit register
			GPIO_PORTB_AFSEL_R = 0; //2. don't want an alternative function (GPIO MODE)
			GPIO_PORTB_PCTL_R = 0; // 3. don't want an alternative function
			GPIO_PORTB_AMSEL_R = 0; // 4. not in analog mode
			GPIO_PORTB_DEN_R = 0XFF; // pin are digital
			break;
			
		case 2:
			SET_BIT(SYSCTL_RCGCGPIO_R, 2);
			delay = 1; // dummy peripheral or use the other way
			GPIO_PORTC_LOCK_R = 0X4C4F434B; // unlock porta
			GPIO_PORTC_CR_R = 0XFF; //commit register
			GPIO_PORTC_AFSEL_R = 0; //2. don't want an alternative function (GPIO MODE)
			GPIO_PORTC_PCTL_R = 0; // 3. don't want an alternative function
			GPIO_PORTC_AMSEL_R = 0; // 4. not in analog mode
			GPIO_PORTC_DEN_R = 0XFF; // pin are digital
			break;
		case 3:
			SET_BIT(SYSCTL_RCGCGPIO_R, 3);
			delay = 1; // dummy peripheral or use the other way
			GPIO_PORTD_LOCK_R = 0X4C4F434B; // unlock porta
			GPIO_PORTD_CR_R = 0XFF; //commit register
			GPIO_PORTD_AFSEL_R = 0; //2. don't want an alternative function (GPIO MODE)
			GPIO_PORTD_PCTL_R = 0; // 3. don't want an alternative function
			GPIO_PORTD_AMSEL_R = 0; // 4. not in analog mode
			GPIO_PORTD_DEN_R = 0XFF; // pin are digital
			break;
		case 4:
			SET_BIT(SYSCTL_RCGCGPIO_R, 4);
			delay = 1; // dummy peripheral or use the other way
			GPIO_PORTE_LOCK_R = 0X4C4F434B; // unlock porta
			GPIO_PORTE_CR_R = 0XFF; //commit register
			GPIO_PORTE_AFSEL_R = 0; //2. don't want an alternative function (GPIO MODE)
			GPIO_PORTE_PCTL_R = 0; // 3. don't want an alternative function
			GPIO_PORTE_AMSEL_R = 0; // 4. not in analog mode
			GPIO_PORTE_DEN_R = 0XFF; // pin are digital
			break;
		case 5:
			SET_BIT(SYSCTL_RCGCGPIO_R, 5);
			delay = 1; // dummy peripheral or use the other way
			GPIO_PORTF_LOCK_R = 0X4C4F434B; // unlock porta
			GPIO_PORTF_CR_R = 0XFF; //commit register
			GPIO_PORTF_AFSEL_R = 0; //2. don't want an alternative function (GPIO MODE)
			GPIO_PORTF_PCTL_R = 0; // 3. don't want an alternative function
			GPIO_PORTF_AMSEL_R = 0; // 4. not in analog mode
			GPIO_PORTF_DEN_R = 0XFF; // pin are digital
			break;
	}
}

void Port_SetPinDirection(uint8_t port_index, uint8_t pin_mask, dir pins_direction)
{
	switch(pins_direction)
	{
		case PORT_PIN_IN : // -----------------INPUT
			switch(port_index)
			{
				case 0: //PORTA
					GPIO_PORTA_DIR_R &= (~pin_mask);
				
				case 1://PORTB
					GPIO_PORTB_DIR_R &= (~pin_mask);
			
				case 2://PORTC
					GPIO_PORTC_DIR_R &= (~pin_mask);
					
				case 3://PORTD
					GPIO_PORTD_DIR_R &= (~pin_mask);
					
				case 4://PORTE
					GPIO_PORTE_DIR_R &= (~pin_mask);
				
				case 5://PORTF
					GPIO_PORTF_DIR_R &= (~pin_mask);
		
			}	
			break;
		case PORT_PIN_OUT : // ----------------------OUTPUT
			switch(port_index)
			{
				case 0: //PORTA
					GPIO_PORTA_DIR_R |= pin_mask;
					break;
				case 1://PORTB
					GPIO_PORTB_DIR_R |= pin_mask;
					break;
				case 2://PORTC
					GPIO_PORTC_DIR_R |= pin_mask;
					break;
				case 3://PORTD
					GPIO_PORTD_DIR_R |= pin_mask;
					break;
				case 4://PORTE
					GPIO_PORTE_DIR_R |= pin_mask;
					break;
				case 5://PORTF
					GPIO_PORTF_DIR_R |= pin_mask;
					break;
			}	
			break;
		}
}

void Port_SetPinPullUp(uint8_t port_index, uint8_t pin_mask, uint8_t enable)
{
	switch(enable)
	{
		case 0: // -----------------DISABLE
			switch(port_index)
			{
				case 0: //PORTA
					GPIO_PORTA_PUR_R &= (~pin_mask);
				
				case 1://PORTB
					GPIO_PORTB_PUR_R &= (~pin_mask);
			
				case 2://PORTC
					GPIO_PORTC_PUR_R &= (~pin_mask);
					
				case 3://PORTD
					GPIO_PORTD_PUR_R &= (~pin_mask);
					
				case 4://PORTE
					GPIO_PORTE_PUR_R &= (~pin_mask);
				
				case 5://PORTF
					GPIO_PORTF_PUR_R &= (~pin_mask);
		
			}	
			break;
		case 1: // ----------------------ENABLE
			switch(port_index)
			{
				case 0: //PORTA
					GPIO_PORTA_PUR_R |= pin_mask;
					break;
				case 1://PORTB
					GPIO_PORTB_PUR_R |= pin_mask;
					break;
				case 2://PORTC
					GPIO_PORTC_PUR_R |= pin_mask;
					break;
				case 3://PORTD
					GPIO_PORTD_PUR_R |= pin_mask;
					break;
				case 4://PORTE
					GPIO_PORTE_PUR_R |= pin_mask;
					break;
				case 5://PORTF
					GPIO_PORTF_PUR_R |= pin_mask;
					break;
			}	
			break;
		}

}
void Port_SetPinPullDown(uint8_t port_index, uint8_t pin_mask, uint8_t enable)
{
	switch(enable)
	{
		case 0: // -----------------DISABLE
			switch(port_index)
			{
				case 0: //PORTA
					GPIO_PORTA_PDR_R &= (~pin_mask);
				
				case 1://PORTB
					GPIO_PORTB_PDR_R &= (~pin_mask);
			
				case 2://PORTC
					GPIO_PORTC_PDR_R &= (~pin_mask);
					
				case 3://PORTD
					GPIO_PORTD_PDR_R &= (~pin_mask);
					
				case 4://PORTE
					GPIO_PORTE_PDR_R &= (~pin_mask);
				
				case 5://PORTF
					GPIO_PORTF_PDR_R &= (~pin_mask);
		
			}	
			break;
		case 1: // ----------------------ENABLE
			switch(port_index)
			{
				case 0: //PORTA
					GPIO_PORTA_PDR_R |= pin_mask;
					break;
				case 1://PORTB
					GPIO_PORTB_PDR_R |= pin_mask;
					break;
				case 2://PORTC
					GPIO_PORTC_PDR_R |= pin_mask;
					break;
				case 3://PORTD
					GPIO_PORTD_PDR_R |= pin_mask;
					break;
				case 4://PORTE
					GPIO_PORTE_PDR_R |= pin_mask;
					break;
				case 5://PORTF
					GPIO_PORTF_PDR_R |= pin_mask;
					break;
			}	
			break;
		}	
}
