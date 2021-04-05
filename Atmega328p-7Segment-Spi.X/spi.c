/*
 * File:   spi.c
 * Author: FDPR
 *
 * Created on 4 de abril de 2021, 14:04
 */


#include <xc.h>

#include "spi.h"

void SPI_init(void)
{
    // SS high
    SPI_PORT |= (1<<SPI_SS);
    // eeprom_SS, SS, MOSI, SCK output
    SPI_DDR |= (1<<SPI_SS)|(1<<SPI_MOSI)|(1<<SPI_SCK);
}
uint8_t SPI_transfer(uint8_t data)
{
    SPDR = data;
    while(!(SPSR & (1<<SPIF)))
        ;
    return SPDR;
}
