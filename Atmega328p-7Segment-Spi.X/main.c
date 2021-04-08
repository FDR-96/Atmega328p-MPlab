/*
 * File:   main.c
 * Author: FDPR
 *
 * Created on 4 de abril de 2021, 13:41
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <avr/wdt.h>
#include <xc.h>
#include "Max7219.h"
#include "spi.h"
void main(void) {
    cli();
    SPI_init();
    sei();
    while(1){
      Display_Digit(Digit1, Deco);
          
    }
}
