/*
 * interrupt.c
 *
 *  Created on: 02.09.2017
 *      Author: forcexx
 */

#include "interrupt.h"

void interrupt_init(){

	/* Conifgure priority grouping */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);

	/* Initialise interrupt module */
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x0;	//highest priority
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x0;			//highest priority
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;

	NVIC_Init(&NVIC_InitStruct);
}



