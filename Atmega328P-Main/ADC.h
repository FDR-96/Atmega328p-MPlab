/*
 * File:   ADC.c
 * Author: FDR-96
 *
 */


#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
#include <util/delay.h>

void ADC_init();
unsigned char ADC_GetData(int canal);

#endif /* ADC_H_ */