/*
 * CFile1.c
 *  Author: mohamed
 */ 
#include"dio.h"



// DIO INIT IMPLEMENTATION

void DIO_init(uint8_t PinNumber , uint8_t PORTNO , uint8_t Direction)
{
	switch (PORTNO)
{		
 case PORT_A :
 { if (Direction == IN || Direction==IN_PULLUP_ON)
	 {
		CLR_BIT(DDRA,PinNumber) ;
		if (Direction == IN_PULLUP_ON)
		{
			SET_BIT(PORTA,PinNumber) ;
		}
		 
	 }
	 else if (Direction == OUT)
	 {
		SET_BIT(DDRA,PinNumber) ;
	 }
	 else {
		 // error handling
	 }
	 break ;
 	}
	 case PORT_B:
	 {  if (Direction == IN || Direction==IN_PULLUP_ON)
	 {
		CLR_BIT(DDRB,PinNumber) ;
		if (Direction == IN_PULLUP_ON)
		{
			SET_BIT(PORTB,PinNumber) ;
		}

	 }
		 else if (Direction == OUT)
		 {
			 SET_BIT(DDRB,PinNumber) ;
		 }
		 else {
			 // error handling
		 }
		 break ;
	 }	
 case PORT_C :
 {  if (Direction == IN || Direction==IN_PULLUP_ON)
 	 {
	 	 CLR_BIT(DDRC,PinNumber) ;
	 	 if (Direction == IN_PULLUP_ON)
	 	 {
	 		 SET_BIT(PORTC,PinNumber) ;
	 	 }

 	 }
	 else if (Direction == OUT)
	 {
		 SET_BIT(DDRC,PinNumber) ;
	 }
	 else {
		 // error handling
	 }
	 break ;
 }
  case PORT_D :
  {  if (Direction == IN || Direction==IN_PULLUP_ON)
	 {
			CLR_BIT(DDRD,PinNumber) ;
		if (Direction == IN_PULLUP_ON)
		{
			SET_BIT(PORTD,PinNumber) ;
		}

	 }
	  else if (Direction == OUT)
	  {
		  SET_BIT(DDRD,PinNumber) ;
	  }
	  else {
		  // error handling
	  }
	  break ;
  }
}
		
}
// DIO WRITE IMPLEMENTATION

void DIO_write(uint8_t PinNumber , uint8_t PORTNO , uint8_t Value)
{
	
	switch (PORTNO)
	{
		case PORT_A :
		{ if (Value == LOW)
			{
				CLR_BIT(PORTA,PinNumber)  ;
				
			}
			else if (Value == HIGH)
			{
				SET_BIT(PORTA,PinNumber) ;
			}
			else {
				// error handling
			}
			break ;
		}
		case PORT_B:
		{ if (Value == LOW)
			{
				CLR_BIT(PORTB,PinNumber) ;
				
			}
			else if (Value == HIGH)
			{
				SET_BIT(PORTB,PinNumber) ;
			}
			else {
				// error handling
			}
			break ;
		}
		
		case PORT_C :
		{ if (Value == LOW)
			{
				CLR_BIT(PORTC,PinNumber) ;
				
			}
			else if (Value == HIGH)
			{
				SET_BIT(PORTC,PinNumber) ;
			}
			else {
				// error handling
			}
			break ;
		}
		case PORT_D :
		{ if (Value == LOW)
			{
				CLR_BIT(PORTD,PinNumber) ;
				
			}
			else if (Value == HIGH)
			{
				SET_BIT(PORTD,PinNumber) ;
			}
			else {
				// error handling
			}
			break ;
		}
	}
}

// DIO TOGGLE IMPLEMENTATION

void DIO_toggle(uint8_t PinNumber , uint8_t PORTNO )
{
	
	switch (PORTNO)
	{
		case PORT_A :
		{ (GET_BIT(PINA,PinNumber)) ? (CLR_BIT(PORTA,PinNumber)) :(SET_BIT(PORTA,PinNumber)) ;
			break ;
		}
		case PORT_B:
		{ (GET_BIT(PINB,PinNumber)) ? (CLR_BIT(PORTB,PinNumber)) :(SET_BIT(PORTB,PinNumber)) ;
			break ;
		}
		
		case PORT_C :
		{ (GET_BIT(PINC,PinNumber)) ? (CLR_BIT(PORTC,PinNumber)) :(SET_BIT(PORTC,PinNumber)) ;
			break ;
		}
		case PORT_D :
		{ (GET_BIT(PIND,PinNumber)) ? (CLR_BIT(PORTD,PinNumber)) :(SET_BIT(PORTD,PinNumber)) ;
			break ;
		}
	}
}
//DIO READ AND RETURN A POINTER  IMPLEMENTATION

void DIO_read(uint8_t PinNumber , uint8_t PORTNO , uint8_t*ptr)
{ 
	switch (PORTNO)
	{
		case PORT_A :
		{ *ptr = GET_BIT(PINA,PinNumber)  ;
			break ;
		}
		case PORT_B:
		{ *ptr = GET_BIT(PINB,PinNumber)  ;
			break ;
		}
		
		case PORT_C :
		{ *ptr =GET_BIT (PINC,PinNumber)  ;
			break ;
		}
		case PORT_D :
		{ *ptr = GET_BIT(PIND,PinNumber)  ;
			break ;
		}
		default :
		{

		 *ptr = -1 ;	// error detection

		}
	}
}
// DIO RETURN BIT IMPLEMENTATION
enum Value DIO_returnbit(uint8_t PinNumber , uint8_t PORTNO)
{
	switch (PORTNO)
	{
		case PORT_A :
		{
			return GET_BIT(PINA,PinNumber)  ;

		}
		case PORT_B:
		{
			return GET_BIT(PINB,PinNumber)  ;
		}

		case PORT_C :
		{ return  GET_BIT (PINC,PinNumber)  ;

		}
		case PORT_D :
		{ return  GET_BIT(PIND,PinNumber)  ;
		}
		default :
		{
			return -1 ; // error detection

		}
	}
}

