/*
** EPITECH PROJECT, 2018
** find_oldpwd.c
** File description:
** Function that returns the OLDPWD value in the env
*/

#include "shell.h"

char *get_value(char *whole_value)
{
	char *value = malloc(sizeof(char) * (my_strlen(whole_value) - 6));
	int i = 0;
	int j = 0;

	while (whole_value[i] != '=')
		i = i + 1;
	i = i + 1;
	while (whole_value[i] != '\0') {
		value[j] = whole_value[i];
		i = i + 1;
		j = j + 1;
	}
	value[j] = '\0';
	return (value);
}

char *find_oldpwd(list *my_env)
{
	environment *oldpwd = my_env->first;
	int found = my_strncmp2(oldpwd->value, "OLDPWD", 6);

	while (oldpwd->next != NULL && found != 0) {
		oldpwd = oldpwd->next;
		found = my_strncmp2(oldpwd->value, "OLDPWD", 6);
	}
	if (found == 0)
		return (get_value(oldpwd->value));
	else
		return (NULL);
}