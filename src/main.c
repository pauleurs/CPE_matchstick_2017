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

void management_game(char **map, int nb_line, int max_matches)
{
	char *str_line = NULL;
	char *str_matches = NULL;
	int line = 0;
	int matches = 0;

	while (1) {
		print_map(map);
		write(1, "Your turn:\nLine: ", 17);
		str_line = get_next_line(0);
		line = check_nb_line(str_line, nb_line);
		my_putstr("Matches: ");
		str_matches = get_next_line(0);
		matches = check_match(str_matches, max_matches);
		print_resume(line, matches, 0);
		map = remove_matches(map, line, matches);
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
	management_game(map, nb_line, max_matches);
	return (0);
}
