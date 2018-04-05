/*
** EPITECH PROJECT, 2018
** my_exec.c
** File description:
** Function that calls execve
*/

#include "shell.h"

int my_copy(char *paths, char *args, char *cmd, char *cmd2)
{
	paths[0] = '\0';
	args[0] = '\0';
	my_strcpy(paths, cmd);
	my_strcpy(args, cmd2);
	return (0);
}

void my_copy2(char *paths, char *args, char *cmd)
{
	cmd[0] = '\0';
	my_strcpy(cmd, paths);
	my_strcpy(paths, args);
	args[0] = '\0';
	my_strcpy(args, paths);
}

int my_exec(char **p, list *my_env, char **args, char *c)
{
	int i = 0;
	char *cmd2 = malloc(sizeof(char) * 100);
	char *cmd3 = malloc(sizeof(char) * 100);
	struct stat e;

	my_strcpy(cmd3, args[0]);
	while (p[i] != NULL) {
		my_copy2(p[i], args[0], cmd2);
		if ((lstat(p[i], &e) != -1) && (access(p[i], F_OK | X_OK) == 0)) {
			create_process(p[i], args, my_env);
			return (my_copy(p[i], args[0], cmd2, cmd3));
		}
		if ((lstat(c, &e) != -1) && (access(c, F_OK | X_OK) == 0)) {
			my_copy(p[i], args[0], cmd2, cmd3);
			return (create_process(args[0], args, my_env));
		}
		my_copy(p[i], args[0], cmd2, cmd3);
		i = i + 1;
	}
	return (no_command(c));
}

int create_process(char *path, char **args, list *my_env)
{
	pid_t pid = fork();
	int stat = 0;

	if (pid == 0) {
		if (execve(path, args, env_origin(my_env)) == -1)
			return (0);
		exit(0);
	}
	pid = wait(&stat);
	return (0);
}