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
#define FOSC 16000000
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1
void main(void) {
    cli();
    DDRB = (1<<PB5);
    PORTB = (0<<PB5);
    ADC_init();
    PWM_init(10);
    unsigned int ubrr = MYUBRR;
    UBRR0H = (unsigned char)(ubrr>>8);
    UBRR0L = (unsigned char)ubrr;  
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);
    UCSR0C = (1<<USBS0)|(3<<UCSZ00);
    sei();

    int decena = 0;
    int unidad = 0;
    int valor = 0;
    unsigned char tx = '#';
    char txa;
    char Rx;
    while(1) {  
        long adcV = ADC_GetData(0)*5.0f/1024.0f;
        txa = adcV;
        PWM_setDuty(20);
        PWM_on();
    
        while(UCSR0A & (1<<RXC0));
        switch(UDR0)
        {
            case('#'):
                        while (!( UCSR0A & (1<<UDRE0)));
                        PORTB = (1<<PB5);
                        UDR0 = tx;     
                break;
            case('%'):  
                        while (!( UCSR0A & (1<<UDRE0)));
                        PORTB = (0<<PB5);
                        UDR0 = ADC_GetData(0);   
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
            case('�'):  // Caracter modificador de ancho de pulso
                        PWM_off();
                        for(int i = 0; i == 2;i++){
                            decena = USART_GetData();
                            unidad = USART_GetData();
                            valor = ((decena*10)+unidad);
                        }
                        PWM_setDuty(valor);
                        PWM_on();
                        USART_SetData('�');
                break;
      
                            
            default  :
                        while (!( UCSR0A & (1<<UDRE0)));
                        
                        UDR0 = Rx;
                        PORTB = (1<<PB5);
						break;
                        
        }
    }

}