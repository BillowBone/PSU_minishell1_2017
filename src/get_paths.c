/*
** EPITECH PROJECT, 2018
** get_paths.c
** File description:
** get_paths.c
*/

#include "shell.h"

int nb_paths(char *path)
{
	int i = 0;
	int nb_paths = 0;

	while (path[i] != '\0') {
		if (path[i] == ':')
			nb_paths = nb_paths + 1;
		i = i + 1;
	}
	return (nb_paths + 1);
}

char *fill_path(char *path, int *i, int j)
{
	char *parsed = malloc(sizeof(char) * (j - *i + 1));
	int n = 0;

	while (path[*i] != ':' && path[*i] != '\0') {
		parsed[n] = path[*i];
		*i = *i + 1;
		n = n + 1;
	}
	parsed[n] = '/';
	parsed[n + 1] = '\0';
	return (parsed);
}

char **parse_path(char *path)
{
	char **parsed = malloc(sizeof(char *) * nb_paths(path));
	int i = 0;
	int j = 0;
	int k = 0;

	while (path[i] != '=' && path[i] != '\0')
		i = i + 1;
	if (path[i] == '=')
		i = i + 1;
	while (path[i] != '\0') {
		j = i;
		while (path[j] != ':' && path[j] != '\0')
			j = j + 1;
		parsed[k] = fill_path(path, &i, j);
		k = k + 1;
		if (path[i] != '\0')
			i = i + 1;
	}
	parsed[k] = NULL;
	return (parsed);
}

char **def_path(void)
{
	char **parsed = malloc(sizeof(char *) * 6);

	parsed[0] = my_strdup("/bin/");
	parsed[1] = my_strdup("/usr/bin/");
	parsed[2] = my_strdup("/usr/local/sbin/");
	parsed[3] = my_strdup("/usr/local/bin/");
	parsed[4] = my_strdup("/usr/sbin/");
	parsed[5] = NULL;
	return (parsed);
}

char **get_paths(list *my_env)
{
	environment *path = my_env->first;
	int found = my_strncmp2(path->value, "PATH", 4);

	while (path->next != NULL && found != 0) {
		path = path->next;
		found = my_strncmp2(path->value, "PATH", 4);
	}
	if (found == 0) {
		return (parse_path(path->value));
	} else {
		return (def_path());
	}
}