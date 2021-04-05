
#ifndef MTCLDO_H
#define	MTCLDO_H

#include <xc.h> 

uint8_t sal[4] ={0xFE, 0xFD, 0xFB, 0xF7};
uint8_t i, ren, ent;

void MTCLDO_init();
unsigned char MTCLDO_read();
#endif	/* XC_HEADER_TEMPLATE_H */

