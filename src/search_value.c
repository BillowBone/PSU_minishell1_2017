/*
** EPITECH PROJECT, 2018
** search_value.c
** File description:
** Function that search a value in my env
*/

#include "shell.h"

int search_value(list *my_env, char *value)
{
	environment *search = my_env->first;

	if (value == NULL)
		return (-1);
	while (search->next != NULL) {
		if (my_strncmp2(search->value, value, my_strlen(value)) == 0)
			return (1);
		search = search->next;
	}
	if (search->value != NULL) {
		if (my_strncmp2(search->value, value, my_strlen(value)) == 0)
			return (1);
	}
	return (0);
}