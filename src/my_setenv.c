/*
** EPITECH PROJECT, 2018
** my_setenv.c
** File description:
** Function that apply the same setenv command as tcsh
*/

#include "shell.h"

char *set_value(char *str)
{
	char *value = malloc(sizeof(char) * my_strlen(str) + 1);
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] == ' ')
			value[i] = '=';
		else
			value[i] = str[i];
		i = i + 1;
	}
	value[i] = '\0';
	return (value);
}

char *first_arg(char *str)
{
	char *arg;
	int i = 0;

	while (str[i] != ' ')
		i = i + 1;
	arg = malloc(sizeof(char) * i);
	i = 0;
	while (str[i] != ' ') {
		arg[i] = str[i];
		i = i + 1;
	}
	arg[i] = '\0';
	return (arg);
}

char *add_equal(char *val)
{
	char *equal = malloc(sizeof(char) * my_strlen(val) + 1);
	int i = 0;

	while (val[i] != '\0') {
		equal[i] = val[i];
		i = i + 1;
	}
	equal[i] = '=';
	equal[i + 1] = '\0';
	return (equal);
}

int my_setenv_spaces(list *my_env, char *arg)
{
	int len = my_strlen(first_arg(arg));

	if (get_nb_spaces(arg) == 1) {
		if (search_value(my_env, first_arg(arg)) == 1) {
			replace_full(my_env, set_value(arg), len);
			return (0);
		} else {
			insertion(my_env, set_value(arg));
			return (0);
		}
	}
	if (get_nb_spaces(arg) > 1) {
		write(2, "setenv: Too many arguments.\n", 29);
		return (0);
	}
	return (-1);
}

int my_setenv(list *my_env, char *arg)
{
	if (arg == NULL) {
		display_env(my_env);
		return (0);
	}
	if (get_nb_spaces(arg) == 0) {
		if (search_value(my_env, arg) == 1) {
			replace(my_env, arg, my_strlen(arg));
			return (0);
		} else {
			insertion(my_env, add_equal(arg));
			return (0);
		}
	}
	return (my_setenv_spaces(my_env, arg));
}