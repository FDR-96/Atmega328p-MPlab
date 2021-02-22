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

uint16_t adc_read(uint8_t adcx);




void main(void) {
    ADCSRA |= _BV(ADEN); // Habilitamos el ADC
  
     //Usaremos OCR1A como nuestra salida PWM, que es la
     //mismo pin que PB1.
    DDRB = (1<<PB1)|(1<<PB5);
    PORTB = (0<<PB5);
    //Usaremos el modo Fast PWM de 8 bits.
    TCCR1A = _BV(COM1A1) | _BV(WGM11);                // Habilitamos la salida del PWM OC1A en el pin digital 9
    TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS12);     // Seteamos el PWM con prescaler 256
    ICR1 = 62499;                                     // Seteamos la frecuencia del PWM 1Hz: 16MHz/(256 * 1Hz) - 1 = 62499
    OCR1A = 6249;
    unsigned int ubrr = MYUBRR;
    UBRR0H = (unsigned char)(ubrr>>8);
    UBRR0L = (unsigned char)ubrr;
    
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);
    UCSR0C = (1<<USBS0)|(3<<UCSZ00);
    unsigned char ok = '#';
    unsigned char bateria = '%';
    bool bandera = false;
  
    while(1) {  
              
        if ( (UCSR0A & (1<<RXC0)) ){
            switch(UDR0) 		
            {   
                case '#' :           
                            while (!( UCSR0A & (1<<UDRE0)));
                            UDR0 = ok;     
                            bandera = true;
                            break;
                case '%' :           
                            while (!( UCSR0A & (1<<UDRE0)));
                            UDR0 = bateria;
                            bandera = true;
                            break;
                case '!' :           
                             ICR1 = 62499;                                     // Seteamos la frecuencia del PWM 1Hz: 16MHz/(256 * 1Hz) - 1 = 62499
                             OCR1A = 6249;
                            break;
                case '"' :           
                             ICR1 = 31250;                                     // Seteamos la frecuencia del PWM 1Hz: 16MHz/(256 * 2Hz) - 1 = 31250
                             OCR1A = 3125;
                            break;
                case '-' :           
                            ICR1 = 6252;                                     // Seteamos la frecuencia del PWM 1Hz: 16MHz/(256 * 1Hz) - 1 = 62499
                            OCR1A = 625;
                            break;
                            
            default  :
                     
						break;
                        
            }
        }else{
         bandera = false;
        }
         if (bandera){  
               PORTB = (1<<PB5);
         }else{
               PORTB = (0<<PB5);
         }
        while (!( UCSR0A & (1<<UDRE0)));  
        UDR0 = dc_read(ADC);
          
          
       
    }

}
uint16_t adc_read(uint8_t adcx) {
	/* adcx is the analog pin we want to use.  ADMUX's first few bits are
	 * the binary representations of the numbers of the pins so we can
	 * just 'OR' the pin's number with ADMUX to select that pin.
	 * We first zero the four bits by setting ADMUX equal to its higher
	 * four bits. */
	ADMUX	&=	0xf0;
	ADMUX	|=	adcx;

	/* This starts the conversion. */
	ADCSRA |= _BV(ADSC);

	/* This is an idle loop that just wait around until the conversion
	 * is finished.  It constantly checks ADCSRA's ADSC bit, which we just
	 * set above, to see if it is still set.  This bit is automatically
	 * reset (zeroed) when the conversion is ready so if we do this in
	 * a loop the loop will just go until the conversion is ready. */
	while ( (ADCSRA & _BV(ADSC)) );

	/* Finally, we return the converted value to the calling function. */
	return ADC;
}