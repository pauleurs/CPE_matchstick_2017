/*
** EPITECH PROJECT, 2018
** game
** File description:
** paul-emile.leurs@epitech.eu
*/

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "bonus.h"

void print_choice(int select)
{
	if (select == 1) {
		attron(A_DIM | A_STANDOUT);
		mvprintw(10, (COLS/2) - 4, "- Two player");
		attroff(A_DIM | A_STANDOUT);
	} else
		mvprintw(10, (COLS/2) - 4, "- Two player");
	if (select == 2) {
		attron(A_DIM | A_STANDOUT);
		mvprintw(12, (COLS/2) - 4, "- IA vs player");
		attroff(A_DIM | A_STANDOUT);
	} else
		mvprintw(12, (COLS/2) - 4, "- IA vs player");
}

int print_choice_1(int select, int *touch)
{
	if (select == 3) {
		attron(A_DIM | A_STANDOUT);
		mvprintw(14, (COLS/2) - 4, "- Help");
		attroff(A_DIM | A_STANDOUT);
	} else
		mvprintw(14, (COLS/2) - 4, "- Help");
	if (select == 4) {
		attron(A_DIM | A_STANDOUT);
		mvprintw(16, (COLS/2) - 4, "- EXIT");
		attroff(A_DIM | A_STANDOUT);
	} else
		mvprintw(16, (COLS/2) - 4, "- Exit");
	*touch = getch();
	if (*touch == 258)
		select = select + 1;
	else if (*touch == 259)
		select = select - 1;
	return (select);
}

int selected_mod_game(void)
{
	int touch = -1;
	int select = 1;

	while (touch != 10) {
		attron(A_UNDERLINE | A_BOLD);
		mvprintw(4, (COLS/2) - 8, "Matchstick game :");
		attroff(A_UNDERLINE | A_BOLD);
		mvprintw(8, (COLS/2) - 8, "Game mode:");
		print_choice(select);
		select = print_choice_1(select, &touch);
		if (select == 5)
			select = 1;
		else if (select == 0)
			select = 4;
		refresh();
		clear();
	}
	return (select);
}
