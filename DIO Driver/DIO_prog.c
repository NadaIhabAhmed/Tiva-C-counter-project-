#include "tm4c123gh6pm.h"
#include "DIO_interface.h"


uint8_t DIO_ReadPort (uint8_t port_index, uint8_t pin_mask)
{
	switch(port_index)
	{
		case 0: //PORTA
			return GPIO_PORTA_DATA_R & pin_mask;
		
		case 1://PORTB
			return GPIO_PORTB_DATA_R & pin_mask;
	
		case 2://PORTC
			return GPIO_PORTC_DATA_R & pin_mask;
			
		case 3://PORTD
			return GPIO_PORTD_DATA_R & pin_mask;
			
		case 4://PORTE
			return GPIO_PORTE_DATA_R & pin_mask;
		
		case 5://PORTF
			return GPIO_PORTF_DATA_R & pin_mask;

	}
}

void DIO_WrirePort (uint8_t port_index, uint8_t pin_mask, level pins_level)
{
	switch(pins_level)
	{
		case STD_LOW: // make them low----------------CLEAR BITS
			if (port_index == 0){
				GPIO_PORTA_DATA_R &= ~(pin_mask);
			}
			else if(port_index == 1){
				GPIO_PORTB_DATA_R &= ~(pin_mask);
			}
			else if(port_index == 2){
				GPIO_PORTC_DATA_R &= ~(pin_mask);
			}
			else if(port_index == 3){
				GPIO_PORTD_DATA_R &= ~(pin_mask);
			}
			else if(port_index == 4){
				GPIO_PORTE_DATA_R &= ~(pin_mask);
			}
			else if(port_index == 5){
				GPIO_PORTF_DATA_R &= ~(pin_mask);
			}
			
		/*	switch(port_index)
			{
				case 0: //PORTA
					GPIO_PORTA_DATA_R &= ~(pin_mask);
				
				case 1://PORTB
					GPIO_PORTB_DATA_R &= ~(pin_mask);
			
				case 2://PORTC
					GPIO_PORTC_DATA_R &= ~(pin_mask);
					
				case 3://PORTD
					GPIO_PORTD_DATA_R &= ~(pin_mask);
					
				case 4://PORTE
					GPIO_PORTE_DATA_R &= ~(pin_mask);
				
				case 5://PORTF
					GPIO_PORTF_DATA_R &= ~(pin_mask);
		
			}	*/
			break;
		case STD_HIGH: // make them high--------------SET BITS
			if (port_index == 0){
				GPIO_PORTA_DATA_R |= pin_mask;
			}
			else if(port_index == 1){
				GPIO_PORTB_DATA_R |= pin_mask;
			}
			else if(port_index == 2){
				GPIO_PORTC_DATA_R |= pin_mask;
			}
			else if(port_index == 3){
				GPIO_PORTD_DATA_R |= pin_mask;
			}
			else if(port_index == 4){
				GPIO_PORTE_DATA_R |= pin_mask;
			}
			else if(port_index == 5){
				GPIO_PORTF_DATA_R |= pin_mask;
			}
			/*
			switch(port_index)
			{
				case 0: //PORTA
					GPIO_PORTA_DATA_R |= pin_mask;
					break;
				case 1://PORTB
					GPIO_PORTB_DATA_R |= pin_mask;
					break;
				case 2://PORTC
					GPIO_PORTC_DATA_R |= pin_mask;
					break;
				case 3://PORTD
					GPIO_PORTD_DATA_R |= pin_mask;
					break;
				case 4://PORTE
					GPIO_PORTE_DATA_R |= pin_mask;
					break;
				case 5://PORTF
					GPIO_PORTF_DATA_R |= pin_mask;
					break;
			}	*/
			break;
	}
	
}

void DIO_FlipPort (uint8_t port_index, uint8_t pin_mask)
{
	switch(port_index)//----------TOGGLE BITS
	{
		case 0: //PORTA
			GPIO_PORTA_DATA_R ^= pin_mask;
			break;
		case 1://PORTB
			GPIO_PORTB_DATA_R ^= pin_mask;
			break;
		case 2://PORTC
			GPIO_PORTC_DATA_R ^= pin_mask;
			break;
		case 3://PORTD
			GPIO_PORTD_DATA_R ^= pin_mask;
			break;
		case 4://PORTE
			GPIO_PORTE_DATA_R ^= pin_mask;
			break;
		case 5://PORTF
			GPIO_PORTF_DATA_R ^= pin_mask;
			break;
	}
}

