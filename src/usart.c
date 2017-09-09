/*
 * usart.c
 *
 *  Created on: 24.07.2017
 *      Author: forcexx
 */

#include "usart.h"

void usart_init(){

	USART_InitTypeDef USART_InitStructure;

	/* Clock USART1 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

	/* U(S)ART */
	USART_StructInit(&USART_InitStructure);

	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;

	USART_DeInit(USART1);

	USART_Init(USART1, &USART_InitStructure);

	/* Enable USART1 interrupt 'Receive data register not empty */
	usart_set_rx_int(ENABLE);

	USART_Cmd(USART1, ENABLE);

}

void usart_write_c(USART_TypeDef* USARTx, char c){
	while(!(USART1->ISR & USART_ISR_TXE));
	USART_SendData(USARTx, (uint16_t) c);
}

void usart_write_s(USART_TypeDef* USARTx, char *s){
	if(s){
		char* tmp = s;
		while(*tmp){
			usart_write_c(USARTx, *tmp);
			tmp++;
		}
	}
}

void usart_set_rx_int(FunctionalState set){
	USART_ITConfig(USART1, USART_IT_RXNE, set);
}

