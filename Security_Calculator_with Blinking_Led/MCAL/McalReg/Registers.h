/*
 * Register.h
 *  Author: mohamed
 */ 


#ifndef REGISTERS_H_
	#define REGISTERS_H_

//*************************************************************	
//PORT REGISTERS
//*************************************************************
// Port A MACROS
#define PORTA	 *((volatile uint8_t*)0x3B)
#define DDRA	 *((volatile uint8_t*)0x3A)
#define PINA	 *((volatile uint8_t*)0x39)
// Port B MACROS
#define PORTB	 *((volatile uint8_t*)0x38)
#define DDRB	 *((volatile uint8_t*)0x37)
#define PINB	 *((volatile uint8_t*)0x36)
// Port C MACROS

#define PORTC	*((volatile uint8_t*)0x35)
#define DDRC	*((volatile uint8_t*)0x34)
#define PINC	*((volatile uint8_t*)0x33)

// Port D MACROS
#define PORTD	*((volatile uint8_t*)0x32)
#define DDRD	*((volatile uint8_t*)0x31)
#define PIND	*((volatile uint8_t*)0x30)


//*************************************************************
// Timer0 Registers
//*************************************************************
#define TCCR0	*((volatile uint8_t*)0x53)
#define TCNT0	*((volatile uint8_t*)0x52)
#define TIFR	*((volatile uint8_t*)0x58)
//****************************************************************
// Bit Macros	
//****************************************************************
#define SET_BIT(REG,BIT)  REG |=(1<<BIT) 
#define CLR_BIT(REG,BIT)  REG &= ~(1<<BIT)
#define TOG_BIT(REG,BIT)  REG ^=(1<<BIT)
#define GET_BIT(REG,BIT)  ((REG &(1<<BIT))>>BIT)	
#define ROT_LEFT (REG,n,Size)   REG = (REG<<n) | (REG>>(Size-n))
#define ROT_RIGHT (REG,n,Size)	REG = (REG>>n) | (REG<<(Size-n))
//**********************************************************
// interrupt REG MACROS
//**********************************************************
#define SREG   *((volatile uint8_t *)0x5F)
#define MCUCR  *((volatile uint8_t *)0x55)
#define GICR   *((volatile uint8_t *)0x5B)
#define MCUCSR  *((volatile uint8_t *)0x54)
	
#endif /*registers file*/
