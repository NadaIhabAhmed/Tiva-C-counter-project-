#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


#define MODE_8_BIT				0x38
#define DISPLAY_ON_CURSOR_OFF	0x0c
#define CLEAR_SCREEN			0x01

void LCD_voidInit(void);
void LCD_voidWriteCharacter(char Character);
void LCD_voidSendCommand(int Command);
void LCD_voidWriteString(char * String);

#endif /* LCD_INTERFACE_H_ */
