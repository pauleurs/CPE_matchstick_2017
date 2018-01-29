/*
** EPITECH PROJECT, 2018
** check_match.c
** File description:
** paul-emile.leurs@epitech.eu
*/

#include "my.h"

void check_match_1(char *str_matches, int max_matches, char **map, int line)
{
	int i = 0;

	if (str_matches[0] == '\0') {
		my_putstr("Error: invalid input (positive "     \
			  "number expected)\nMatches: : ");
		str_matches = get_next_line(0);
		check_match(str_matches, max_matches, map, line);
	}
	while (str_matches[i] != '\0') {
		if (str_matches[i] < '0' || str_matches[i] > '9') {
			my_putstr("Error: invalid input (positive "     \
				  "number expected)\nMatches:  ");
			str_matches = get_next_line(0);
			check_match(str_matches, max_matches, map, line);
		}
		i = i + 1;
	}
}

void check_matches_line(char **map, int line, int matches, int max_matches)
{
	int i = 0;
	int nb_matches = 0;
	char *str_matches;

	while (map[line][i] != '\0') {
		if (map[line][i] == '|')
			nb_matches = nb_matches + 1;
		i = i + 1;
	}
	if (nb_matches < matches) {
		my_putstr("Error: not enough matches on this line\nMatches: ");
		str_matches = get_next_line(0);
		check_match(str_matches, max_matches, map, line);
	}
}

int check_match(char *str_matches, int max_matches, char **map, int line)
{
	static int matches = 0;

	check_match_1(str_matches, max_matches, map, line);
	matches = str_to_int(str_matches);
	if (matches > max_matches) {
		my_putstr("Error: you cannot remove more than ");
		my_put_nbr(max_matches);
		my_putstr(" matches per turn\nMatches: ");
		str_matches = get_next_line(0);
		check_match(str_matches, max_matches, map, line);
	} if (matches < 1) {
		my_putstr("Error: you have to remove at least one "	\
			"match\nMatches: ");
		str_matches = get_next_line(0);
		check_match(str_matches, max_matches, map, line);
	}
	check_matches_line(map, line, matches, max_matches);
	return (matches);
}
