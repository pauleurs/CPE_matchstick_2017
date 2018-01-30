/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** paul-emile.leurs@epitech.eu
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>

char **check_invalid_input(char *str, char **map, int *nb)
{
	int i = 0;

	if (str[0] == '\0') {
		my_putstr("Error: invalid input (positive "	\
			  "number expected)\n");
		free (str);
		return (check_player(map, nb));
	}
	while (str[i] != '\0') {
		if (str[i] < '0' || str[i] > '9') {
			my_putstr("Error: invalid input (positive "	\
				  "number expected)\n");
			free (str);
			return (check_player(map, nb));
		}
		i = i + 1;
	}
	return (NULL);
}

char **check_line_out_range(int line, int *nb, char **map)
{
	if (line > nb[0] || line < 1) {
		my_putstr("Error: this line is out of range\n");
		return (check_player(map, nb));
	} else
		my_putstr("Matches: ");
	return (NULL);
}

char **check_player(char **map, int *nb)
{
	static int line = 0;
	static int matches = 0;
	static char *str_line = NULL;
	static char *str_matches = NULL;

	my_putstr("Line: ");
	str_line = get_next_line(0);
	if (str_line == NULL)
		return (NULL);
	check_invalid_input(str_line, map, nb);
	line = str_to_int(str_line);
	check_line_out_range(line, nb, map);
	str_matches = get_next_line(0);
	if (str_matches == NULL)
		return (NULL);
	check_invalid_input(str_matches, map, nb);
	matches = str_to_int(str_matches);
	check_match(nb, map, line, matches);
	print_resume(line, matches, PLAYER);
	return (remove_matches(map, line, matches));
}

int management_game(char **map, int *nb)
{
	print_map(map);
	while (1) {
		my_putstr("\nYour turn:\n");
		if ((map = check_player(map, nb)) == NULL)
			return (0);
		print_map(map);
		if (check_win(map, PLAYER) == 0)
			return (2);
		map = management_ia(map, nb[1]);
		if (check_win(map, 1) == IA)
			return (1);
	}
	return (0);
}

int main(int ac, char **av)
{
	int parametre[2];
	char **map;

	if (ac != 3)
		return (84);
	parametre[0] = str_to_int(av[1]);
	if (parametre[0] <= 1 || parametre[0] >= 100)
		return (84);
	parametre[1] = str_to_int(av[2]);
	if (parametre[1] <= 0)
		return (84);
	map = creat_map(parametre[0]);
	return (management_game(map, parametre));
}
