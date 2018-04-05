/*
** EPITECH PROJECT, 2018
** my_strcpy.c
** File description:
** my_strcpy.c
*/

#include "shell.h"

void my_strcpy(char *str, char *str2)
{
	int i = 0;
	int j = 0;

	while (str[i] != '\0') {
		i = i + 1;
	}
	while (str2[j] != '\0') {
		str[i] = str2[j];
		i = i + 1;
		j = j + 1;
	}
	str[i] = '\0';
}