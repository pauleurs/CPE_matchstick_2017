/*
** EPITECH PROJECT, 2018
** player_one
** File description:
** paul-emile.leurs@epitech.eu
*/

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "bonus.h"

void choose_line(char **map, int *line, char **name, int size)
{
	int touch = 0;
	int check = 0;

	while (check == 0) {
		while (touch != 10) {
			if (touch == 259)
				touch = touch - 2;
			*line = compteur(touch + 1, 1, size, *line);
			print_map_two_player(map, size, *line, 0);
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

void delect_matches(char **map, int *parametre, char **name, int size)
{
	int touch = 0;
	int delect = 0;
	int line = parametre[0];

	while (touch != 10 || delect == 0) {
		clear();
		print_name_player(name, 0);
		if (touch == 32 && nb_matches_line(line, map)	\
		!= 0 && delect != parametre[1]) {
			map = remove_matches(map, line, 1);
			delect = delect + 1;
		} else if (touch == 263 && delect != 0) {
			map = creat_matches(map, line);
			delect = delect - 1;
		}
		move(3, COLS / 2 - 18);
		printw("line select : %d && %d matche(s) remove", line, delect);
		print_map_two_player(map, size, line, 0);
		refresh();
		touch = getch();
	}
}

void recover_nb_line_1(int size, char **map, char **name, int max_matches)
{
	int line = 0;
	int parametre[2];

	while (nb_matches_line(line, map) == 0)
		line = line + 1;
	parametre[1] = max_matches;
	print_map_two_player(map, size, line, 0);
	choose_line(map, &line, name, size);
	parametre[0] = line;
	delect_matches(map, parametre, name, size);
}
