/*
 * interrupt.c
 *
 *  Created on: Sep 22, 2022
 *      Author: mohamed
 */
#include "interrupt.h"


void (*p2f_INT0) () =0 ;
void (*p2f_INT1) () =0 ;
void (*p2f_INT2) () =0 ;




void EXTINT_init()
{	SET_BIT(SREG,GIB)  	; // set Global Interrupt BIT in status reg (bit 7) in SREG REG
#if EXT_INT0_MODE == ENABLE
	#if EXT_INT0_SENSE_MODE == LOW_LEVEL
			CLR_BIT(MCUCR,ISC00) ;
			CLR_BIT(MCUCR,ISC01) ;
	#elif EXT_INT0_SENSE_MODE == ANY_LOGIC_CHANGE
			SET_BIT(MCUCR,ISC00) ;
			CLR_BIT(MCUCR,ISC01) ;
	#elif EXT_INT0_SENSE_MODE == FALLING_EDGE
			CLR_BIT(MCUCR,ISC00) ;
			SET_BIT(MCUCR,ISC01) ;
	#elif EXT_INT0_SENSE_MODE == RISING_EDGE
			SET_BIT(MCUCR,ISC00) ;
			SET_BIT(MCUCR,ISC01) ;

	#endif
			EXTINT_enable(EXTI0) ;
#endif

#if EXT_INT1_MODE == ENABLE
	#if EXT_INT1_SENSE_MODE == LOW_LEVEL
			CLR_BIT(MCUCR,ISC10) ;
			CLR_BIT(MCUCR,ISC11) ;
	#elif EXT_INT1_SENSE_MODE == ANY_LOGIC_CHANGE
			SET_BIT(MCUCR,ISC10) ;
			CLR_BIT(MCUCR,ISC11) ;
	#elif EXT_INT1_SENSE_MODE == FALLING_EDGE
			CLR_BIT(MCUCR,ISC10) ;
			SET_BIT(MCUCR,ISC11) ;
	#elif EXT_INT1_SENSE_MODE == RISING_EDGE
			SET_BIT(MCUCR,ISC10) ;
			SET_BIT(MCUCR,ISC11) ;
#endif
	EXTINT_enable(EXTI1) ;
#endif



#if EXT_INT2_MODE == ENABLE
	#if EXT_INT1_SENSE_MODE == FALLING_EDGE
			CLR_BIT(MCUCSR,ISC2) ;
	#elif EXT_INT1_SENSE_MODE == RISING_EDGE
			SET_BIT(MCUCSR,ISC2) ;
	#endif
	EXTINT_enable(EXTI2) ;
#endif
}




ISR(EXT_INT0)
{ if (passed ==1)
{
	switch (C_flag)
{
case 1 :
	C_flag=2 ;
	break ;
case 2 :
	C_flag=1 ;
	break ;
default :
{
	C_flag=1 ;
}
}
}
else
{  if (p2f_INT0 != 0)
		{
			p2f_INT0(0,1,"enter pass first :D") ;

		}

}

}


ISR(EXT_INT1)
{


}
ISR(EXT_INT2)
{


}

void EXTINT_enable(EXTI_TYPES interrupt)
{
switch (interrupt)
{
	case EXTI0 :
	{ SET_BIT(GICR,GICR_INT0) ;


	break ;
	}

	case EXTI1 :
	{	SET_BIT(GICR,GICR_INT1) ;

		break ;
	}
	case EXTI2 :
	{SET_BIT(GICR,GICR_INT2) ;

	 break ;
	}
	default :
	{
 // error detection
	}

}



}


void EXTINT_disable(EXTI_TYPES interrupt)
{
	switch (interrupt)
	{
		case EXTI0 :
		{ CLR_BIT(GICR,GICR_INT0) ;


		break ;
		}

		case EXTI1 :
		{	CLR_BIT(GICR,GICR_INT1) ;

			break ;
		}
		case EXTI2 :
		{CLR_BIT(GICR,GICR_INT2)  ;

		 break ;
		}
		default :
		{

		}
		}
	}


void SET_CALLBACK_INT0(void (*p2f)(void))
{
	p2f_INT0=p2f ;
}
void SET_CALLBACK_INT1(void (*p2f)(void))
{
	p2f_INT1=p2f ;

}
void SET_CALLBACK_INT2(void (*p2f)(void))
{
	p2f_INT2=p2f ;

}
