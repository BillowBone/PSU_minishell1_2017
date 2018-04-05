/*
** EPITECH PROJECT, 2018
** check_builtin.c
** File description:
** Function that check if a command is builtin or not and execute it
*/

#include "shell.h"

char *parse_env_commands(char *command)
{
	char *parsed;
	int i = 0;
	int j = 0;

	if (my_strcmp(command, "setenv") == 0
	|| my_strcmp(command, "unsetenv") == 0)
		return (NULL);
	while (command[i] != ' ' && command[i] != '\0')
		i = i + 1;
	if (command[i] == '\0')
		return (NULL);
	parsed = malloc(sizeof(char) * (my_strlen(command) - i));
	i = i + 1;
	while (command[i] != '\0') {
		parsed[j] = command[i];
		i = i + 1;
		j = j + 1;
	}
	parsed[j] = '\0';
	return (parsed);
}

int check_builtin_end(char *command)
{
	if (my_strncmp2(command, "exit ", 5) == 0)
		my_exit(command);
	if (my_strcmp(command, "exit") == 0)
		my_exit(command);
	return (-1);
}

int check_builtin(char *command, list *my_env)
{
	if (my_strncmp2(command, "cd", 2) == 0) {
		my_cd(command, my_env);
		return (0);
	}
	if (my_strncmp2(command, "env", 3) == 0) {
		display_env(my_env);
		return (0);
	}
	if (my_strncmp2(command, "setenv", 6) == 0) {
		my_setenv(my_env, parse_env_commands(command));
		return (0);
	}
	if (my_strncmp2(command, "unsetenv", 8) == 0) {
		my_unsetenv(my_env, parse_env_commands(command));
		return (0);
	}
	return (check_builtin_end(command));
}