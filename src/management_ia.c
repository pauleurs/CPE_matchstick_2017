/*
** EPITECH PROJECT, 2018
** ia
** File description:
** paul_emile.leurs@epitech.eu
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>

int counter_nb_mathches(char **map)
{

	int i = 1;
	int index = 1;
	int matches = 0;

	while (map[i] != NULL) {
		while (map[i][index] != '*') {
			if (map[i][index] == '|')
				matches = matches + 1;
			index = index + 1;
		}
		index = 1;
		i = i + 1;
	}
	return (matches);
}

int searche_nb_matches(char **map, int check)
{
	int matches = 0;
	int index = 1;
	int i = 1;

	while (map[i] != NULL) {
		while (map[i][index] != '*') {
			if (map[i][index] == '|')
				matches = matches + 1;
			if (check == matches)
				return (i);
			index = index + 1;
		}
		matches = 0;
		index = 1;
		i = i + 1;
	}
	return (-1);
}

int search_line_big_matches(int line, int *check, char **map)
{
	int i = 1;
	int big = 0;
	int index = 1;
	int matches = 0;

	while (map[i] != NULL) {
		while (map[i][index] != '*') {
			if (map[i][index] == '|')
				matches = matches + 1;
			index = index + 1;
		}
		if (big < matches) {
			line = i;
			big = matches;
			*check = matches;
		}
		matches = 0;
		index = 1;
		i = i + 1;
	}       return (line);
}

static char **print_map_ia(char **map, int line, int check)
{
	map = remove_matches(map, line, check);
	print_resume(line, check, IA);
	print_map(map);
	return (map);
}

char **management_ia(char **map, int max_matches)
{
	int nb_matches = counter_nb_mathches(map);
	int line = 0;
	int check = 1;

	my_putstr("\nAI's turn...\n");
	if (nb_matches == 1) {
		line = search_line_big_matches(line, &check, map);
		map = remove_matches(map, line, check);
		print_resume(line, check, IA);
		print_map(map);
		return (map);
	}
	while (check <= nb_matches)
		check = check + max_matches + 1;
	check = check - (max_matches + 1);
	check = nb_matches - check;
	line = searche_nb_matches(map, check);
	if (line == -1)
		line = search_line_big_matches(line, &check, map);
	return (print_map_ia(map, line, check));
}
