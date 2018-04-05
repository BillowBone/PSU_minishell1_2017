/*
** EPITECH PROJECT, 2018
** my_exit.c
** File description:
** Function that exit with the expected value
*/

#include "shell.h"

int exit_value(char *command)
{
	int i = 0;
	char *value = malloc(sizeof(char) * my_strlen(command));
	int j = 0;
	int quit = -1;

	while (command[i] != ' ' && command[i] != '\0')
		i = i + 1;
	i = i + 1;
	while (command[i] != '\0') {
		value[j] = command[i];
		i = i + 1;
		j = j + 1;
	}
	value[j] = '\0';
	quit = my_getnbr(value);
	return (quit);
}

int my_exit(char *command)
{
	int value = 0;

	if (my_strlen(command) == 4)
		exit(0);
	value = exit_value(command);
	if (value != -66)
		exit(value);
	else
		write(2, "exit: Expression Syntax.\n", 25);
	return (-1);
}