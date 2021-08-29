#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int contA;
int contB;

int main(void)
{
	contA = 0;
	contB = 0;

	cli();					// Desactivando interrupciones globales

    DDRD &=~ (1<<DDD2);		// Pin 2 del puerto D como entrada
	PORTD |= (1<<PORTD2);	// pull-up activado

	EICRA &=~ (1<<ISC00);	// INT0 configurado = Flanco de bajada
	EICRA |= (1<<ISC01);

	EIMSK |= (1<<INT0);		// INT0 activado

	DDRB |= (1<<DDB5);		// Pin 5 del puerto B como salida

	sei();					// Activando interrupciones globales

    while (1) 
    {
		_delay_ms(5000);
		contB = contA;
		contA = 0;

		for (int i = 0; i < contB; i++)
		{
			PORTB |= (1<<PORTB5);
			_delay_ms(500);
			PORTB &=~ (1<<PORTB5);
			_delay_ms(500);
		}
    }
}

ISR(INT0_vect)
{
	contA++;	
}