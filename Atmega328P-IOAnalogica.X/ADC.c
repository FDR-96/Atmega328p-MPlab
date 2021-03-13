/*
 * ADC.c
 *
 * Created: 26/03/2019 06:43:35 p.m.
 *  Author: FDR-96
 */ 
#include "ADC.h"

void ADC_init()
{
	// Output adjust = right //
	ADMUX = (0<<ADLAR);

	// Voltage Reference = AVCC //
	ADMUX =  (1<<REFS0)|(0<<REFS1);

	// Frequency divisor = 128 -> 16000/128 = 125 KHz
	ADCSRA = (1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
}

int ADC_GetData(int canal)
{
	// Selección del canal de lADC //
	ADMUX &=~  0x0F;
	ADMUX |=  canal;
	
	// Encendemos en ADC
	ADCSRA |= (1<<ADEN);
	_delay_us(10);	// Esperamos a que caliente

	// Mandamos el muestreo
	ADCSRA |= (1<<ADSC);

	// Esperamos a que muestree, leyendo el flag
	while( !(ADCSRA & (1<<ADIF)) );
	ADCSRA |= (1<<ADIF);	// Reiniciamos el flag

	// Apagamos el ADC
	ADCSRA = (0<<ADEN);

	return ADC;	
}
