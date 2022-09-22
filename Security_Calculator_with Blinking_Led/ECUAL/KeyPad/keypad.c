 /*
 * keypad.c
 *
 *  Created on: Sep 17, 2022
 *      Author: mohamed
 */
#include "keypad.h"

static uint8_t KP_MapArr [4][4] = {
		{'7','8','9','/'},
		{'4','5','6','*'},
		{'1','2','3','-'},
		{'C','0','=','+'}
} ;


void KP_4x4_init()
{	DIO_init(OUT_A,KP_PORT,OUT) ;
	DIO_init(OUT_B,KP_PORT,OUT) ;
	DIO_init(OUT_C,KP_PORT,OUT) ;
	DIO_init(OUT_D,KP_PORT,OUT) ;
	DIO_init(IN_1,KP_PORT,IN_PULLUP_ON) ;
	DIO_init(IN_2,KP_PORT,IN_PULLUP_ON) ;
	DIO_init(IN_3,KP_PORT,IN_PULLUP_ON) ;
	DIO_init(IN_4,KP_PORT,IN_PULLUP_ON) ;
}


uint8_t KP_4x4_check_press()
{
	uint8_t i , j ;
	DIO_write(OUT_A,KP_PORT,HIGH) ;
	DIO_write(OUT_B,KP_PORT,HIGH) ;
	DIO_write(OUT_C,KP_PORT,HIGH) ;
	DIO_write(OUT_D,KP_PORT,HIGH) ;
	_delay_ms(10) ;
		for (i = OUT_A ; i<=OUT_D ; i++)
		{		DIO_write(i,KP_PORT,LOW) ;
			for (j =IN_1 ; j<=IN_4 ; j++)
			{
				if (!DIO_returnbit(j,KP_PORT))
				{
					return (KP_MapArr[i][j-4]) ;
				}

			}
			DIO_write(i,KP_PORT,HIGH) ;
		}
return (KP_NOTPRESSED) ;
}

