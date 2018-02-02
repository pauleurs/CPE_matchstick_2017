/*
** EPITECH PROJECT, 2018
** name_player.c
** File description:
** paul-emile.leurs@epitech.eu
*/

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "bonus.h"

int print_name_player(char **name, int player)
{
	int size = my_strlen(name[player]);

	attron(A_UNDERLINE | A_BOLD);
	move(0, COLS / 2 - size / 2);
	printw("%s\n", name[player]);
	attroff(A_UNDERLINE | A_BOLD);
	refresh();
	return (0);
}

char **name_player(void)
{
	char **name;

	echo();
	clear();
	name = malloc((2) * sizeof(char *));
	name[0] = malloc((20) * sizeof(char *));
	name[1] = malloc((20) * sizeof(char *));
	if (name == NULL || name[0] == NULL || name[1] == NULL)
		return (NULL);
	mvprintw((LINES / 2) - 10, (COLS / 2) - 25, "Name Player 1 (max 20) : ");
	move((LINES / 2 - 10), COLS / 2);
	getnstr(name[0], 20);
	mvprintw((LINES / 2) - 6, (COLS / 2) - 25, "Name Player 2 (max 20) : ");
	move((LINES / 2 - 6), COLS / 2);
	getnstr(name[1], 20);
	refresh();
	return (name);
}
