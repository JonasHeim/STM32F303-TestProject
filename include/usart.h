/*
 * usart.h
 *
 *  Created on: 24.07.2017
 *      Author: forcexx
 */

#ifndef USART_H_
#define USART_H_

#include "stm32f30x_usart.h"

/* Initialise USART */
void usart_init();

void usart_write_c(USART_TypeDef* USARTx, char c);

void usart_write_s(USART_TypeDef* USARTx, char *c);

void usart_set_rx_int(FunctionalState set);

#endif /* USART_H_ */
