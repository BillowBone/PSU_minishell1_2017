/*
** EPITECH PROJECT, 2018
** replace.c
** File description:
** Function that replace a value by another in the env
*/

#include "shell.h"

void replace(list *my_env, char *value, int cmp)
{
	environment *replace = my_env->first;

	if (value == NULL)
		exit(84);
	while (replace->next != NULL) {
		if (my_strncmp2(replace->value, value, cmp) == 0) {
			replace->value = my_strdup(add_equal(value));
			break;
		}
		replace = replace->next;
	}
	if (replace->value != NULL) {
		if (my_strncmp2(replace->value, value, cmp) == 0)
			replace->value = my_strdup(add_equal(value));
	}
}