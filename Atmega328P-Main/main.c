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

void main(void) {
    cli();
    ADC_init();
    PWM_init(10);
    USART_init();
    sei();

    int decena = 0;
    int unidad = 0;
    int valor = 0;
    char tx = '#';
    char adcVolt;
    char Rx;
    while(1) {  
        float adcV = ADC_GetData(0)*5.0f/1024.0f;
        adcVolt = adcV;
        PWM_setDuty(20);
        PWM_on();
        Rx = USART_GetData();
        switch(Rx)
        {
            case('#'):
                        USART_SetData(tx);      
                break;
            case('%'):  
                       USART_SetData(adcVolt);
                        USART_SetData(adcV);
                break;
            case('?'):  // Caracter modificador de frecuencia
                        PWM_off();
                        for(int i = 0; i == 2;i++){
                            decena = USART_GetData();
                            unidad = USART_GetData();
                            valor = ((decena*10)+unidad);
                        }
                        PWM_init(valor);
                        PWM_on();
                        USART_SetData('?');
                break;
            case('¿'):  // Caracter modificador de ancho de pulso
                        PWM_off();
                        for(int i = 0; i == 2;i++){
                            decena = USART_GetData();
                            unidad = USART_GetData();
                            valor = ((decena*10)+unidad);
                        }
                        PWM_setDuty(valor);
                        PWM_on();
                        USART_SetData('¿');
                break;
      
                            
            default  :
                     
						break;
                        
        }
    }

}