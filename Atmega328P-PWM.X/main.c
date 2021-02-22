/*
 * File:   main.c
 * Author: ADICHIP 4
 *
 * Created on 21 de febrero de 2021, 20:21
 */


#include <xc.h>
#include <avr/io.h>
#include <avr/interrupt.h>


#include "PWM.h"

int main(void)
{
	cli();
    PWM_init(10);
	sei();

	PWM_setDuty(20);
	
	PWM_on();

    while (1) 
    {
    }
}