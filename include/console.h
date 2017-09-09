/*
 * console.h
 *
 *  Created on: 02.09.2017
 *      Author: forcexx
 */

#ifndef CONSOLE_H_
#define CONSOLE_H_

#include "interrupt.h"
#include "usart.h"
#include <string.h>

#define MAX_RECV_DATA	255
#define CMD_COUNT		3

extern char recv_data[MAX_RECV_DATA];
extern uint8_t recv_counter;
extern uint8_t led_toggle;

/* prototypes */
void console_init();
int parse_input();

typedef int (*command_func)(char *data);

typedef struct command_struct {
	char* cmd_name;
	int arg_c;
	command_func function;
} command_t;

/* command prototypes */
int func_whoami(char *);
int func_run(char *);
int func_help(char *);

extern command_t command_list[CMD_COUNT];

#endif /* CONSOLE_H_ */
