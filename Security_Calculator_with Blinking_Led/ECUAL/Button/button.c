/*
 * button.c
 *
 * Created: 8/27/2022 7:27:48 AM
 *  Author: mohamed
 */ 
#include "button.h"

void BUTTON_init(uint8_t ButtonPin , uint8_t ButtonPort)
{
	DIO_init(ButtonPin,ButtonPort,IN) ; // button is input device
}
void BUTTON_read(uint8_t ButtonPin , uint8_t ButtonPort,uint8_t*retrnstate)
{
	DIO_read(ButtonPin,ButtonPort,retrnstate) ;
}