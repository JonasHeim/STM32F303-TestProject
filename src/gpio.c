/*
 * gpio.c
 *
 *  Created on: 24.07.2017
 *      Author: forcexx
 */

#include "gpio.h"

void gpio_init(){

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_StructInit(&GPIO_InitStructure);

	/*
	 * LEDs
	 */

	/* Clock GPIOE */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	/*
	 *  UART1
	 */

	/* Clock GPIOA */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* Alternative function PinA9, PinA10 */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_7);	//Tx
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_7);	//Rx

	/*
	 * SPI1
	 */

	/* Clock GPIOA */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

	/* Alternative function PinA5, PinA6, PinA7 */
	//GPIO_PinAFConfig(GPIOA, GPIO_PinSource4, GPIO_AF_5);	//NSS
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_5);	//CLK
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_5);	//MISO
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_5);	//MOSI

	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7; //| GPIO_Pin_4
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* Chips select */
	/* Clock GPIOE */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);


	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOE, &GPIO_InitStructure);


}


