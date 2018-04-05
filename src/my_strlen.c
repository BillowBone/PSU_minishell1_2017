/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** Function that returns the length of a string
*/

#include "shell.h"

int my_strlen(char *str)
{
	int i = 0;

	if (str == NULL)
		exit(84);
	while (str[i] != '\0')
		i = i + 1;
	return (i);
}