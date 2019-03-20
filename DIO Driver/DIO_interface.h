#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include <stdint.h>

#define OUTPUT		1
#define INPUT		0

#define	HIGH		1
#define LOW			0

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define PORTE 4
#define PORTF 5

enum Dio_LevelType{
			STD_LOW, // 0
			STD_HIGH // 1
}level;

/*DIO_ReadPort: 
This function returns the value of the pins selected by pins_masks in the port selected by port_index 
(GET_BITS())
*/
uint8_t DIO_ReadPort (uint8_t port_index, uint8_t pin_mask); 
/*DIO_WritePort: 
This function Change the value of the pins selected by pins_masks in the port selected by port_index to input pins_level
(SET_BITS())
*/
void DIO_WrirePort (uint8_t port_index, uint8_t pin_mask, level pin_level);
/*DIO_FlipPort: 
This function Toggle the values of the pins selected by pins_masks in the port selected by port_index
(TOGGLE_BITS())
*/
void DIO_FlipPort (uint8_t port_index, uint8_t pin_mask);


#endif /* DIO_INTERFACE_H_ */
