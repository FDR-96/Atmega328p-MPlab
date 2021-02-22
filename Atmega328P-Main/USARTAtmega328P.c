/*
 * File:   USART.c
 * Author: ROLDAN
 *
 * Created on 21 de febrero de 2021, 19:44
 */



#include "USARTAtmega328P.h"
#include <xc.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#define FOSC 16000000
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1
void USART_init()
{
    
    unsigned int ubrr = MYUBRR;
    UBRR0H = (unsigned char)(ubrr>>8);
    UBRR0L = (unsigned char)ubrr;  
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);
    UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}


void USART_SetData(char Tx)
{
     while (!( UCSR0A & (1<<UDRE0)));
     UDR0 = Tx;
}

unsigned char USART_GetData()
{
	while(UCSR0A & (1<<RXC0));
	return UDR0;	
}