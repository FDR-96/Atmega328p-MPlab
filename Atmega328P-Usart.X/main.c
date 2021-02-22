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
#include <USARTAtmega328P.h>
unsigned long TxA = '#';
void main(void) {
    USART_init();
    while(1)
    {
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