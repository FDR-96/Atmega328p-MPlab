/*
 * File:   main.c
 * Author: FDPR
 *
 * Created on 25 de marzo de 2021, 05:28
 */


#include <xc.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "PCINT.h"

ISR (PCINT0_vect) {
    // Interrupt handler code goes here
}
ISR (PCINT1_vect) { //A0 a D5
    
}
void main(void) {
    cli();
    PCINT_init();
    DDRB = (0<<PINB4);
    sei();
    while(1){
    
    
    }
}
