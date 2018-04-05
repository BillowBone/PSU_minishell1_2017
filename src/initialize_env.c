/*
** EPITECH PROJECT, 2018
** initialize_env.c
** File description:
** Function that takes the env and fill a chained list with
*/

#include "shell.h"

int initialize_env(list *my_env, char *env[])
{
	int i = 0;

	if (env[0] == NULL)
		return (-1);
	while (env[i] != NULL) {
		insertion(my_env, env[i]);
		i = i + 1;
	}
	return (0);
}