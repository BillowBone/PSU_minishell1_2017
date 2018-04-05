/*
** EPITECH PROJECT, 2018
** find_home.c
** File description:
** Function that returns the HOME value
*/

#include "shell.h"

char *get_home_value(char *value)
{
	char *home = malloc(sizeof(char) * (my_strlen(value) - 4));
	int i = 0;
	int j = 0;

	while (value[i] != '=')
		i = i + 1;
	i = i + 1;
	while (value[i] != '\0') {
		home[j] = value[i];
		i = i + 1;
		j = j + 1;
	}
	home[j] = '\0';
	return (home);
}

char *find_home(list *my_env)
{
	environment *home = my_env->first;
	int found = my_strncmp2(home->value, "HOME", 4);

	while (home->next != NULL && found != 0) {
		home = home->next;
		found = my_strncmp2(home->value, "HOME", 4);
	}
	if (found == 0)
		return (get_home_value(home->value));
	else {
		char *def = my_strdup("/home/");
		return (def);
	}
}