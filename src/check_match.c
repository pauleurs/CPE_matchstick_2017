/*
** EPITECH PROJECT, 2018
** check_match.c
** File description:
** paul-emile.leurs@epitech.eu
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>

char **check_matches_line(char **map, int line, int matches, int *nb)
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
		return (check_player(map, nb));
	}
	return (NULL);
}

char **check_match(int *nb, char **map, int line, int matches)
{
	if (matches > nb[1]) {
		my_putstr("Error: you cannot remove more than ");
		my_put_nbr(nb[1]);
		my_putstr(" matches per turn\n");
		return (check_player(map, nb));
	} if (matches < 1) {
		my_putstr("Error: you have to remove at least one "	\
			"match\n");
		return (check_player(map, nb));
	}
	check_matches_line(map, line, matches, nb);
	return (NULL);
}
