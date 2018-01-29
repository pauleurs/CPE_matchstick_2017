/*
** EPITECH PROJECT, 2018
** check_win.c
** File description:
** paul-emile.leurs@epitech.eu
*/

#include "my.h"
#include <unistd.h>

void print_final(int player)
{
	if (player == 0)
		my_putstr("You lost, too bad...\n");
	else
		my_putstr("I lost... snif... but I'll get you next time!!\n");
}

int check_line_win(int i, char **map)
{
	int index = 1;

	while (map[i][index] != '*') {
		if (map[i][index] == '|')
			return (-1);
		index = index + 1;
	}
	return (0);
}

int check_win(char **map, int player)
{
	int i = 0;

	while (map[i] != NULL) {
		if (check_line_win(i, map) == -1)
			return (-1);
		i = i + 1;
	}
	print_final(player);
	return (0);
}
