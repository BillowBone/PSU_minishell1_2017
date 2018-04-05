/*
** EPITECH PROJECT, 2018
** initialize_shell.c
** File description:
** Function that checks if there is arguments and if there is an env
*/

#include "shell.h"

int initialize_shell(int argc, list *my_env, char *env[])
{
	verify_args(argc);
	return (initialize_env(my_env, env));
}