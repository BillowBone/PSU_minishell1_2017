/*
** EPITECH PROJECT, 2018
** env_list.c
** File description:
** Functions that manages my chained list
*/

#include "shell.h"

list *create_list(void)
{
	struct list *my_list = malloc(sizeof(list));
	struct environment *my_env = malloc(sizeof(environment));

	if (my_list == NULL || my_env == NULL)
		exit(84);
	my_env->value = NULL;
	my_env->next = NULL;
	my_list->first = my_env;
	return (my_list);
}

void insertion(list *my_list, char *value)
{
	environment *my_env = malloc(sizeof(environment));
	environment *insert = malloc(sizeof(environment));

	if (my_list == NULL || value == NULL)
		exit(84);
	if (my_list->first->value == NULL) {
		my_list->first->value = my_strdup(value);
		free(my_env);
		free(insert);
	} else {
		my_env = my_list->first;
		while (my_env->next != NULL)
			my_env = my_env->next;
		insert->value = my_strdup(value);
		insert->next = NULL;
		my_env->next = insert;
	}
}

int deletion_end(environment *del, environment *prvs, int cmp)
{
	if (del->next != NULL) {
		prvs->next = del->next;
		free(del);
		return (0);
	}
	if (del->next == NULL && cmp == 0) {
		prvs->next = NULL;
		free(del);
		return (0);
	}
	return (-1);
}

int deletion(list *my_list, char *value)
{
	environment *previous = NULL;
	environment *del_list = my_list->first;
	int cmp = my_strncmp(value, del_list->value, my_strlen(value));

	while (del_list->next != NULL && cmp != 0) {
		previous = del_list;
		del_list = del_list->next;
		cmp = my_strncmp(value, del_list->value, my_strlen(value));
	}
	if (previous == NULL) {
		environment *to_delete = my_list->first;
		my_list->first = my_list->first->next;
		free(to_delete);
		return (0);
	}
	return (deletion_end(del_list, previous, cmp));
}

void display_env(list *my_list)
{
	environment *display = malloc(sizeof(environment));

	if (my_list == NULL)
		exit(84);
	display = my_list->first;
	while (display != NULL) {
		my_putstr(display->value);
		write(1, "\n", 1);
		display = display->next;
	}
	free(display);
}