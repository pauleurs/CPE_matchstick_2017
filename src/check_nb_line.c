/*
** EPITECH PROJECT, 2018
** checked_nb_line.c
** File description:
** paul-emile.leurs@epitech.eu
*/

#include "my.h"

void check_nb_line_1(char *str_line, int nb_line)
{
	int i = 0;

	if (str_line[0] == '\0') {
		my_putstr("Error: invalid input (positive "\
			"number expected)\nLine: ");
		str_line = get_next_line(0);
		check_nb_line(str_line, nb_line);
	}
	while (str_line[i] != '\0') {
		if (str_line[i] < '0' || str_line[i] > '9') {
			my_putstr("Error: invalid input (positive "\
				"number expected)\nLine: ");
			str_line = get_next_line(0);
			check_nb_line(str_line, nb_line);
		}
		i = i + 1;
	}
}

int check_nb_line(char *str_line, int nb_line)
{
	static int line = 0;

	check_nb_line_1(str_line, nb_line);
	line = str_to_int(str_line);
	if (line > nb_line || line < 1) {
		my_putstr("Error: this line is out of range\nLine: ");
		str_line = get_next_line(0);
		check_nb_line(str_line, nb_line);
	} else
		return (line);
	return (line);
}
