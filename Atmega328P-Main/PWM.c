/*
 * PWM.c
 *
 * Created: 16/03/2019 13:05:27
 *  Author: marlon
 */ 

 #include "PWM.h"
 int _freq = 0;
 #define FCPU 16000000UL
 #include <xc.h>
 #include <avr/io.h>
 #include <avr/interrupt.h>
 #include <stdbool.h>


void PWM_init(int freq)
{
	//Operation Mode = Fast PWM
	TCCR1A = (0<<WGM10)|(1<<WGM11)|(1<<WGM12)|(1<<WGM13);
	
	//Compare value
	_freq = freq;
	ICR1 = (FCPU/1024/_freq) - 1;
}

void PWM_on()
{
	TCNT1 = 0x0000;
	//N = 1024
	TCCR1B = (1<<CS10)|(0<<CS11)|(1<<CS12);
}

void PWM_off()
{
	//Clock setting T1clock = 0 Hz
	TCCR1B = (0<<CS10)|(0<<CS11)|(0<<CS12);
}

void PWM_setDuty(int duty)
{
	//Pin configuration
	DDRB = (1<<DDB1);
	
	//Output active
    TCCR1A = (0<<COM1A0)|(1<<COM1A1);

	OCR1A = (((FCPU/1024/_freq) - 1)*duty)/100;
}
