##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for the minishell2 project
##

SRC	=	./src/main.c	\
		./src/env_list.c	\
		./src/my_putstr.c	\
		./src/my_strdup.c	\
		./src/my_strlen.c	\
		./src/my_strncmp.c	\
		./src/initialize_env.c	\
		./src/verify_args.c	\
		./src/initialize_shell.c	\
		./src/create_prompt.c	\
		./src/analyse_command.c	\
		./src/check_builtin.c	\
		./src/my_strcmp.c	\
		./src/my_setenv.c	\
		./src/get_nb_spaces.c	\
		./src/search_value.c	\
		./src/replace_full.c	\
		./src/my_unsetenv.c	\
		./src/my_exit.c	\
		./src/my_getnbr.c	\
		./src/my_cd.c	\
		./src/find_oldpwd.c	\
		./src/find_home.c	\
		./src/change_oldpwd.c	\
		./src/change_pwd.c	\
		./src/replace.c	\
		./src/my_exec.c	\
		./src/get_paths.c	\
		./src/my_strcpy.c	\
		./src/parse_args.c	\
		./src/invalid_command.c	\
		./src/no_command.c	\
		./src/my_env_len.c	\
		./src/env_origin.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -pedantic -I./include/

NAME	=	mysh

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc $(OBJ) $(CFLAGS) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all