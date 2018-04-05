/*
** EPITECH PROJECT, 2018
** my_env_len.c
** File description:
** Function that returns the number of variables inside of the env
*/

#include "shell.h"

int my_env_len(list *my_env)
{
	environment *current = my_env->first;
	int i = 0;

	while (current->next != NULL) {
		current = current->next;
		i = i + 1;
	}
	return (i + 1);
}