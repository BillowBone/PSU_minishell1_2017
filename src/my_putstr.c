/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** Function that displays a string
*/

#include "shell.h"

void my_putstr(char *str)
{
	int i = 0;

	if (str == NULL)
		exit(84);
	while (str[i] != '\0') {
		write(1, &str[i], 1);
		i = i + 1;
	}
}