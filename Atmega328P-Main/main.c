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
    unsigned char TxA = '#'; // Caracter de verificacion de conexion
    unsigned char TxB = '%'; // Caracter de estado de bateria
    unsigned char TxC = '$'; // Caracter de lectura ADC corriente
    unsigned char TxD = '&'; // Caracter de lectura de Tension
    unsigned char TxE = '?'; // Caracter modificador de frecuencia
    unsigned char TxF = '¿'; // Caracter modificador de ancho de pulso
    unsigned char TxG = '('; // Caracter de encendido del PWM
    unsigned char TxH = ')'; // Caracter de Apagado del PWM
    int decena = 0;
    int unidad = 0;
    int valor = 0;
    while(1) {  
        float adcV = ADC_GetData(0)*5.0f/1024.0f;
        PWM_setDuty(20);
        PWM_on();
        switch(USART_GetData())
        {
            case('#'):
                        USART_SetData(TxA);      
                break;
            case('%'):  
                       
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
                        USART_SetData(TxE);
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
                        USART_SetData(TxF);
                break;
      
                            
            default  :
                     
						break;
                        
        }
    }

}