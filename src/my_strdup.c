/*
** EPITECH PROJECT, 2018
** my_strdup.c
** File description:
** my_strdup
*/

#include "shell.h"

char *my_strdup(char *str)
{
	char *dup = malloc(sizeof(char) * my_strlen(str) + 1);
	int i = 0;

	while (str[i] != '\0') {
		dup[i] = str[i];
		i = i + 1;
	}
	dup[i] = '\0';
	return (dup);
}