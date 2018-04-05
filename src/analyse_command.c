/*
** EPITECH PROJECT, 2018
** analyse_command.c
** File description:
** Function that checks if a command is a built-in, a binary or if it's invalid
*/

#include "shell.h"

char *remove_jump(char command[CMD_SIZE])
{
	char *cmd = malloc(sizeof(char) * my_strlen(command));
	int i = 0;

	while (command[i] != '\n' && command[i] != '\0') {
		cmd[i] = command[i];
		i = i + 1;
	}
	cmd[i] = '\0';
	return (cmd);
}

int analyse_command(char command[CMD_SIZE], list *my_env)
{
	char *cmd = remove_jump(command);
	char **paths;
	char **args;

	if (invalid_command(cmd) == -1) {
		write(1, "crash\n", 6);
		return (-1);
	}
	if (check_builtin(cmd, my_env) == 0)
		return (0);
	paths = get_paths(my_env);
	args = parse_args(cmd);
	if (my_exec(paths, my_env, args, cmd) == 0)
		return (0);
	return (-1);
}