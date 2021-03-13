/*
 * File:   main.c
 * Author: FDR-96
 *
 * Created on 21 de febrero de 2021, 19:43
 */


#include <xc.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include "USARTAtmega328P.h"
unsigned char data[] = "%32 ";
unsigned char TxA = '#';

int i=1;
void main(void)       
{
    cli();
    USART_init();
    DDRB = (1<<PB5);
    PORTB = (1<<PB5);
    sei();
    
    for(;;)
    {
        switch(USART_GetData())
        {
            case '#':
                USART_SetData(TxA);
                PORTB = (0<<PB5);
                break;
            case '%':
                while(i <= 3)
                {
                USART_SetData(data[i]);
                i++;
                }
                i = 1;
                 PORTB = (1<<PB5);
                   break;
            default:
                break;
        }
   
    }    
}