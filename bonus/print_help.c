/*
** EPITECH PROJECT, 2018
** print_help
** File description:
** paul-emile.leurs@epitech.eu
*/

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "bonus.h"

static void print_help_2(void)
{
	mvprintw(4, (COLS / 2) - 7, "MATCHSTICK GAME");
}

static void print_help_1(int select)
{
	mvprintw(1, (COLS / 2) - 3, "HELP :");
	if (select == 0) {
		attron(A_DIM | A_STANDOUT);
		mvprintw(LINES / 2, 1, "RESUME");
		attroff(A_DIM | A_STANDOUT);
	} else
		mvprintw(LINES / 2, 1, "RESUME");
	if (select == 1) {
		attron(A_DIM | A_STANDOUT);
		mvprintw(LINES / 2, COLS - 5, "EXIT");
		attroff(A_DIM | A_STANDOUT);
	} else
		mvprintw(LINES / 2, COLS - 5, "EXIT");
	print_help_2();
	refresh();
}

int print_help(void)
{
	int touch = 0;
	int select = 0;

	while (touch != 10) {
		print_help_1(select);
		touch = getch();
		if (touch == 260)
			select = 0;
		else if (touch == 261)
			select = 1;
		clear();
	}
	if (select == 0) {
		flash();
		main();
	}
	return (0);
}
