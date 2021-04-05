/*
 * File:   Max7219.c
 * Author: FDPR
 *
 * Created on 4 de abril de 2021, 14:12
 */

#include "spi.h"
#include "MAX7219.h"





void Display_Test(uint8_t inf)
{ 
	DISP_SELECT();
	SPI_transfer(Display_Tst);
	SPI_transfer(inf);
	DISP_DESELECT();
}

void Display_Decode(uint8_t inf)
{
	DISP_SELECT();
	SPI_transfer(Deco);
	SPI_transfer(inf);
	DISP_DESELECT();
}

void Display_Intensity(uint8_t inf)
{
	DISP_SELECT();
	SPI_transfer(Intensidad);
	SPI_transfer(inf);
	DISP_DESELECT();
}

void Display_Scan(uint8_t inf)
{
	DISP_SELECT();
	SPI_transfer(Scan_Limit);
	SPI_transfer(inf);
	DISP_DESELECT();
}

void Display_Shutdown(uint8_t inf)
{
	DISP_SELECT();
	SPI_transfer(Shutdown);
	SPI_transfer(inf);
	DISP_DESELECT();
}

void Display_Digit(uint8_t dig, uint8_t inf)
{
	DISP_SELECT();
	SPI_transfer(dig);
	SPI_transfer(inf);
	DISP_DESELECT();
}

void Display_Clear()
{ uint8_t a;
 	a = 0x01;
	while(a <= 8)
	{
		Display_Digit(a, 0x00);
		a++;
	}
	
}