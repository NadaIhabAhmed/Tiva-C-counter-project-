#ifndef SEVEN_SEGMENT_CONFIG_H_
#define SEVEN_SEGMENT_CONFIG_H_

//these SEVEN_SEGMENTS are COMMON ANODE
//RSS stands for RIGHT_SEVEN_SEGMENT

#define SS0_PORT GPIO_PORTB_DATA_R
#define SS1_PORT GPIO_PORTB_DATA_R
#define SS2_PORT GPIO_PORTB_DATA_R
#define SS3_PORT GPIO_PORTB_DATA_R
#define SS4_PORT GPIO_PORTB_DATA_R
#define SS5_PORT GPIO_PORTB_DATA_R
#define SS6_PORT GPIO_PORTB_DATA_R
//common --> always high
#define SS7_PORT GPIO_PORTB_DATA_R

#define SS0_PIN PB0
#define SS1_PIN PB1
#define SS2_PIN PB2
#define SS3_PIN PB3
#define SS4_PIN PB4
#define SS5_PIN PB5
#define SS6_PIN PB6
//common --> always high
#define SS7_PIN PB7


#endif /* RIGHT_SEVEN_SEGMENT_CONFIG_H_ */