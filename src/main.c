/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** paul-emile.leurs@epitech.eu
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>

char **remove_matches(char **map, int line, int matches)
{
	int size = my_strlen(map[line]) - 2;
	int i = 0;
	while (map[line][size] == ' ')
		size = size -1;
	while (matches != i) {
		map[line][size] = ' ';
		size = size - 1;
		i = i + 1;
	}
	return (map);
}

int counter_nb_mathches(char **map) {

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
	int index = 0;
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
        }	return (line);
}

char **management_ia(char **map, int max_matches)
{
	int nb_matches = counter_nb_mathches(map);
	int line = 0;
	int check = 1;
	
	while (check <= nb_matches)
		check = check + max_matches + 1;
	check = check - (max_matches + 1);
	check = nb_matches - check;
	line = searche_nb_matches(map, check);
	if (line == -1)
		line = search_line_big_matches(line, &check, map);
	map = remove_matches(map, line, check);
	my_putstr("AI's turn...\n");
	print_resume(line, check, 1);
	print_map(map);
	return (map);
}

int management_game(char **map, int nb_line, int max_matches)
{
	char *str_line = NULL;
	char *str_matches = NULL;
	int line = 0;
	int matches = 0;

	print_map(map);
	while (1) {
		write(1, "Your turn:\nLine: ", 17);
		str_line = get_next_line(0);
		line = check_nb_line(str_line, nb_line);
		my_putstr("Matches: ");
		str_matches = get_next_line(0);
		matches = check_match(str_matches, max_matches, map, line);
		print_resume(line, matches, 0);
		map = remove_matches(map, line, matches);
		print_map(map);
		if (check_win(map, 0) == 0)
			return (2);
		map = management_ia(map, max_matches);
		if (check_win(map, 1) == 0)
	                return (1);
	}
}

int main(int ac, char **av)
{
	int nb_line = 0;
	int max_matches = 0;
	char **map;

	if (ac != 3)
		return (84);
	nb_line = str_to_int(av[1]);
	max_matches = str_to_int(av[2]);
	map = creat_map(nb_line);
	return (management_game(map, nb_line, max_matches));
}
