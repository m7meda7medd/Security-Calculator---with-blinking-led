/*
 * button.h

 *  Author: mohamed
 */ 


#ifndef BUTTON_H_
	#define BUTTON_H_

#include "../../MCAL/DIO/dio.h"
 
void BUTTON_init(uint8_t ButtonPin , uint8_t ButtonPort) ;

void BUTTON_read(uint8_t ButtonPin , uint8_t ButtonPort,uint8_t*retrnstate) ;





#endif /* BUTTON_H_ */