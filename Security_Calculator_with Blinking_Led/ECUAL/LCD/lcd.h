
#ifndef LCD_H
	#define LCD_H

#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/McalReg/Registers.h"
#include "../../MCAL/McalReg/Typedefs.h"
#include "lcd_cnfig.h"
#include <util/delay.h>




 // 4_bit func declaration
void LCD_4bit_init () ;
void LCD_4bit_sendcmd(uint8_t cmd) ;
void LCD_4bit_sendstring (uint8_t* string) ;
void LCD_4bit_sendstring_x_y(uint8_t x , uint8_t y ,uint8_t* string) ;
void LCD_4bit_sendchar(uint8_t Char) ;
void LCD_8bit_init () ;
// 8 bit func declaration
void LCD_8bit_cmd(uint8_t cmd) ;
void LCD_8bit_string (uint8_t* string) ;
void LCD_8bit_char(uint8_t Char) ;
 void LCD_trig_EN(void) ;
 void LCD_4bit_clear() ;




#endif // LCD_H
