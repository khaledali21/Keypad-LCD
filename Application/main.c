/*
 * main.c
 *
 * Created: 1/22/2022 12:30:42 AM
 *  Author: Khaled Ali
 */ 

#include "../ECUAL/KEYPAD/KEYPAD.h"
#include "../ECUAL/LCD/LCD.h"
int main(void){
	KEYPAD_u8Init();
	LCD_u8Init();
	uint8_t key = 0;
	uint8_t counter = 0;
	while(1){
		KEYPAD_u8GetKey(&key);
		if(key != 0xFF){
			if(counter == 16){
				LCD_u8SetCursor(1, 0);
			}
			else if(counter == 32){
				counter = 0;
				LCD_u8SendCommand(LCD_CLEAR);
			}
			LCD_u8SendNumber(key);
			counter++;
		}
		TIMER0_u8PollingDelay(100);
	}
}