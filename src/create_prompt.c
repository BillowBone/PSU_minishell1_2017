/*
** EPITECH PROJECT, 2018
** create_prompt.c
** File description:
** Function that makes a prompt from the current name of the binary
*/

#include "shell.h"

char *create_prompt(char *argv[])
{
	int len = my_strlen(argv[0]);
	char *prompt = malloc(sizeof(char) * len + 3);
	int i = 1;

	prompt[0] = '[';
	while (i < len - 1) {
		prompt[i] = argv[0][i + 1];
		i = i + 1;
	}
	prompt[len - 1] = ']';
	prompt[len] = '$';
	prompt[len + 1] = ' ';
	prompt[len + 2] = '\0';
	return (prompt);
}