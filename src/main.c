/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2014 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"

#include "stm32f30x.h"
#include "gpio.h"
#include "usart.h"
#include "spi.h"
#include "interrupt.h"
#include "console.h"

// ----- main() ---------------------------------------------------------------

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

int
main(int argc, char* argv[])
{
	/* Initialisation */
	SystemInit();
	interrupt_init();
	gpio_init();
	usart_init();
	spi_init();

	console_init();


	/* Switch LEDs on (Low active) */
/*	SET_BIT(GPIOE->BSRR, 0x100);
	SET_BIT(GPIOE->BSRR, 0x200);
	SET_BIT(GPIOE->BSRR, 0x400);
	SET_BIT(GPIOE->BSRR, 0x800);
	SET_BIT(GPIOE->BSRR, 0x1000);
	SET_BIT(GPIOE->BSRR, 0x2000);
	SET_BIT(GPIOE->BSRR, 0x4000);
	SET_BIT(GPIOE->BSRR, 0x8000);
*/
	/* Write "Hello world!" to UART1 (9600-8-n-1) */
	usart_write_s(USART1, "Hello world!\n\r");


	uint8_t spi_recv_data = 0x0;

	/* main loop */
	while (1)
	{
		GPIO_ResetBits(GPIOE, GPIO_Pin_3);
		SPI_SendData8(SPI1, 0x8F);
		/* Send dummy data via SPI1 */
		SPI_SendData8(SPI1, 0xFF);
		spi_recv_data = SPI_ReceiveData8(SPI1);
		for(int i = 0; i < 1000; i++);
		GPIO_SetBits(GPIOE, GPIO_Pin_3);

		for(int i = 0; i < 1000; i++);

	}
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
