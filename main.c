/*
 * Asignacion_2LED_1BTN.c
 *
 * Created: 06/11/2020 2:37:23 p. m.
 * Author : cesh_
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

int main(void)
{
	DDRB |=(1<<PORTB4)|(1<<PORTB6);   // Set the data direction register to OUTPUT
	DDRA &=~(1<<PORTA2);	// Set the data direction register for the switch to INPUT
	
	PORTB=(0<<PORTB4)|(0<<PORTB6); // output LOW STATE (sink)
	PORTA=(1<<PORTA2);	// enable the PULL-UP RSISTOR for the switch
   
    while (1) 
    {
		if (PINA & (1<<PORTA2))
		{
			PORTB |=(1<<PORTB6);
			PORTB &=~(1<<PORTB4);
			_delay_ms (500);
		}
		
		else
		{
			PORTB&=~ (1<<PORTB6);
			PORTB|=(1<<PORTB4);
			_delay_ms ( 500 );
		}
    }
}

