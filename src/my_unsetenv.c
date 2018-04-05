/*
** EPITECH PROJECT, 2018
** my_unsetenv.c
** File description:
** Function that delete any variable in the env
*/

#include "shell.h"

void new_arg(char **parsed, char *arg, int *i, int j)
{
	int h = 0;

	while (arg[*i] != ' ' && arg[*i] != '\0') {
		parsed[j][h] = arg[*i];
		h = h + 1;
		*i = *i + 1;
	}
	parsed[j][h] = '\0';
}

char **parse_command(char *arg)
{
	char **parsed = malloc(sizeof(char *) * (get_nb_spaces(arg) + 2));
	int i = 0;
	int j = 0;
	int k = 0;

	while (arg[i] != '\0') {
		k = i;
		while (arg[k] != ' ' && arg[k] != '\0')
			k = k + 1;
		parsed[j] = malloc(sizeof(char) * (k + 1));
		new_arg(parsed, arg, &i, j);
		j = j + 1;
		if (arg[i] != '\0')
			i = i + 1;
	}
	parsed[j] = NULL;
	return (parsed);
}

int my_unsetenv(list *my_env, char *arg)
{
	int i = 0;
	char **parsed;

	if (arg == NULL) {
		write(2, "unsetenv: Too few arguments.\n", 29);
		return (0);
	}
	if (get_nb_spaces(arg) == 0) {
		deletion(my_env, arg);
		return (0);
	}
	if (get_nb_spaces(arg) > 0) {
		parsed = parse_command(arg);
		while (parsed[i] != NULL) {
			deletion(my_env, parsed[i]);
			i = i + 1;
		}
	}
	return (-1);
}