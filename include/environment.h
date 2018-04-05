/*
** EPITECH PROJECT, 2018
** environment.h
** File description:
** Header file for the chained list to manage the env
*/

#ifndef ENVIRONMENT_H_
	#define ENVIRONMENT_H_

typedef struct environment environment;
struct environment {
	char *value;
	environment *next;
};

typedef struct list list;
struct list {
	environment *first;
};

#endif /* !ENVIRONMENT_H_ */
