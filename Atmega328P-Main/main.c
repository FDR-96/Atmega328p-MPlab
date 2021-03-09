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
float  adcV;
float maximo = 3.7;
float medio = 3.5;
float minimo = 3.3;
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
    PWM_setDuty(20);
    PWM_on();
    while(1) {  
 
        adcV = ADC_GetData(0)*5.0f/1024.0f;
     
        
       
      switch(USART_GetData())
        {
            case '$': /* Caracter F para apagar el PWM que genera los pulsos.
                       */
                PWM_off();
                break;
            case 'N':  /* Caracter N para encender el PWM que genera los pulsos.
                       */
                PWM_on();
                break;
            case 'O':  /* Caracter O para control de la comunicacion UART..
                       */
                USART_SetData(TxA);
                PORTB = (0<<PB5);
                break;
            case '%':  /* Caracter % para verificar el estado de la bateria.
                       */
                if(adcV >= maximo)
                {
                   USART_SetData('H');
                }else if(adcV >= medio)
                {
                   USART_SetData('M');
                }else if(adcV >= minimo)
                {
                   USART_SetData('L');
                }else
                {
                   USART_SetData('N');
                }
                break;
            case 'P':   /* Caracter P controla el ancho del pulso
                       */
                switch(USART_GetData())
                {   
                    
                    case '1':  
                            USART_SetData('P');
                            PWM_setDuty(10);
                            PWM_on();
                        break;
                    case '2':  
                            USART_SetData('P');
                            PWM_setDuty(20);
                            PWM_on();
                        break;
                    case '3':  
                            USART_SetData('P');
                            PWM_setDuty(30);
                            PWM_on();
                        break;
                    case '4':  
                            USART_SetData('P');
                            PWM_setDuty(40);
                            PWM_on();
                    break;
                    case '5':  
                            USART_SetData('P');
                            PWM_setDuty(40);
                            PWM_on();
                    break;
                    default:
                        break;
                }
            break;
            case 'F':   
                switch(USART_GetData())
                {   
                    
                    case '1':  
                            USART_SetData('F');
                            cli();
                            PWM_init(1);
                            sei();
                            PWM_on();
                        break;
                    case '2':  
                            USART_SetData('P');
                            cli();
                            PWM_init(5);
                            sei();
                            PWM_on();
                        break;
                    case '3':  
                            USART_SetData('P');
                            cli();
                            PWM_init(10);
                            sei();
                            PWM_on();
                        break;
                  
                    default:
                        break;
                }
            break;
            default:
                break;
        }
    }

}