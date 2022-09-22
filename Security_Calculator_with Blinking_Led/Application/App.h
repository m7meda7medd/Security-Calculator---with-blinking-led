#ifndef APP_H
	#define APP_H

#include "../ECUAL/LED/led.h"
#include "../ECUAL/KeyPad/keypad.h"
#include "../ECUAL/LCD/lcd.h"
#include <stdio.h>
#include <util/delay.h>
#include "../MCAL/EXT_INTERRUPT/interrupt.h"


#define CALC_MODE 1
#define LED_BLINK_MODE 2
void APP_init () ;
void APP_start () ;
 // helping functions

void check_pass() ;
void calculator_mode() ;
void locked_press() ;
#endif // APP_H
