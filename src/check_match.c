/*
** EPITECH PROJECT, 2018
** check_match.c
** File description:
** paul-emile.leurs@epitech.eu
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>

int check_matches_line(char **map, int line, int matches)
{
	int i = 0;
	int nb_matches = 0;

	while (map[line][i] != '\0') {
		if (map[line][i] == '|')
			nb_matches = nb_matches + 1;
		i = i + 1;
	}
	if (nb_matches < matches) {
		my_putstr("Error: not enough matches on this line\n");
		return (-1);
	}
	return (0);
}

int check_match(char **map, int line, int matches, int *nb)
{
	if (matches > nb[1]) {
		my_putstr("Error: you cannot remove more than ");
		my_put_nbr(nb[1]);
		my_putstr(" matches per turn\n");
		return (-1);
	} if (matches < 1) {
		my_putstr("Error: you have to remove at least one "	\
			"match\n");
		return (-1);
	}
	return (check_matches_line(map, line, matches));
}
