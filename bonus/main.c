/*
** EPITECH PROJECT, 2018
** main_bonus.c
** File description:
** paul-emile.leurs@epitech.eu
*/

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "bonus.h"

static void ncurses(void)
{
	initscr();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(FALSE);
}

void print_map(char **map, int size)
{
	int i = 0;
	int size_line = my_strlen(map[0]);

	while (map[i] != NULL) {
		mvprintw((LINES / 2) + (i - (size / 2)), \
			(COLS / 2) - (size_line) / 2, map[i]);
		i = i + 1;
	}
	refresh();
}

int main(void)
{
	int game = 0;

	ncurses();
	game = selected_mod_game();
	if (game == 1) {
		mvprintw((LINES / 2), (COLS / 2) - 5, "TWO PLAYER");
		refresh();
		usleep(900000);
		management_two_player();
	} else if (game == 2) {
		mvprintw((LINES / 2), (COLS / 2) - 6, "PLAYER VS IA");
		refresh();
		usleep(900000);
		management_ai_player();
	} else if (game == 3)
		print_help();
	endwin();
	return (0);
}
