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
    char TxA = '#'; // Caracter de verificacion de conexion
    char TxB = '%'; // Caracter de estado de bateria
    char TxC = '$'; // Caracter de lectura ADC corriente
    char TxD = '&'; // Caracter de lectura de Tension
    char TxE = '?'; // Caracter modificador de frecuencia
    char TxF = '¿'; // Caracter modificador de ancho de pulso
    char TxG = '('; // Caracter de encendido del PWM
    char TxH = ')'; // Caracter de Apagado del PWM
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
                        USART_SendData(TxA);      
                break;
            case('%'):  
                       
                        USART_SendData(adcV);
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
                        USART_SendData(TxE);
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
                        USART_SendData(TxF);
                break;
      
                            
            default  :
                     
						break;
                        
        }
    }

}