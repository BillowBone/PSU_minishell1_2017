/*
** EPITECH PROJECT, 2018
** get_nb_spaces.c
** File description:
** Function that returns the number of spaces in a string
*/

#include "shell.h"

int get_nb_spaces(char *str)
{
	int i = 0;
	int nb_spaces = 0;

	if (str == NULL)
		return (0);
	while (str[i] != '\0') {
		if (str[i] == ' ')
			nb_spaces = nb_spaces + 1;
		i = i + 1;
	}
	return (nb_spaces);
}