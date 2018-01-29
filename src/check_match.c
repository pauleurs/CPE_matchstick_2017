/*
** EPITECH PROJECT, 2018
** check_match.c
** File description:
** paul-emile.leurs@epitech.eu
*/

#include "my.h"

void check_match_1(char *str_matches, int max_matches)
{
	int i = 0;

	if (str_matches[0] == '\0') {
		my_putstr("Error: invalid input (positive "     \
			  "number expected)\nMatches: : ");
		str_matches = get_next_line(0);
		check_match(str_matches, max_matches);
	}
	while (str_matches[i] != '\0') {
		if (str_matches[i] < '0' || str_matches[i] > '9') {
			my_putstr("Error: invalid input (positive "     \
				  "number expected)\nMatches:  ");
			str_matches = get_next_line(0);
			check_match(str_matches, max_matches);
		}
		i = i + 1;
	}
}

int check_match(char *str_matches, int max_matches)
{
	static int matches = 0;

	check_match_1(str_matches, max_matches);
	matches = str_to_int(str_matches);
	if (matches < 1 || matches > max_matches) {
		my_putstr("Error: you cannot remove more than ");
		my_put_nbr(max_matches);
		my_putstr(" matches per turn\nMatches: ");
		str_matches = get_next_line(0);
		check_match(str_matches, max_matches);
	}
	return (matches);
}
