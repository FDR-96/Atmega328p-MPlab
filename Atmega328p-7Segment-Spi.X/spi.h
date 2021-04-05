#ifndef SPI_H
#define SPI_H

#include <avr/io.h>

// Definimos los pines en los que vamos a utilizar la comunicacion spi con sus etiquetas

#define SPI_PORT PORTB
#define SPI_PIN  PINB
#define SPI_DDR  DDRB
#define SPI_SS   2
#define SPI_MOSI 3
#define SPI_MISO 4
#define SPI_SCK  5
#define SPI_DISP 6 

#define SPI_read() spi_transfer(0)
#define SPI_write(x) spi_transfer(x)

void SPI_init(void);
uint8_t SPI_transfer(uint8_t data);


#endif