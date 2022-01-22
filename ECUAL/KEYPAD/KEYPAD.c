/*
 * KEYPAD.c
 *
 * Created: 1/22/2022 1:31:39 AM
 *  Author: Khaled Ali
 */ 

#include "KEYPAD.h"


const static uint8_t KEYPAD[KEYPAD_ROWS][KEYPAD_COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
KEYPAD_ERR_STATE KEYPAD_u8Init(void){
	KEYPAD_ERR_STATE state = KEYPAD_OK;
	//Set Cols direction output
	state = DIO_u8SetPinDirection(COL0_PORT, COL0_PIN, OUTPUT_PIN);
	if(state == KEYPAD_OK){
		state = DIO_u8SetPinDirection(COL1_PORT, COL1_PIN, OUTPUT_PIN);	
	}
	if(state == KEYPAD_OK){
		state = DIO_u8SetPinDirection(COL2_PORT, COL2_PIN, OUTPUT_PIN);
	}
	
	//Set Cols high
	if(state == KEYPAD_OK){
		state = DIO_u8SetPinData(COL0_PORT, COL0_PIN, HIGH);
	}
	if(state == KEYPAD_OK){
		state = DIO_u8SetPinData(COL1_PORT, COL1_PIN, HIGH);
	}
	if(state == KEYPAD_OK){
		state = DIO_u8SetPinData(COL2_PORT, COL2_PIN, HIGH);
	}
	
	//Set rows direction input with pullup
	if(state == KEYPAD_OK){
		state = DIO_u8SetPinDirection(ROW0_PORT, ROW0_PIN, INPUT_PIN_PULLUP);
	}
	if(state == KEYPAD_OK){
		state = DIO_u8SetPinDirection(ROW1_PORT, ROW1_PIN, INPUT_PIN_PULLUP);
	}
	if(state == KEYPAD_OK){
		state = DIO_u8SetPinDirection(ROW2_PORT, ROW2_PIN, INPUT_PIN_PULLUP);
	}
	
	return state;
}

KEYPAD_ERR_STATE KEYPAD_u8GetKey(uint8_t* key){
	KEYPAD_ERR_STATE state = KEYPAD_OK;
	if(key == NULL){
		state = KEYPAD_ERR;
	}
	else{
		uint8_t pin;
		uint8_t acquired = 0;
		*key = 0xFF;
		for(uint8_t col = 0; col < KEYPAD_COLS; col++){
			switch(col){
				case  0:
					state = DIO_u8SetPinData(COL0_PORT, COL0_PIN, LOW);
					break;
				case 1:
					state = DIO_u8SetPinData(COL1_PORT, COL1_PIN, LOW);
					break;
				case 2:
					state = DIO_u8SetPinData(COL2_PORT, COL2_PIN, LOW);
					break;
				default:
					break;
			}
			if(state != KEYPAD_OK){
				break;
			}
			for(uint8_t row = 0; row < KEYPAD_ROWS; row++){
				switch(row){
					case  0:
						state = DIO_u8GetPinData(ROW0_PORT, ROW0_PIN, &pin);
						break;
					case 1:
						state = DIO_u8GetPinData(ROW1_PORT, ROW1_PIN, &pin);
						break;
					case 2:
						state = DIO_u8GetPinData(ROW2_PORT, ROW2_PIN, &pin);
						break;
					default:
						break;
				}
				if(pin == LOW){
					*key = KEYPAD[row][col];
					acquired = 1;
					TIMER0_u8PollingDelay(10);
				}
			}
			switch(col){
				case  0:
				state = DIO_u8SetPinData(COL0_PORT, COL0_PIN, HIGH);
				break;
				case 1:
				state = DIO_u8SetPinData(COL1_PORT, COL1_PIN, HIGH);
				break;
				case 2:
				state = DIO_u8SetPinData(COL2_PORT, COL2_PIN, HIGH);
				break;
				default:
				break;
			}
		}
	}
	return state;
}