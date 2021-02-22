/*
 * File:   USART.c
 * Author: ROLDAN
 *
 * Created on 21 de febrero de 2021, 19:40
 */
#ifndef USARTAtmega328P_H_
#define USARTAtmega328P_H_



void USART_init();
void USART_SetData(char Tx);
unsigned char USART_GetData();
#endif 