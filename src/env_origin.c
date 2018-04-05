/*
** EPITECH PROJECT, 2018
** env_origin.c
** File description:
** Make the chained list env go back to a char** format
*/

#include "shell.h"

char **env_origin(list *my_env)
{
	char **origin = malloc(sizeof(char *) * (my_env_len(my_env) + 1));
	environment *current = my_env->first;
	int i = 0;

	while (current->next != NULL) {
		origin[i] = my_strdup(current->value);
		i = i + 1;
		current = current->next;
	}
	if (current->value != NULL) {
		origin[i] = my_strdup(current->value);
		origin[i + 1] = NULL;
	} else {
		origin[i] = NULL;
	}
	return (origin);
}