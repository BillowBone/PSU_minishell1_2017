/*
** EPITECH PROJECT, 2018
** invalid_command.c
** File description:
** Function that checks if a command is valid or not
*/

#include "shell.h"

int invalid_command(char *cmd)
{
	int i = 0;
	int invalid = 0;

	while (cmd[i] != '\0') {
		if (cmd[i] == ' ' || cmd[i] == '\t' || cmd[i] == 0)
			invalid = invalid + 1;
		i = i + 1;
	}
	if (invalid == i)
		return (-1);
	return (0);
}