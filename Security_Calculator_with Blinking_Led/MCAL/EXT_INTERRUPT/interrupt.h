/*
 * interrupt.h
 *
 *  Created on: Sep 22, 2022
 *      Author: mohamed
 */

#ifndef MCAL_EXT_INTERRUPT_INTERRUPT_H_
#define MCAL_EXT_INTERRUPT_INTERRUPT_H_

#include "interruptcnfig.h"
#include "../McalReg/Registers.h"
#include "../McalReg/Typedefs.h"

extern volatile uint8_t C_flag ;
extern volatile uint8_t passed ;
#define ISR(INT_VECT) void INT_VECT(void)__attribute__((signal,used))  ; \
void INT_VECT(void)


void EXTINT_init(void) ;
void EXTINT_enable(EXTI_TYPES interrupt) ;
void EXTINT_disable(EXTI_TYPES interrupt) ;
void SET_CALLBACK_INT0(void (*p2f)(void)) ; // functions to execute functions from higher layer using interrupt in App layer
void SET_CALLBACK_INT1(void (*p2f)(void)) ;
void SET_CALLBACK_INT2(void (*p2f)(void)) ;


#endif /* MCAL_EXT_INTERRUPT_INTERRUPT_H_ */
