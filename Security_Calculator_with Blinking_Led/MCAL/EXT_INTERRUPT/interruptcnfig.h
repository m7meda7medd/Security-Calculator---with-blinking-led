/*
 * interruptcnfig.h
 *
 *  Created on: Sep 22, 2022
 *      Author: mohamed
 */

#ifndef MCAL_EXT_INTERRUPT_INTERRUPTCNFIG_H_
#define MCAL_EXT_INTERRUPT_INTERRUPTCNFIG_H_

#define DISABLE 0
#define ENABLE  1

#define EXT_INT0_MODE  ENABLE
#define EXT_INT1_MODE  DISABLE
#define EXT_INT2_MODE  DISABLE

#define LOW_LEVEL  0
#define ANY_LOGIC_CHANGE 1
#define FALLING_EDGE 2
#define RISING_EDGE 3


#define EXTINT0_SENSE_MODE 	RISING_EDGE
#define EXTINT1_SENSE_MODE 	ANY_LOGIC_CHANGE
#define EXTINT2_SENSE_MODE 	RISING_EDGE   // only can work in falling or rising edge

#define EXT_INT0  __vector_1
#define EXT_INT1  __vector_2
#define EXT_INT2  __vector_3

#define ISC00  0
#define ISC01  1
#define ISC10  2
#define ISC11  3
#define IS2   6
#define GICR_INT0  6
#define GICR_INT1  7
#define GICR_INT2  5
#define GIB  7

typedef enum
{ 	EXTI0,
	EXTI1,
	EXTI2


}EXTI_TYPES;




#endif /* MCAL_EXT_INTERRUPT_INTERRUPTCNFIG_H_ */
