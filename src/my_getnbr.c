/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** my_getnbr.c
*/

#include "shell.h"

int my_getnbr(char const *str)
{
	int i = 0;
	int nb = 0;
	int check = 0;
	int neg = 0;

	while (check == 0) {
		neg = neg + negative(str, i);
		if (((str[i] < 48) || (str[i] > 57)) && (str[i] != '-')) {
			return (-66);
		}
		if ((str[i] > 47) && (str[i] < 58)) {
			nb = nb + str[i] - 48;
			nb = nb * 10;
		}
		check = end(str, i);
		i = i + 1;
	}
	nb = nb / 10;
	nb = nb * apply_negative(neg);
	return (nb);
}

int negative(char const *str, int i)
{
	if (str[i] == '-') {
		return (1);
	} else {
		return (0);
	}
}

int apply_negative(int neg)
{
	int i = 0;
	int neg2 = 1;

	while (i < neg) {
		neg2 = neg2 * (-1);
		i = i + 1;
	}
	neg = neg2;
	return (neg);
}

int end(char const *str, int i)
{
	if (((str[i + 1] < 48) || (str[i + 1] > 57)) && (str[i + 1] != '-')) {
		return (1);
	}
	return (0);
}
