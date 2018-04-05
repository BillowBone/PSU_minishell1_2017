/*
** EPITECH PROJECT, 2018
** replace_full.c
** File description:
** Same function as replace but this time with a whole value set
*/

#include "shell.h"

void replace_full(list *my_env, char *value, int cmp)
{
	environment *replace = my_env->first;

	if (value == NULL)
		exit(84);
	while (replace->next != NULL) {
		if (my_strncmp2(replace->value, value, cmp) == 0) {
			replace->value = my_strdup(value);
			break;
		}
		replace = replace->next;
	}
	if (replace->value != NULL && replace->next == NULL) {
		if (my_strncmp2(replace->value, value, cmp) == 0) {
			replace->value = my_strdup(value);
		}
	}
}