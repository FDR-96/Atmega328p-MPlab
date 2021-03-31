/*
 * File:   TECLADO.c
 * Author: FDPR
 *
 * Created on 29 de marzo de 2021, 08:49
 */
#include "Tcld.h"
#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000
//unsigned static char* kbrd_port;

//TODO: agregar la mascara para el otro pin si se esta utilizando un teclado 4x4
#define KBRD_ROW_MASK()  (PORTC & (1<<PC4)) >> PC4 | ((PORTC & (1<<PC5)) >> PC5) << 1 | ((PORTC & (1<<PC6)) >> PC6) << 2 

#define KBRD_ROW_MASK_AL()  (~(PORTC | ~(1<<PC4)) >> PC4) | (~(PORTC | ~(1<< PC5)) >> PC5) << 1 | (~(PORTC | ~(1<< PC6)) >>  PC6) << 2 

//function prototypes
 void activate_column(unsigned char column);
 void reset_columns(void);

void TCLD_init()
{
	//Column pins are Outputs
	DDRC |= (1<<PC0);
	DDRC |= (1<<PC1);
	DDRC |= (1<<PC2);
	DDRC |= (1<<PC3);
	
	//Row pins are Inputs
	DDRC &= ~(1<<PC4);
	DDRC &= ~(1<<PC5);
	DDRC &= ~(1<<PC6);

	
	
	//enable pull ups on row pins
	PORTC |= (1<<PC0);
	PORTC |= (1<<PC1);
	PORTC |= (1<<PC2);
	PORTC |= (1<<PC3);
	// Put Ones in Columns
	PORTC |= (1<<PC4);
	PORTC |= (1<<PC5);
	PORTC |= (1<<PC6);

	

}

char TCLD_leer(void)
{
	//reset_columns();
	char tecla=0;
	//verificamos estado dela columna
	activate_column(0);

	_delay_ms(100);

	switch(KBRD_ROW_MASK_AL())
		{
		case 1:
			 tecla='7';
		break;
		case 2:
			tecla= '4';
		break;
		case 4:
			tecla= '1';
		break;
		case 8:
			tecla= '.';
		break;
	}	



	//verificamos la seunda columna
	activate_column(1);

	_delay_ms(100);

	switch(KBRD_ROW_MASK_AL())
	
	{
		case 1:
			tecla= '8';
		break;
		case 2:
			tecla= '5';
		break;
		case 4:
			tecla= '2';
		break;
		case 8:
			tecla= '0';// +
		break;
		
	}	
	
	
	
	//verificamos la tercera columna
	activate_column(2);
	
	_delay_ms(100);

	switch(KBRD_ROW_MASK_AL())
	
	{
		case 1:
			tecla= '9';// /
		break;
		case 2:
			tecla= '6';// X
		break;
		case 4:
			tecla= '3';// -
		break;
		case 8:
			tecla= '=';
		break;
		
	}
	
	
	//verificamos la primera
	activate_column(3);

	_delay_ms(100);

	switch(KBRD_ROW_MASK_AL())
	{
		case 1:
			tecla= '/';
		break;
		case 2:
			tecla= 'X';
		break;
		case 4:
			tecla= '-';
		break;
		case 8:
			tecla= '+';
		break;
	}	
	
	reset_columns();
	
	if (tecla!=-1)
	{
		return tecla;
	}
	else{return 0;}
	
}

//FIXME: 
void activate_column(unsigned char column)
{
	if(column == 0)
	{
		PORTC &= ~(1<< PC0);
		PORTC |= (1<< PC1);
		PORTC |= (1<< PC2);
		PORTC |= (1<< PC3);	
		
	}
	 if(column == 1)
	{
		PORTC |= (1<< PC0);
		PORTC &= ~(1<< PC1);
		PORTC |= (1<< PC2);
		PORTC |= (1<< PC3);
			
	}
	if(column == 2)
	{
		PORTC |= (1<< PC0);
		PORTC |= (1<< PC1);
		PORTC &= ~(1<< PC2);
		PORTC |= (1<< PC3);
			
	}
	//FIXME: completar para un teclado 4x4
	if(column == 3)
	{
        PORTC |= (1<< PC0);
		PORTC |= (1<< PC1);
		PORTC |= (1<< PC2);
		PORTC &= ~(1<< PC3);
		
	}
	
}


void reset_columns()
{
	
    PORTC |= (1<< PC0);
	PORTC |= (1<< PC1);
	PORTC |= (1<< PC2);
	PORTC |= (1<< PC3);
			
}