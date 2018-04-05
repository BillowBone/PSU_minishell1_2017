/*
** EPITECH PROJECT, 2018
** change_oldpwd.c
** File description:
** Function that replace the OLDPWD value with the new one
*/

#include "shell.h"

char *get_whole_value(char *oldpwd)
{
	char *whole_value = malloc(sizeof(char) * (my_strlen(oldpwd) + 8));
	int i = 7;
	int j = 0;

	whole_value[0] = 'O';
	whole_value[1] = 'L';
	whole_value[2] = 'D';
	whole_value[3] = 'P';
	whole_value[4] = 'W';
	whole_value[5] = 'D';
	whole_value[6] = '=';
	while (oldpwd[j] != '\0') {
		whole_value[i] = oldpwd[j];
		i = i + 1;
		j = j + 1;
	}
	whole_value[i] = '\0';
	return (whole_value);
}

int change_oldpwd(list *my_env, char *oldpwd)
{
	environment *old = my_env->first;
	int found = my_strncmp2(old->value, "OLDPWD", 6);

	while (old->next != NULL && found != 0) {
		old = old->next;
		found = my_strncmp2(old->value, "OLDPWD", 6);
	}
	if (old->value != NULL && old->next == NULL)
		found = my_strncmp2(old->value, "OLDPWD", 6);
	if (found == 0)
		old->value = my_strdup(get_whole_value(oldpwd));
	else
		insertion(my_env, get_whole_value(oldpwd));
	return (0);
}