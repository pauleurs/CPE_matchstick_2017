/*
** EPITECH PROJECT, 2018
** print.c
** File description:
** paul-emile.leurs@epitech.eu
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>

void print_map(char **map)
{
	int i = 0;
	int size = my_strlen(map[i]);

	while (map[i] != NULL) {
		write(1, map[i], size);
		write(1, "\n", 1);
		i = i + 1;
	}
}

void print_resume(int line, int matches, int player)
{
	if (player == 0)
		my_putstr("Player removed ");
	else
		my_putstr("IA removed ");
	my_put_nbr(matches);
	my_putstr(" match(es) from line ");
	my_put_nbr(line);
	my_putstr("\n");
}
