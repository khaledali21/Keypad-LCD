/*
 * LCD.h
 *
 * Created: 1/17/2022 12:19:20 AM
 *  Author: Khaled Ali
 */

#ifndef LCD_H_
#define LCD_H_

#include "../../LIB/Typedef.h"
#include "LCD_cfg.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/TIMER/TIMER0.h"
#include "../../LIB/BIT_Math.h"

typedef enum{
	LCD_ERR,
	LCD_OK
}LCD_ERR_STATE;
LCD_ERR_STATE LCD_u8Init(void);

LCD_ERR_STATE LCD_u8SendCommand(uint8_t command);

LCD_ERR_STATE LCD_u8SendData(uint8_t data);
LCD_ERR_STATE LCD_u8SendNumber(uint16_t num);
LCD_ERR_STATE LCD_u8SendString(uint8_t *str);
LCD_ERR_STATE LCD_u8SetCursor(uint8_t row, uint8_t col);

#endif /* LCD_H_ */
