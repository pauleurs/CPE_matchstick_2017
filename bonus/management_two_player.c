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

char **creat_matches(char **map, int line)
{
	int i = 1;

	while (map[line][i] == ' ')
		i = i + 1;
	while (map[line][i] == '|')
		i = i + 1;
	map[line][i] = '|';
	return (map);
}

int check_line_win(int i, char **map)
{
	int index = 1;

	while (map[i][index] != '*') {
		if (map[i][index] == '|')
			return (-1);
		index = index + 1;
	}
	return (0);
}

int check_win(char **map, int player, char **name)
{
	int i = 0;

	while (map[i] != NULL) {
		if (check_line_win(i, map) == -1)
			return (-1);
		i = i + 1;
	}
	clear();
	move(LINES / 2, COLS / 2 - (my_strlen(map[player]) -2) / 2);
	if (player == 0) {
		printw("%s WIN", name[0]);
	} else
		printw("%s WIN", name[1]);
	refresh();
	sleep (2);
	return (0);
}

int management_two_player(void)
{
	char **name = name_player();
	int size = size_map_ask();
	int max_matches = max_matches_ask();
	char **map = creat_map(size);

	while (1) {
		clear();
		recover_nb_line_1(size, map, name, max_matches);
		if (check_win(map, 1, name) == 0)
			return (0);
		clear();
		recover_nb_line_2(size, map, name, max_matches);
		if (check_win(map, 0, name) == 0)
			return (0);
		refresh();
	}
	return (0);
}
