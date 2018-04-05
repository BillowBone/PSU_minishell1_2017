/*
** EPITECH PROJECT, 2018
** my_strncmp.c
** File description:
** my_strcmp function-like but for the n first characters
*/

#include "shell.h"

int my_strncmp2(char *str, char *str2, int n)
{
	int i = 0;

	if (my_strlen(str) < n || my_strlen(str2) < n)
		return (84);
	while (i < n) {
		if (str[i] < str2[i])
			return (-1);
		if (str[i] > str2[i])
			return (1);
		i = i + 1;
	}
	return (0);
}

int my_strncmp(char *str, char *str2, int n)
{
	int i = 0;

	if (my_strlen(str) < n || my_strlen(str2) < n)
		return (84);
	while (i < n) {
		if (str[i] < str2[i])
			return (-1);
		if (str[i] > str2[i])
			return (1);
		i = i + 1;
	}
	if (str2[i] != '=')
		return (-1);
	return (0);
}