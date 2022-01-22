/*
 * LCD.c
 *
 * Created: 1/17/2022 12:19:06 AM
 *  Author: Khaled Ali
 */

#include "LCD.h"
/*
* brief: This function is used to initialize pin directions of the LCD as defined in the configurations and in 4-Bit Mode
* return: (output) the Error state of the function 0 if an error happens and 1 otherwise
*/
LCD_ERR_STATE LCD_u8Init(void) {
	LCD_ERR_STATE state = LCD_OK;
	state = DIO_u8SetPinDirection(RS_PORT, RS_PIN, OUTPUT_PIN);
	if(state == LCD_OK){
		state = DIO_u8SetPinDirection(RW_PORT, RW_PIN, OUTPUT_PIN);
	}
	if(state == LCD_OK){
		state = DIO_u8SetPinDirection(E_PORT, E_PIN, OUTPUT_PIN);
	}
	if(state == LCD_OK){
		state = DIO_u8SetPinDirection(D4_PORT, D4_PIN, OUTPUT_PIN);
	}
	if(state == LCD_OK){
		state = DIO_u8SetPinDirection(D4_PORT, D5_PIN, OUTPUT_PIN);
	}
	if(state == LCD_OK){
		state = DIO_u8SetPinDirection(D4_PORT, D6_PIN, OUTPUT_PIN);
	}
	if(state == LCD_OK){
		state = DIO_u8SetPinDirection(D4_PORT, D7_PIN, OUTPUT_PIN);
	}

	if(state == LCD_OK){
		state = LCD_u8SendCommand(0x33);
	}

	if(state == LCD_OK){
		state = LCD_u8SendCommand(0x32);
	}
	if(state == LCD_OK){
		state = LCD_u8SendCommand(LCD_4BIT_MODE);
	}
	if(state == LCD_OK){
		state = LCD_u8SendCommand(LCD_DISPLAY_ON);
	}
	if(state == LCD_OK){
		state = LCD_u8SendCommand(LCD_SHIFT_CURSOR_RIGHT);
	}
	if(state == LCD_OK){
		state = LCD_u8SendCommand(LCD_CLEAR);
	}

	return state;

}
/*
* brief: This function is used to send a command to the LCD
* param.: (input) the command to be sent
* return: (output) the Error state of the function 0 if an error happens and 1 otherwise
*/
LCD_ERR_STATE LCD_u8SendCommand(uint8_t command){
	LCD_ERR_STATE state = LCD_OK;	
	uint8_t bit = GET_BIT(command, 4);
	state = DIO_u8SetPinData(D4_PORT,D4_PIN,bit);
	if(state == LCD_OK){
		bit = GET_BIT(command, 5);
		state = DIO_u8SetPinData(D5_PORT,D5_PIN,bit);
	}

	if(state == LCD_OK){
		bit = GET_BIT(command, 6);
		DIO_u8SetPinData(D6_PORT,D6_PIN,bit);
	}
	if(state == LCD_OK){
		bit = GET_BIT(command, 7);
		DIO_u8SetPinData(D7_PORT,D7_PIN,bit);
	}
	if(state == LCD_OK){
		state = DIO_u8SetPinData(RS_PORT,RS_PIN,LOW);
	}
	if(state == LCD_OK){
		state = DIO_u8SetPinData(RW_PORT,RW_PIN,LOW);
	}
	if(state == LCD_OK){
		state = DIO_u8SetPinData(E_PORT,E_PIN,HIGH);
	}

	if(state == LCD_OK){
		TIMER0_u8PollingDelay(2);
		state = DIO_u8SetPinData(E_PORT,E_PIN,LOW);
	}

	if(state == LCD_OK){
		bit = GET_BIT(command, 0);
		state = DIO_u8SetPinData(D4_PORT,D4_PIN,bit);
	}
	if(state == LCD_OK){
		bit = GET_BIT(command, 1);
		DIO_u8SetPinData(D5_PORT,D5_PIN,bit);
	}
	if(state == LCD_OK){
		bit = GET_BIT(command, 2);
		DIO_u8SetPinData(D6_PORT,D6_PIN,bit);
	}
	if(state == LCD_OK){
		bit = GET_BIT(command, 3);
		DIO_u8SetPinData(D7_PORT,D7_PIN,bit);
	}
	if(state == LCD_OK){
		state = DIO_u8SetPinData(RS_PORT,RS_PIN,LOW);
	}
	if(state == LCD_OK){
		state = DIO_u8SetPinData(RW_PORT,RW_PIN,LOW);
	}
	if(state == LCD_OK){
		state = DIO_u8SetPinData(E_PORT,E_PIN,HIGH);
	}
	if(state == LCD_OK){
		TIMER0_u8PollingDelay(2);
		state = DIO_u8SetPinData(E_PORT,E_PIN,LOW);
	}
	if(state == LCD_OK){
		state = TIMER0_u8PollingDelay(5);	
	}
	return state;
}
/*
* brief: This function is used to send a data character to he LCD
* param.: (input) the data to be sent 
* return: (output) the Error state of the function 0 if an error happens and 1 otherwise
*/
LCD_ERR_STATE LCD_u8SendData(uint8_t data) {

	LCD_ERR_STATE state = LCD_OK;
	uint8_t bit = GET_BIT(data, 4);
	state = DIO_u8SetPinData(D4_PORT,D4_PIN,bit);
	if(state == LCD_OK){
		bit = GET_BIT(data, 5);
		state = DIO_u8SetPinData(D5_PORT,D5_PIN,bit);
	}
	if(state == LCD_OK){
		bit = GET_BIT(data, 6);
		DIO_u8SetPinData(D6_PORT,D6_PIN,bit);
	}
	if(state == LCD_OK){
		bit = GET_BIT(data, 7);
		DIO_u8SetPinData(D7_PORT,D7_PIN,bit);
	}
	if(state == LCD_OK){
		state = DIO_u8SetPinData(RS_PORT,RS_PIN,HIGH);
	}
	if(state == LCD_OK){
		state = DIO_u8SetPinData(RW_PORT,RW_PIN,LOW);
	}
	if(state == LCD_OK){
		state = DIO_u8SetPinData(E_PORT,E_PIN,HIGH);
	}
	if(state == LCD_OK){
		TIMER0_u8PollingDelay(2);
		state = DIO_u8SetPinData(E_PORT,E_PIN,LOW);
	}

	if(state == LCD_OK){
		bit = GET_BIT(data, 0);
		state = DIO_u8SetPinData(D4_PORT,D4_PIN,bit);
	}
	if(state == LCD_OK){
		bit = GET_BIT(data, 1);
		DIO_u8SetPinData(D5_PORT,D5_PIN,bit);
	}
	if(state == LCD_OK){
		bit = GET_BIT(data, 2);
		DIO_u8SetPinData(D6_PORT,D6_PIN,bit);
	}
	if(state == LCD_OK){
		bit = GET_BIT(data, 3);
		DIO_u8SetPinData(D7_PORT,D7_PIN,bit);
	}
	if(state == LCD_OK){
		state = DIO_u8SetPinData(RS_PORT,RS_PIN,HIGH);
	}
	if(state == LCD_OK){
		state = DIO_u8SetPinData(RW_PORT,RW_PIN,LOW);
	}
	if(state == LCD_OK){
		state = DIO_u8SetPinData(E_PORT,E_PIN,HIGH);
	}
	if(state == LCD_OK){
		TIMER0_u8PollingDelay(2);
		state = DIO_u8SetPinData(E_PORT,E_PIN,LOW);
	}
	state = TIMER0_u8PollingDelay(5);
	return state;

}

/*
* brief: This function is used to send a string to the LCD
* param.: (input) a pointer to char pointing to the string
* return: (output) the Error state of the function 0 if an error happens and 1 otherwise
*/
LCD_ERR_STATE LCD_u8SendString(uint8_t *str){
	LCD_ERR_STATE state = LCD_OK;
	if(str == NULL){
		state = LCD_ERR;
	}
	else{
		uint8_t* iterator = str;
		while(*iterator != '\0' && state == LCD_OK){
			state = LCD_u8SendData(*iterator);
			state = TIMER0_u8PollingDelay(1);
			iterator++;
		}	
	}
	return state;

}
/*
* brief: This function is used to send a positive integer to the LCD
* param.: (input) the integer to be sent
* return: (output) the Error state of the function 0 if an error happens and 1 otherwise
*/
LCD_ERR_STATE LCD_u8SendNumber(uint16_t num)
{
	LCD_ERR_STATE state = LCD_OK;
	uint16_t y = 1;
	do{
		y = (y * 10) + (num % 10);
		num = num /10;
	}while(num > 0);
	
	while(y>1 && state == LCD_OK)
	{
		state = LCD_u8SendData((y%10)+48);
		y=y/10;
	}
	return state;
}
/*
* brief: This function is used to set the cursor at a certain position on the Display
* param.: (input) the row to set the cursor at, should be 0 or 1
* param.: (input) the column to set the cursor at, should be an integer between 0 and 15
* return: (output) the Error state of the function 0 if an error happens and 1 otherwise
*/
LCD_ERR_STATE LCD_u8SetCursor(uint8_t row, uint8_t col)
{	uint8_t state = LCD_OK;
	if(col > 15){
		state = LCD_ERR;
	}
	else{
		switch (row)
		{
			case 0:
			col |= 0x80;
			break;
			case 1:
			col |= 0xC0;
			break;
			default:
			state = LCD_ERR;
			break;
		}
	}
	if(state == LCD_OK){
		state = LCD_u8SendCommand(col);
	}
	return state;
}
