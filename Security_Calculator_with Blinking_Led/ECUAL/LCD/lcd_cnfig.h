/*
 * lcd_cnfig.h
 *  Author: mohamed
 */ 


#ifndef LCD_CNFIG_H_
		#define LCD_CNFIG_H_


#define RS  PIN_1 // PIN 7 in port A
#define RW  PIN_2   // PIN_6 in PORT A
#define EN  PIN_3 // PIN_5 in port A
#define EN_PORT  PORT_B
#define RW_PORT PORT_B
#define RS_PORT PORT_B
#define LCD_PORT PORT_A

#define D7  PIN_7
#define D6  PIN_6
#define D5  PIN_5
#define D4  PIN_4


// Initialization
/*
 * Display ON/OFF Control:
 *	D = 0 : Display OFF
 *	C = 0 : Cursor OFF
 *	B = 0 : Blink OFF
 */

#define Disp		0x0e //0b1DCB
#define CLRSc		0x01 // Clear Display screen

/*
 *	Entry Mode Set
 *	I/D = 1 : +1 (Increment Mode) (to Right)
 *	S = 0 : No Display Shift operation
 */
#define IncMode		0x06 // 0b 0 1 I/D SH
#define shift_curser_right  0x14
#define SECOND_LINE  0xC0
#define FIRST_LINE   0x80




#endif /* LCD_CNFIG_H_ */
