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

void print_map_two_player(char **map, int size, int line)
{
	int i = 0;
	int size_line = my_strlen(map[0]);

	mvprintw((LINES/2) + (line - (size/2)), (COLS/2) - (size_line)/2  - 2, "->");
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

int nb_matches_line(int line, char **map)
{
	int i = 1;
	int nb_matches = 0;

	while (map[line][i] != '\0') {
		if (map[line][i] == '|')
			nb_matches = nb_matches + 1;
		i = i + 1;
	}
	return (nb_matches);
}

void choose_line(char **map, int *line, char **name, int size)
{
	int touch = 0;
	int check = 0;

	while (check == 0) {
		while (touch != 10) {
			if (touch == 258 && *line != size)
				*line = *line + 1;
			else if (touch == 259 && *line != 1)
				*line = *line - 1;
			print_map_two_player(map, size, *line);
			print_name_player(name, 0);
			refresh();
			touch = getch();
			clear();
		}
		touch = 0;
		check = nb_matches_line(*line, map);
		if (check == 0)
			mvprintw(1, (COLS / 2) - 5, "LINE EMPTY");
		refresh();
	}
}

void recover_nb_line(int size, char **map, char **name, int max_matches)
{
	int touch = 0;
	int line = 0;
	int delect = 0;
	
	while (nb_matches_line(line, map) == 0)
		line = line + 1;
	print_map_two_player(map, size, line);
	choose_line(map, &line, name, size);
	while (touch != 10) {
		clear();
		print_name_player(name, 0);
		if (touch == 32 && nb_matches_line(line, map) != 0 && delect != max_matches) {
			map = remove_matches(map, line, 1);
			delect = delect + 1;
		}
		print_map_two_player(map, size, line);
		refresh();
		touch = getch();
	}
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
		recover_nb_line(size, map, name, max_matches);
		refresh();
	}
	return (0);
}
