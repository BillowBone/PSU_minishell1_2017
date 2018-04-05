/*
** EPITECH PROJECT, 2018
** my_cd.c
** File description:
** Function that makes all the chdir redirections
*/

#include "shell.h"

char *get_dir_arg(char *dir)
{
	char *arg = malloc(sizeof(char) * my_strlen(dir));
	int i = 0;
	int j = 0;

	if (my_strlen(dir) == 2)
		return (NULL);
	if (dir[2] != ' ')
		return (NULL);
	while (dir[i] != ' ')
		i = i + 1;
	i = i + 1;
	while (dir[i] != '\0') {
		arg[j] = dir[i];
		i = i + 1;
		j = j + 1;
	}
	arg[j] = '\0';
	return (arg);
}

int go_back(list *my_env, char *olddir, char oldpwd[1024])
{
	if (olddir != NULL) {
		change_oldpwd(my_env, oldpwd);
		chdir(olddir);
		change_pwd(my_env);
	} else {
		write(2, ": No such file or directory.\n", 29);
	}
	return (0);
}

int go_there(char *dir, list *my_env, char oldpwd[1024])
{
	if (chdir(dir) != 0) {
		my_putstr(dir);
		write(2, ": No such file or directory.\n", 29);
		return (-1);
	} else {
		change_oldpwd(my_env, oldpwd);
		change_pwd(my_env);
		return (0);
	}
	return (0);
}

int my_cd(char *dir, list *my_env)
{
	char *olddir = find_oldpwd(my_env);
	char oldpwd[1024];

	dir = get_dir_arg(dir);
	getcwd(oldpwd, sizeof(oldpwd));
	if (dir == NULL) {
		change_oldpwd(my_env, oldpwd);
		chdir(find_home(my_env));
		change_pwd(my_env);
		return (0);
	} else if (dir[0] == '-') {
		return (go_back(my_env, olddir, oldpwd));
	} else {
		return (go_there(dir, my_env, oldpwd));
	}
	return (-1);
}