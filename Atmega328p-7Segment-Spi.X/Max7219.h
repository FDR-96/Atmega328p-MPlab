
#ifndef MAX7219_H_
#define MAX7219_H_

uint8_t dig;
uint8_t	inf;

//Definicion de funciones
void Display_Test(uint8_t inf);
void Display_Intensity(uint8_t inf);
void Display_Scan(uint8_t inf);
void Display_Shutdown(uint8_t inf);
void Display_Decode(uint8_t inf);
void Display_Digit(uint8_t dig, uint8_t inf);
void Display_Clear();


//Definimos los segmentos que se encienden en cada digito
#define		Digit0		0x01U
#define		Digit1		0x02U
#define		Digit2		0x03U
#define		Digit3		0x04U
#define		Digit4		0x05U
#define		Digit5		0x06U
#define		Digit6		0x07U
#define		Digit7		0x08U

#define		Deco	0x09U       	//Modo de decodificación. Para el byte de datos
#define		Intensidad	0x0AU		//El byte de datos establece el brillo de los dígitos. Nota> Aparece en la hoja de datos
#define		Scan_Limit	0x0BU		//Cuántos dígitos se utilizan. Nota sobre el Byte de datos: coloque un '1' en cada ubicación para que el dígito esté activo
#define		Shutdown	0x0CU		//registro de cierre. DAta byte 0x00 apaga disp 0x01 enciende disp, segun la hoja de dato je
#define		Display_Tst  0x0FU		//Mostrar el byte de datos de prueba 0x00 apaga la prueba 0x01 se enciende. Anula el comando de apagado,ta waeno

#define		ON			0x01U       //Definimos 
#define		OFF			0x00U


#define DISP_SELECT() SPI_PORT &= ~(1<<SPI_DISP)
#define DISP_DESELECT() SPI_PORT |= (1<<SPI_DISP)


#endif /* MAX7219_H_ */