/*
** EPITECH PROJECT, 2018
** check_player
** File description:
** paul-emile.leurs@epitech.eu
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>

int check_invalid_input(char *str)
{
	int i = 0;

	if (str[0] == '\0') {
		my_putstr("Error: invalid input (positive "     \
			  "number expected)\n");
		free (str);
		return (-1);
	}
	while (str[i] != '\0') {
		if (str[i] < '0' || str[i] > '9') {
			my_putstr("Error: invalid input (positive "     \
				  "number expected)\n");
			free (str);
			return (-1);
		}
		i = i + 1;
	}
	return (0);
}

int check_line_out_range(int line, int *nb, int check)
{
	 if (check == -1)
		return (-1);
	if (line > nb[0] || line < 1) {
		my_putstr("Error: this line is out of range\n");
		return (-1);
	} else
		my_putstr("Matches: ");
	return (check);
}

char *check_player_1(int *check, int *line, char *str_line, int *nb)
{
	my_putstr("Line: ");
	str_line = get_next_line(0);
	if (str_line == NULL)
		return (NULL);
	*check = check_invalid_input(str_line);
	*line = str_to_int(str_line);
	*check = check_line_out_range(*line, nb, *check);
	return (str_line);
}

char **check_player(char **map, int *nb, int check)
{
	static int line = 0;
	static int matches = 0;
	static char *str_line = NULL;
	static char *str_matches = NULL;

	while (check == -1) {
		str_line = check_player_1(&check, &line, str_line, nb);
		if (str_line == NULL)
			return (NULL);
		if (check != -1) {
			str_matches = get_next_line(0);
			if (str_matches == NULL)
				check = check_invalid_input(str_matches);
			matches = str_to_int(str_matches);
			if (check != -1)
				check = check_match(map, line, matches, nb);
		}
	}
	print_resume(line, matches, PLAYER);
	return (remove_matches(map, line, matches));
}
