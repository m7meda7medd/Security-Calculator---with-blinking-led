/*
 * dio.h
 *

 *  Author: mohamed
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../McalReg/Registers.h"
#include "../McalReg/Typedefs.h"


	// Direction Defines Enum
enum Value{
	LOW, HIGH
	};
	// Value Defines Enum
enum  State {
	IN , OUT, IN_PULLUP_ON
	};
	// PORTS DEFINES MACROS
#define  PORT_A  'A'
#define  PORT_B  'B'
#define  PORT_C  'C'
#define  PORT_D  'D'


	// Function Declarations 
void DIO_init(uint8_t PinNumber , uint8_t PORTNO , uint8_t Direction) ; 
void DIO_write(uint8_t PinNumber , uint8_t PORTNO , uint8_t Value) ;
void DIO_toggle(uint8_t PinNumber , uint8_t PORTNO ) ;
void DIO_read(uint8_t PinNumber , uint8_t PORTNO , uint8_t*ptr) ;
enum Value DIO_returnbit(uint8_t PinNumber , uint8_t PORTNO) ;

// pins enums
typedef enum PINS
{	PIN_0 ,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7
}PINS;



#endif /* DIO_H_ */
