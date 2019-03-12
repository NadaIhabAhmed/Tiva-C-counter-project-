#ifndef PORT_INTERFACE_H_
#define PORT_INTERFACE_H_
#include <stdint.h>

enum Port_PinDirectionType{
			PORT_PIN_IN,
			PORT_PIN_OUT
};
/*Port_Init:
Initialize port based on selected port_index (0 to 5) by enabling the clock, unlocking the port, and making the selected mode digital
*/
void Port_Init(uint8_t port_index);

/* Port_SetPinDirection:
Change the direction of the selected pins by pins_mask in the port selected by port_index
*/
void Port_SetPinDirection(uint8_t port_index, uint8_t pins_mask, uint8_t pins_direction);
/*Port_SetPinPullUp:
If enable is 1, the selected pins by pins_mask in the port selected by port_index will beconnected to internal pull-up resistor.
If enable is 0, the selected pins by pins_mask in the port selected by port_index will be not be connected to internal pull-up resistor.
*/
void Port_SetPinPullUp(uint8_t port_index, uint8_t pins_mask, uint8_t enable);
/*Port_SetPinPullDown:
If enable is 1, the selected pins by pins_mask in the port selected by port_index will be connected to internal pull-down resistor.
If enable is 0, the selected pins by pins_mask in the port selected by port_index will be not be connected to internal pull-down resistor.
*/
void Port_SetPinPullDown(uint8_t port_index, uint8_t pins_mask, uint8_t enable);

#endif
