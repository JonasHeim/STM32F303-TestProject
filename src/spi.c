/*
 * spi.c
 *
 *  Created on: 24.07.2017
 *      Author: forcexx
 */

#include "spi.h"

void spi_init(){

	SPI_InitTypeDef SPI_InitStructure;

	/* Enable clock SPI1 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);

	SPI_StructInit(&SPI_InitStructure);

	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_64;
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
	SPI_InitStructure.SPI_CRCPolynomial = 7;
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;

	/* DeInit SPI1 */
	SPI_I2S_DeInit(SPI1);
	/* Init SPI1 */
	SPI_Init(SPI1, &SPI_InitStructure);
	/* Enable SPI1 */
	SPI_Cmd(SPI1, ENABLE);

}


