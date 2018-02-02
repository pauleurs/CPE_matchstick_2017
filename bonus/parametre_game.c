/*
** EPITECH PROJECT, 2018
** game
** File description:
** paul-emile.leurs@epitech.Eu
*/

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "bonus.h"

int compteur(int touch, int min, int max, int nb)
{
	if (touch == 259 && nb != max)
		nb = nb + 1;
	else if (touch == 258 && nb != min)
		nb = nb - 1;
	return (nb);
}

int size_map_ask(void)
{
	int size = 2;
	int touch = 0;

	while (touch != 10) {
		clear();
		mvprintw((LINES / 2) - 3, (COLS / 2) - 19, "Select "	\
			"size map (max -> 35, min -> 2) :");
		move(LINES / 2, COLS / 2);
		size = compteur(touch, 2, 35, size);
		printw("%d\n", size);
		refresh();
		touch = getch();
	}
	return (size);
}

int max_matches_ask(void)
{
	int max = 1;
	int touch = 0;
	int i = 0;

	while (touch != 10) {
		clear();
		mvprintw((LINES / 2) - 3, (COLS / 2) - 29, "Maximum number of "\
			"matches that can be taken out each turn?");
		move(LINES / 2 - 1, COLS / 2);
		printw("%d\n", max);
		while (i != max) {
			mvprintw((LINES / 2), (COLS / 2) - (max / 2) + i, "|");
			i = i + 1;
		}
		i = 0;
		max = compteur(touch, 1, 70, max);
		refresh();
		touch = getch();
	}
	return (max);
}
