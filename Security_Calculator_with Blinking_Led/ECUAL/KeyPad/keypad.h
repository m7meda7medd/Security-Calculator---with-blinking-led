/*
 * keypad.h
 *
 *  Created on: Sep 17, 2022
 *      Author: mohamed
 */

#ifndef ECUAL_KEYPAD_KEYPAD_H_
#define ECUAL_KEYPAD_KEYPAD_H_
#include "keypadcnfg.h"
#include <util/delay.h>
#include "../../MCAL/McalReg/Registers.h"
#include "../../MCAL/McalReg/Typedefs.h"
#include "../../MCAL/DIO/dio.h"

void KP_4x4_init() ;

uint8_t KP_4x4_check_press() ;




#endif /* ECUAL_KEYPAD_KEYPAD_H_ */
