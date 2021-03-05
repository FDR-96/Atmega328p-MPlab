/*
 * File:   newmain.c
 * Author: ADICHIP 4
 *
 * Created on 18 de febrero de 2021, 23:23
 */


#include <xc.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include "ADC.h"
#include "PWM.h"    
#include "USARTAtmega328P.h"
int  adcV;

unsigned char TxA = 'H';
unsigned char Bateria[3] = "   \0";
int tempAdcA;
int  tempAdcB;
int  tempAdcC;
int i = 0;
void main(void) {
    cli();
    ADC_init();
    PWM_init(10);
    USART_init();
    sei();
    DDRB = (1<<PB5);
    PORTB = (0<<PB5);
       
   
    while(1) {  
 
        adcV = ADC_GetData(0)*5/1024;
        
        PWM_setDuty(20);
        PWM_on();
        
       
      switch(USART_GetData())
        {
            case 'H':
                USART_SetData(TxA);
                PORTB = (0<<PB5);
                break;
            case '%':
               
                tempAdcA = (adcV/100) + 48;
                Bateria[0] =  tempAdcA;
                tempAdcB = ((tempAdcA*100)-adcV/10)+ 48;
                Bateria[1] =  tempAdcB;
                tempAdcC = (((tempAdcA*100))+((tempAdcB*10))-adcV)+ 48;
                Bateria[2] =  tempAdcC;
                while(i <= 3){
                USART_SetData( Bateria[i]);                          
                i++;
                }
                i=0;
                PORTB = (1<<PB5);
                break;
            default:
                break;
        }
    }

}