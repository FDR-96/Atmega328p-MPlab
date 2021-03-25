/*
 * File:   main.c
 * Author: FDPR
 *
 * Created on 24 de marzo de 2021, 06:07
 */

#include <xc.h>
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <stdint.h>
#include "WatchDog.h"
#define _XTAL_FREQ 8000000

void main(void) {
    cli();
    WATCHDOG_init();
    WATCHDOG_SetPreescaler(1);
   
    sei();
    DDRB = (1<<PINB1);
    PORTB = (1<<PINB1);
            
    while(1){
        __delay_ms(20);
        PORTB = (0<<PINB1);
    }
    return;
}
