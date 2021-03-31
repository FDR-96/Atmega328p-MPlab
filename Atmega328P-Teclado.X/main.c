/*
 * File:   main.c
 * Author: FDPR
 *
 * Created on 29 de marzo de 2021, 08:48
 */


#include <xc.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include "Tcld.h"
#include "USARTAtmega328P.h"
unsigned char Tx;
void main(void) {
    cli();
    TCLD_init();
    USART_init();
    DDRB = (1<<PB5);
    PORTB = (0<<PB5);
    sei();
    while(1){
        Tx = TCLD_leer();
        if(Tx == '7'){
           PORTB = (1<<PB5);
        }
        USART_SetData(Tx);
    }
}
