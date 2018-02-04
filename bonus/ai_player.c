/*
** EPITECH PROJECT, 2018
** ai_vs_player
** File description:
** paul-emile.leurs@epitech.eu
*/

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "bonus.h"

int counter_nb_mathches(char **map)
{

	int i = 1;
	int index = 1;
	int matches = 0;

	while (map[i] != NULL) {
		while (map[i][index] != '*') {
			if (map[i][index] == '|')
				matches = matches + 1;
			index = index + 1;
		}
		index = 1;
		i = i + 1;
	}
	return (matches);
}

int searche_nb_matches(char **map, int check)
{
	int matches = 0;
	int index = 1;
	int i = 1;

	while (map[i] != NULL) {
		while (map[i][index] != '*') {
			if (map[i][index] == '|')
				matches = matches + 1;
			if (check == matches)
				return (i);
			index = index + 1;
		}
		matches = 0;
		index = 1;
		i = i + 1;
	}
	return (-1);
}

int search_line_big_matches(int line, int *check, char **map)
{
	int i = 1;
	int big = 0;
	int index = 1;
	int matches = 0;

	while (map[i] != NULL) {
		while (map[i][index] != '*') {
			if (map[i][index] == '|')
				matches = matches + 1;
			index = index + 1;
		}
		if (big < matches) {
			line = i;
			big = matches;
			*check = matches;
		}
		matches = 0;
		index = 1;
		i = i + 1;
	}
	return (line);
}

char **management_ia_bonus(char **map, int max_matches)
{
	int nb_matches = counter_nb_mathches(map);
	int line = 0;
	int check = 1;

	if (nb_matches == 1) {
		line = search_line_big_matches(line, &check, map);
		map = remove_matches(map, line, check);
		return (map);
	}
	while (check < nb_matches) {
		check = check + max_matches + 1;
	}
	check = check - (max_matches + 1);
	check = nb_matches - check;
	line = searche_nb_matches(map, check);
	if (line == -1)
		line = search_line_big_matches(line, &check, map);
	move(3, COLS / 2 - 18);
	printw("line select : %d && %d matche(s) remove", line, check);
	return (remove_matches(map, line, check));
}

void management_ai_player(void)
{
	int size = size_map_ask();
	int max_matches = max_matches_ask();
	char **map = creat_map(size);
	char *name[2] = {"player", "ai"};

	while (1) {
		clear();
		recover_nb_line_1(size, map, name, max_matches);
		clear();
		mvprintw(0, (COLS / 2) - 2, "AI :");
		map = management_ia_bonus(map, max_matches);
		print_map(map, size);
		refresh();
		sleep(2);
	}
}
