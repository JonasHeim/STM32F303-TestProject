/*
 * console.c
 *
 *  Created on: 02.09.2017
 *      Author: forcexx
 */

#include "console.h"
#include "string.h"

char recv_data[MAX_RECV_DATA];
uint8_t recv_counter = 0;
uint8_t led_toggle = 0;
command_t command_list[CMD_COUNT];

void console_init(){

	/* register commands */
	command_t command_tmp;

	command_tmp.cmd_name = "whoami";
	command_tmp.arg_c = 0;
	command_tmp.function = func_whoami;
	command_list[0] = command_tmp;

	command_tmp.cmd_name = "run";
	command_tmp.arg_c = 0;
	command_tmp.function = func_run;
	command_list[1] = command_tmp;

	command_tmp.cmd_name = "help";
	command_tmp.arg_c = 0;
	command_tmp.function = func_help;
	command_list[2] = command_tmp;
}

int func_whoami(char *data){

	usart_write_s(USART1, "\r\nCommand whoami - STM32F303VCT6\n\r");

	if(data){
		usart_write_s(USART1, data);
	}
	return 0;
}

int func_run(char *data){

	usart_write_s(USART1, "\r\nCommand run");

	if(data){
			usart_write_s(USART1, data);
		}
	return 0;
}

int func_help(char *data){

	usart_write_s(USART1, "\r\nAvailable commands:\r\n");
	for(int i = 0; i < CMD_COUNT; i++){
		usart_write_s(USART1, command_list[i].cmd_name);
		usart_write_s(USART1, "\r\n");
	}

	return 0;
}

void USART1_IRQHandler(void){

	/* toggle LED */
	if(led_toggle){
		led_toggle = 0;
		GPIO_SetBits(GPIOE, GPIO_Pin_8);
	}
	else{
		led_toggle = 1;
		GPIO_ResetBits(GPIOE, GPIO_Pin_8);
	}

	char recv_char = 0x00;

	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET){
		/* get data */
		recv_char = USART_ReceiveData(USART1);

		if(recv_char == '\r'){
			/* end of data */

			/* end of input */
			recv_data[recv_counter] = '\0';

			/* disable interrupt */
			usart_set_rx_int(DISABLE);

			/* parse input */
			parse_input();

			usart_write_s(USART1, "\n\rGot input: ");
			usart_write_s(USART1, recv_data);
			usart_write_s(USART1, "\r\n");

			/* input buffer */
			recv_counter = 0;

			/* enable interrupt */
			usart_set_rx_int(ENABLE);

		}
		else{
			/* echo received data */
			usart_write_c(USART1, recv_char);

			if(recv_counter < MAX_RECV_DATA){
				recv_data[recv_counter] = recv_char;
				recv_counter++;
			}
			else{
				recv_counter = 0;
				usart_write_s(USART1, "\n\rInput too long\n\r");
			}

		}
	}
}

int parse_input(){

	/* get first token = cmd */
	char *str_ptr1 = recv_data;
	char *str_tok = strtok(str_ptr1, " ");

	command_func func_tmp;

	if(str_tok){

		usart_write_s(USART1, "\n\rTOKEN = ");
		usart_write_s(USART1, str_tok);
		usart_write_s(USART1, "\n\r");

		/* get function */
		for(int i = 0; i < CMD_COUNT; i++){
			if(!strcmp(command_list[i].cmd_name, str_tok)){
				/* found function, call it */
				func_tmp = command_list[i].function;
				func_tmp(str_ptr1);
				break;
			}
		}
	}
	else{
		/* invalid command */
		usart_write_s(USART1, "\n\rUnknown command ");
		/* TODO ausgabe des 1. Tokens
		 * unknown command '...'
		 */
	}






	return 0;
}

