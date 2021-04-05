/*
 * File:   MTCLDO.c
 * Author: FDPR
 *
 * Created on 31 de marzo de 2021, 07:29
 */


#include <xc.h>
#include "MTCLDO.h"
 uint8_t teclado();
 uint8_t dato;
 void MTCLDO_init(){
    teclado(){
    for(i = 0, ren = 0; i < 4; i++, ren+=4){
        PORTD = sal[i];
        asm(nop);
        ent = PIND & 0xF0;
        if (ent != 0xF0){
            switch(ent){
                case 0xE0: return ren;
                case 0xD0: return ren +1;
                case 0xB0: return ren +2;
                case 0x70: return ren +3;
            }
        }
    }
    }
    return 0xFF;
}

unsigned char MTCLDO_read(){
    dato = teclado();
    
}