/*
** EPITECH PROJECT, 2018
** verify_args.c
** File description:
** Function that verify if there is nos argument passed as parameter of the minishell2
*/

#include "shell.h"

void verify_args(int argc)
{
	if (argc != 1) {
		write(2, "You don't need to put parameters\n", 34);
		exit(84);
	}
}