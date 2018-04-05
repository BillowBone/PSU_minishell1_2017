/*
** EPITECH PROJECT, 2018
** parse_args.c
** File description:
** Function that transform the command line into a char **
*/

#include "shell.h"

int nb_args(char *command)
{
	int i = 0;
	int nb_args = 0;

	while (command[i] != '\0') {
		if (command[i] == ' ')
			nb_args = nb_args + 1;
		i = i + 1;
	}
	return (nb_args + 1);
}

char *fill_args(char *command, int *i, int j)
{
	char *parsed = malloc(sizeof(char) * (j - *i + 1));
	int n = 0;

	while (command[*i] != ' ' && command[*i] != '\0') {
		parsed[n] = command[*i];
		*i = *i + 1;
		n = n + 1;
	}
	parsed[n] = '\0';
	return (parsed);
}

char **parse_args(char *command)
{
	char **parsed = malloc(sizeof(char *) * nb_args(command));
	int i = 0;
	int j = 0;
	int k = 0;

	while (command[i] != '\0') {
		j = i;
		while (command[j] != ' ' && command[j] != '\0')
			j = j + 1;
		parsed[k] = fill_args(command, &i, j);
		k = k + 1;
		if (command[i] != '\0')
			i = i + 1;
	}
	parsed[k] = NULL;
	return (parsed);
}