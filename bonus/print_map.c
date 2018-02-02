/*
** EPITECH PROJECT, 2018
** print_map
** File description:
** paul-emile.leurs@epitech.eu
*/

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "bonus.h"

void print_map_two_player(char **map, int size, int line, int player)
{
	int i = 0;
	int size_line = my_strlen(map[0]);

	if (player == 0)
		mvprintw((LINES/2) + (line - (size/2)), (COLS/2) - (size_line)/2  - 2, "->");
	else
		mvprintw((LINES/2) + (line - (size/2)), (COLS/2) + (size_line)/2  + 2, "<-");
	while (map[i] != NULL) {
		if (i == line) {
			attron(A_DIM);
			mvprintw((LINES/2) + (i - (size/2)), (COLS/2) - (size_line)/2, map[i]);
			attroff(A_DIM);
		} else
			mvprintw((LINES/2) + (i - (size/2)), (COLS/2) - (size_line)/2, map[i]);
		i = i + 1;
	}
	refresh();
}
