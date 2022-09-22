

#include "lcd.h"



void LCD_4bit_init ()
{
	DIO_init(EN,EN_PORT,OUT) ;
	DIO_init(RS,RS_PORT,OUT) ;
	DIO_init(RW,RW_PORT,OUT) ;
	DIO_init(D7,LCD_PORT,OUT) ;
	DIO_init(D6,LCD_PORT,OUT) ;
	DIO_init(D5,LCD_PORT,OUT) ;
	DIO_init(D4,LCD_PORT,OUT) ;

	_delay_ms(35);

	/*
	 * Function set:
	 *	DL = 1 : 8 bit interface operation
	 *	N = 0 : 1 - line display
	 *	F = 0 : 5 x 7 dot character font
	 */
	LCD_4bit_sendcmd (0x02);
	LCD_4bit_sendcmd (0x28); //0bNF00 --> 4bit Mode SELECTED
	_delay_us(40);

	//Display ON/OFF control
	LCD_4bit_sendcmd (0x00);
	LCD_4bit_sendcmd(Disp);
	_delay_us(40);

	LCD_4bit_sendcmd (0x00);
	LCD_4bit_sendcmd(CLRSc); // Clear Display screen
	_delay_ms(2);

	LCD_4bit_sendcmd(0x00);
	LCD_4bit_sendcmd(IncMode);
	_delay_us(40);
	
}

void LCD_4bit_sendcmd(uint8_t cmd)
{ 	DIO_write(RS,RS_PORT,LOW) ; // write 0 on RS to write command
	DIO_write(RW,RW_PORT,LOW) ; // write 0 on RW to write
	(GET_BIT(cmd,7)) ? DIO_write(D7,LCD_PORT,HIGH) : DIO_write(D7,LCD_PORT,LOW) ;
	(GET_BIT(cmd,6)) ? DIO_write(D6,LCD_PORT,HIGH) : DIO_write(D6,LCD_PORT,LOW) ;
	(GET_BIT(cmd,5)) ? DIO_write(D5,LCD_PORT,HIGH) : DIO_write(D5,LCD_PORT,LOW) ;
	(GET_BIT(cmd,4)) ? DIO_write(D4,LCD_PORT,HIGH) : DIO_write(D4,LCD_PORT,LOW) ;
	LCD_trig_EN() ;
	(GET_BIT(cmd,3)) ? DIO_write(D7,LCD_PORT,HIGH) : DIO_write(D7,LCD_PORT,LOW) ;
	(GET_BIT(cmd,2)) ? DIO_write(D6,LCD_PORT,HIGH) : DIO_write(D6,LCD_PORT,LOW) ;
	(GET_BIT(cmd,1)) ? DIO_write(D5,LCD_PORT,HIGH) : DIO_write(D5,LCD_PORT,LOW) ;
	(GET_BIT(cmd,0)) ? DIO_write(D4,LCD_PORT,HIGH) : DIO_write(D4,LCD_PORT,LOW) ;
		LCD_trig_EN() ;
}	
void LCD_4bit_sendchar(uint8_t Char)
{ 	DIO_write(RS,RS_PORT,HIGH) ; // write 1 on RS to write Data
	DIO_write(RW,RW_PORT,LOW) ; // write 0 on RW to write
	(GET_BIT(Char,7)) ? DIO_write(D7,LCD_PORT,HIGH) : DIO_write(D7,LCD_PORT,LOW) ;
	(GET_BIT(Char,6)) ? DIO_write(D6,LCD_PORT,HIGH) : DIO_write(D6,LCD_PORT,LOW) ;
	(GET_BIT(Char,5)) ? DIO_write(D5,LCD_PORT,HIGH) : DIO_write(D5,LCD_PORT,LOW) ;
	(GET_BIT(Char,4)) ? DIO_write(D4,LCD_PORT,HIGH) : DIO_write(D4,LCD_PORT,LOW) ;
	LCD_trig_EN() ;
	(GET_BIT(Char,3)) ? DIO_write(D7,LCD_PORT,HIGH) : DIO_write(D7,LCD_PORT,LOW) ;
	(GET_BIT(Char,2)) ? DIO_write(D6,LCD_PORT,HIGH) : DIO_write(D6,LCD_PORT,LOW) ;
	(GET_BIT(Char,1)) ? DIO_write(D5,LCD_PORT,HIGH) : DIO_write(D5,LCD_PORT,LOW) ;
	(GET_BIT(Char,0)) ? DIO_write(D4,LCD_PORT,HIGH) : DIO_write(D4,LCD_PORT,LOW) ;
	LCD_trig_EN() ;
}

void LCD_4bit_sendstring (uint8_t* string)
{
	while (*string !='\0')
	{
		LCD_4bit_sendchar(*string++) ;
	}
}

 void LCD_4bit_sendstring_x_y(uint8_t x , uint8_t y ,uint8_t* string)
 {
	  // x 0--->15
	  // y 0 -->1
 if (0==y)
	 LCD_4bit_sendcmd(0x80) ; // forces cursor to the first line
 else if (1==y)
	 LCD_4bit_sendcmd(0xC0) ; // forces cursor to second line
 else
	 LCD_4bit_sendstring("ERROR_OUT_RANGE") ;
if (x>15)
	 LCD_4bit_sendstring("ERROR_OUT_RANGE") ;
else
{		while (x)
	{ LCD_4bit_sendcmd(0x14) ;
		x-- ;
	}
	LCD_4bit_sendstring(string) ;
}

}


void LCD_4bit_clear()
{
LCD_4bit_sendcmd(CLRSc) ;
_delay_us(40) ;
}








void LCD_trig_EN(void)
{
	
	DIO_write(EN,EN_PORT,HIGH) ;
	_delay_us(10) ;
	DIO_write(EN,EN_PORT,LOW) ;
	
}

