/*
** EPITECH PROJECT, 2018
** two_player
** File description:
** paul-emile.leurs@epitech.eu
*/

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "bonus.h"

int size_map_ask(void)
{
	int size = 2;
	int touch = 0;

	while (touch != 10) {
		clear();
		mvprintw((LINES/2)-3, (COLS/2) - 19, "Select size map (max -> 35, min -> 2) :");
		move(LINES/2, COLS/2);
		if (touch == 259)
			size = size + 1;
		else if (touch == 258)
			size = size - 1;
		if (size == 36)
			size = 35;
		else if (size == 1)
			size = 2;
		printw("%d\n", size);
		refresh();
		touch = getch();
	}
	clear();
	return (size);
}

int max_matches_ask(void)
{
	int max = 1;
	int touch = 0;
	int i = 0;

	while (touch != 10) {
		clear();
		mvprintw((LINES/2)-3, (COLS/2) - 29, "Maximum number of "\
			"matches that can be taken out each turn?");
		move(LINES/2 - 1, COLS/2);
		printw("%d\n", max);
		while (i != max) {
			mvprintw((LINES/2), (COLS/2) - (max/2) + i,"|");
			i = i + 1;
		}
		i = 0;
		if (touch == 259 && max != 70)
			max = max + 1;
		else if (touch == 258 && max != 1)
			max = max - 1;
		refresh();
		touch = getch();
	}
	clear();
	return (max);
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
	mvprintw((LINES/2) - 10, (COLS / 2) - 25, "Name Player 1 (max 20) : ");
	move((LINES / 2 - 10), COLS / 2);
	getnstr(name[0], 20);
	mvprintw((LINES/2) - 6, (COLS / 2) - 25, "Name Player 2 (max 20) : ");
	move((LINES/2 - 6), COLS / 2);
	getnstr(name[1], 20);
	refresh();
	return (name);
}

int print_name_player(char **name)
{
	int size = 0;
	int size_1 = 0;

	if (name == NULL)
		return (0);
	attron(A_UNDERLINE | A_BOLD);
	size = my_strlen(name[0]);
	size_1 = my_strlen(name[1]);
	move(0, size/2);
	printw("%s\n", name[0]);
	move(0, COLS - size_1 - (size_1 / 2));
	printw("%s\n", name[1]);
	attroff(A_UNDERLINE | A_BOLD);
	refresh();
	return (0);
}

int recover_nb_line(int *matches)
{
	int line = 0;
	int tempo = 0;
	static int round = 1;

	move(2, 1);
	printw("round : %d\n",round);
	mvprintw(3, 1, "Line: ");
	move(3, 8);
	scanw("%d", &line);
	mvprintw(3, 15, "Matches: ");
	move(3, 25);
	scanw("%d", &tempo);
	*matches = tempo;
	round = round + 1;
	return (line);
}

int management_two_player(void)
{
	char **name = name_player();
	int size = size_map_ask();
	int max_matches = max_matches_ask();
	char **map = creat_map(size);
	int line = 0;
	int matches = 0;

	while (1) {
		clear();
		print_name_player(name);
		print_map(map, size);
		line =recover_nb_line(&matches);
		map = remove_matches(map, line, matches);
		refresh();
	}
	return (0);
}
