/*
 * File:   main.c
 * Author: FDPR
 *
 * Created on 31 de marzo de 2021, 07:29
 */


#include <xc.h>
#include "kbrd.h"
void main(void) {
     kbrd_init();
     DDRB = 0xFF;
     while(1){
        switch(kbrd_read()){
            case '1': PORTB = (1<<PB0)|(0<<PB1)|(0<<PB3);break;
            case '2': PORTB = (0<<PB0)|(1<<PB1)|(0<<PB3);break;
            case '3': PORTB = (0<<PB0)|(0<<PB1)|(1<<PB3);break;
            default:  PORTB = (0<<PB0)|(0<<PB1)|(0<<PB3);break;
        }
        
     }
}
