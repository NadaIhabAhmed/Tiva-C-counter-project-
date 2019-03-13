#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

//control pins
#define EN_PORT PORTA//Enable (latch wait for data arrival)
#define RW_PORT PORTA// read -> 1 / write -> 0
#define RS_PORT PORTA//Register selector (data or command)

#define EN_PIN PA5//Enable (latch wait for data arrival)
#define RW_PIN PA6// read -> 1 / write -> 0
#define RS_PIN PA7//Register selector (data or command)

//Data pins
#define D0_PORT PORTB
#define D1_PORT PORTB
#define D2_PORT PORTB
#define D3_PORT PORTB
#define D4_PORT PORTB
#define D5_PORT PORTB
#define D6_PORT PORTB
#define D7_PORT PORTB

#define D0_PIN PB0
#define D1_PIN PB1
#define D2_PIN PB2
#define D3_PIN PB3
#define D4_PIN PB4
#define D5_PIN PB5
#define D6_PIN PB6
#define D7_PIN PB7


#endif /* LCD_CONFIG_H_ */