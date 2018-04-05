/*
** EPITECH PROJECT, 2018
** no_command.c
** File description:
** Function that display command not found
*/

#include "shell.h"

int no_command(char *command)
{
	my_putstr(command);
	write(2, ": Command not found.\n", 21);
	return (-1);
}