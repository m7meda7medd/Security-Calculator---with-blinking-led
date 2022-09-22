
#include "App.h"
 // variables related to calculator mode
uint8_t buffer[12];
uint8_t temp[10] ;
uint8_t i=0 , text=KP_NOTPRESSED , operation,flag =0 ;
double Num1=0,Num2=0,result =0 ;

//variables related to security key
uint8_t Security_Key[4]="1122",Try[4] ;
volatile uint8_t passed =0 ;

// control flag
volatile uint8_t C_flag = 0 ;

void APP_init ()
{	KP_4x4_init() ; // initialization of keypad
	LCD_4bit_init() ; // lcd initialization
	LED_init(PORT_D,PIN_7) ; // led initialization
	BUTTON_init(PORT_D,PIN_2) ; // button initialization
	EXTINT_init() ; // interrupt initialization
	SET_CALLBACK_INT0(locked_press) ;
}


void APP_start () // control the modes if security key passed with flag
{
while (1) // C_flag starts with zero value
{
	if (C_flag==CALC_MODE) // if flag ==1 go to calculator mode
	{
		calculator_mode() ;
    }

	else if (C_flag == LED_BLINK_MODE) //if flag ==2 go to LED BLINKING mode
	{	LCD_4bit_clear() ; // clear lcd
		LCD_4bit_sendstring("LED_Blinking :D"); // print on lcd
		while (C_flag==LED_BLINK_MODE)
	{
		LED_toggle(PORT_D,PIN_7) ;
		_delay_ms(300) ;
	}
	}
	else
	{
		check_pass() ; // check key passed
						// if key passed it let the button to control the the modes  else will print enter pass first
	}
	}
}







void check_pass()
{while (!passed)
  {
		LCD_4bit_clear() ;
		uint8_t i=0 ;
		LCD_4bit_sendstring(" Enter PIN: ") ;
		while (i<4)
		{ 	while (text==KP_NOTPRESSED)
		{
			text = KP_4x4_check_press() ;
		}
			_delay_ms(160) ;
			LCD_4bit_sendchar(text) ;
			_delay_ms(160) ;
			Try[i]=text ;
			i++ ;
			text=KP_NOTPRESSED ;
		}
		if ((atoi(Try))==(atoi(Security_Key)))
		{ 	LCD_4bit_clear() ;
			LCD_4bit_sendstring("Passed") ;
			_delay_ms(500) ;
			LCD_4bit_clear() ;
			LCD_4bit_sendstring_x_y(3,0,"Press Button");
			LCD_4bit_sendstring_x_y(3,1,"to start");

			passed = 1 ;
		}
		else
		{ LCD_4bit_clear() ;
			LCD_4bit_sendstring("TRY Again !!") ;
			_delay_ms(500) ;
		}
	}
}

void calculator_mode()
{ 	LCD_4bit_clear() ;
	while (C_flag ==1)
{ while (text==KP_NOTPRESSED && C_flag==1)
{
	text= KP_4x4_check_press() ;
}
			_delay_ms(160) ;
			LCD_4bit_sendchar(text) ;
			_delay_ms(160) ;
	  	   switch (text)
	  	  	  { case 'C' :
	  	  	  		LCD_4bit_clear() ;
	  	  	  		i=0 ;
	  	  	  		result =0 ;
	  	  	  		Num1=0 ;
	  	  	  		Num2=0 ;
	  	  	  		 flag=0 ;
					break ;
				case 48 ... 57 :
					if (i==0)
						{	if (Num1!=0)
								Num1*=10 ;
							Num1+=(text-48) ;
						}
					else if (i==1)
					{
							if (Num2!=0)
								Num2*=10 ;
							Num2+=(text-48) ;
					}
					else
						{
						// error detection
						}
					break ;
				 case '=' :
					LCD_4bit_clear() ;
					 if (operation =='+')
					 {
						 result=Num1+Num2 ;
					 }
					 else if (operation =='-')
					 {
						 result=Num1-Num2 ;
					 }
					 else if (operation =='*')
					 {
						 result=Num1*Num2 ;
					 }
					 else if (operation =='/')
					 {
						 result=Num1/Num2 ;
					 }
					 else
					 {
						  // error detection
					 }
					 dtostrf(result,4,2,temp) ;
					 sprintf(buffer ,"%s", temp) ;
					 flag =1 ;
					 LCD_4bit_sendstring(buffer) ;
					 _delay_ms(120) ;
					 break ;
				 default :
					{ if (flag ==1)
							{	Num2=0 ;
								Num1 = result ;
							}
						operation=text ;
						i=1 ;
					}

	  	  	  }

	  	 text = KP_NOTPRESSED ;
}
}

void locked_press()
{ 			LCD_4bit_clear() ;
			LCD_4bit_sendstring("Enter Pass First") ;
			_delay_ms(200) ;
			LCD_4bit_clear() ;
			LCD_4bit_sendstring(" Enter PIN: ") ;
}
