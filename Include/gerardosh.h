#ifndef GERARDOSH_H
#define GERARDOSH_H

/*-------------------  Includes  -------------------*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>

/*-------------------  Constants  -------------------*/

#define MAX_INPUT_SIZE 1024

/*--------------  Function Prototypes  --------------*/

/* Tokenization */
int *tokenizing_init(char *line);
char **tokenize(char *line);

/* Command Execution */
void command(char **myargs);
int cd_command(char **myargs, int length);
void exit_command(char *command);

/* Pipelining */
int pipeline(char **myargs, int length);
void run_pipe(char ***commands, int number_commands);

/* Redirection */
int redirect(char **myargs, int length);

/* Main */
int main(void);

#endif