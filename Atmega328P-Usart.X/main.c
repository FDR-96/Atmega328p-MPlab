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
char TxB = '1';
void main(void) {
    cli();
    USART_init();
    sei();
    while(1)
    {
        USART_SetData(TxB);
        USART_SetData('#');        
        switch(USART_GetData())
        {
            case('#'):
                        USART_SetData(TxA);
                    
                break;
                                   
            default  :
                     
						break;
                        
        }
        
    }    return;
}
