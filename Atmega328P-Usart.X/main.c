/*
 * File:   main.c
 * Author: ADICHIP 4
 *
 * Created on 21 de febrero de 2021, 19:43
 */


#include <xc.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include "USARTAtmega328P.h"
unsigned char TxA = '#';
char TxB = '%';
unsigned char Rx;
void main(void) 
{
    cli();
    USART_init();
    DDRB = (1<<PB5);
    PORTB = (0<<PB5);
    sei();
    
    while(1)
    {
        Rx = USART_GetData();
        switch(Rx)
        {
            case('#'):
                        USART_SetData(TxA);
                    
                break;
            case('%'):
                        USART_SetData(TxA);
                        PORTB = (1<<PB5);
                break;
                                   
            default  :
                     
						break;
                        
        }
        
    }    
}