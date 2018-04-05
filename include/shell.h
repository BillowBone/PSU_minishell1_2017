/*
** EPITECH PROJECT, 2018
** shell.h
** File description:
** Header file for the minishell2 project
*/

#ifndef SHELL_H_
	#define SHELL_H_

#ifndef CMD_SIZE
#define CMD_SIZE 1000
#endif /* !CMD_SIZE_ */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "environment.h"

char *get_home_value(char *value);
char *find_home(list *my_env);
void my_putstr(char *str);
int my_env_len(list *my_env);
int my_copy(char *paths, char *args, char *cmd, char *cmd2);
void my_copy2(char *paths, char *args, char *cmd);
int my_exec(char **p, list *my_env, char **args, char *c);
int create_process(char *path, char **args, list *my_env);
void replace_full(list *my_env, char *value, int cmp);
char **env_origin(list *my_env);
void new_arg(char **parsed, char *arg, int *i, int j);
char **parse_command(char *arg);
int my_unsetenv(list *my_env, char *arg);
char *parse_env_commands(char *command);
int check_builtin_end(char *command);
int check_builtin(char *command, list *my_env);
list *create_list(void);
void insertion(list *my_list, char *value);
int deletion_end(environment *del, environment *prvs, int cmp);
int deletion(list *my_list, char *value);
void display_env(list *my_list);
int search_value(list *my_env, char *value);
int initialize_env(list *my_env, char *env[]);
int my_strcmp(char *str, char *str2);
int my_strncmp2(char *str, char *str2, int n);
int my_strncmp(char *str, char *str2, int n);
char *get_dir_arg(char *dir);
int go_back(list *my_env, char *olddir, char oldpwd[1024]);
int go_there(char *dir, list *my_env, char oldpwd[1024]);
int my_cd(char *dir, list *my_env);
int nb_args(char *command);
char *fill_args(char *command, int *i, int j);
char **parse_args(char *command);
int get_nb_spaces(char *str);
int nb_paths(char *path);
char *fill_path(char *path, int *i, int j);
char **parse_path(char *path);
char **def_path(void);
char **get_paths(list *my_env);
void replace(list *my_env, char *value, int cmp);
int invalid_command(char *cmd);
int initialize_shell(int argc, list *my_env, char *env[]);
void verify_args(int argc);
char *my_strdup(char *str);
int my_strlen(char *str);
int exit_value(char *command);
int my_exit(char *command);
char *set_value(char *str);
char *first_arg(char *str);
char *add_equal(char *val);
int my_setenv_spaces(list *my_env, char *arg);
int my_setenv(list *my_env, char *arg);
int no_command(char *command);
char *set_pwd_value(char pwd[1024]);
void change_pwd(list *my_env);
char *remove_jump(char command[CMD_SIZE]);
int analyse_command(char command[CMD_SIZE], list *my_env);
int my_getnbr(char const *str);
int negative(char const *str, int i);
int apply_negative(int neg);
int end(char const *str, int i);
char *get_whole_value(char *oldpwd);
int change_oldpwd(list *my_env, char *oldpwd);
void my_strcpy(char *str, char *str2);
char *create_prompt(char *argv[]);
char *get_value(char *whole_value);
char *find_oldpwd(list *my_env);
int main(int argc, char *argv[], char *env[]);

#endif /* !SHELL_H_ */