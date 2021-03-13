/*
 * File:   main.c
 * Author: FDR-96
 *
 */


#include <xc.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "ADC.h"

int main(void)
{
	cli();
	
	DDRB |= (1<<DDB5);
    ADC_init();
	
	sei();
	
    while (1) 
    {
		float adcV = ADC_GetData(0)*5.0f/1024.0f;

		if (adcV > 3.0f)
		{
			PORTB |= (1<<PORTB5);
		}
		else
		{
			PORTB &=~ (1<<PORTB5);
		}
    }
}
