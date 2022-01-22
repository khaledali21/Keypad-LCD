/*
 * KEYPAD.h
 *
 * Created: 1/22/2022 1:31:51 AM
 *  Author: Khaled Ali
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "../../LIB/Typedef.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/TIMER/TIMER0.h"
#include "KEYPAD_cfg.h"

typedef enum{
	KEYPAD_ERR,
	KEYPAD_OK
}KEYPAD_ERR_STATE;


KEYPAD_ERR_STATE KEYPAD_u8Init(void);

KEYPAD_ERR_STATE KEYPAD_u8GetKey(uint8_t* key);	
#endif /* KEYPAD_H_ */