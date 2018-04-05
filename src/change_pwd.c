/*
** EPITECH PROJECT, 2018
** change_pwd.c
** File description:
** Function that actualize the PWD value in my env
*/

#include "shell.h"

char *set_pwd_value(char pwd[1024])
{
	char *value = malloc(sizeof(char) * (my_strlen(pwd) + 5));
	int i = 4;
	int j = 0;

	value[0] = 'P';
	value[1] = 'W';
	value[2] = 'D';
	value[3] = '=';
	while (pwd[j] != '\0') {
		value[i] = pwd[j];
		i = i + 1;
		j = j + 1;
	}
	value[i] = '\0';
	return (value);
}

void change_pwd(list *my_env)
{
	char pwd[1024];
	environment *current = my_env->first;
	int found = my_strncmp2(current->value, "PWD", 3);

	getcwd(pwd, sizeof(pwd));
	while (current->next != NULL && found != 0) {
		current = current->next;
		found = my_strncmp2(current->value, "PWD", 3);
	}
	if (current->value != NULL && current->next == NULL)
		found = my_strncmp2(current->value, "PWD", 3);
	if (found == 0)
		current->value = my_strdup(set_pwd_value(pwd));
	else
		insertion(my_env, set_pwd_value(pwd));
}