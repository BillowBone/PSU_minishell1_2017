/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main function for the minishell2 project
*/

#include "shell.h"

int main(int argc, char *argv[], char *env[])
{
	list *my_env = create_list();
	int with_env = initialize_shell(argc, my_env, env);
	char *prompt = create_prompt(argv);
	char command[CMD_SIZE];
	int size = -1;

	if (with_env == -1)
		return (84);
	while (size != 0) {
		my_putstr(prompt);
		size = read(0, command, CMD_SIZE);
		if (size != 0)
			analyse_command(command, my_env);
	}
	return (0);
}