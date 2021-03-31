/*
 * File:   PCINT.c
 * Author: FDPR
 *
 * Created on 25 de marzo de 2021, 05:29
 */


#include <xc.h>

void PCINT_init()
{
    PCICR |= _BV(PCIE0);
     PCIFR |= (1 << PCIF0);
	PCMSK2 |= _BV(PCINT0);
}