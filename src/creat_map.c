/*
** EPITECH PROJECT, 2018
** creat_map.c
** File description:
** paul-emile.leurs@epitech.eu
*/

#include <stdlib.h>

char **malloc_map(int nb_line)
{
	int i = 0;
	char **map = malloc((nb_line + 3) * sizeof(char *));

	map[nb_line + 2] = NULL;
	map[0] = malloc((nb_line * 2 + 2) * sizeof(char));
	while (i != nb_line * 2 + 1) {
		map[0][i] = '*';
		i = i + 1;
	}
	map[0][i] = '\0';
	i = 1;
	while (i != nb_line + 2) {
		map[i] = malloc((nb_line * 2 + 2) * sizeof(char));
		i = i + 1;
	}
	i = 0;
	while (i != nb_line * 2 + 1) {
		map[nb_line + 1][i] = '*';
		i = i + 1;
	}
	map[nb_line + 1][i] = '\0';
	return (map);
}

char **write_matchstick(char **map, int nb_line, int index)
{
	static int nb_match = 1;
	int nb_space = (nb_line * 2 - nb_match - 1) / 2;
	int i = nb_space;
	int a = 0;

	while (i != nb_line * 2) {
		while (a != nb_match) {
			map[index][i + 1] = '|';
			a = a + 1;
			i = i + 1;
		}
		i = i + 1;
	}
	nb_match = nb_match + 2;
	return (map);
}

char **creat_map(int nb_line)
{
	char **map = malloc_map(nb_line);
	int index = 1;
	int i = 0;

	while (index != nb_line + 1) {
		while (i != nb_line * 2 + 1) {
			if (i == 0 || i == nb_line * 2)
				map[index][i] = '*';
			else
				map[index][i] = ' ';
			i = i + 1;
		}
		map[index][i] = '\0';
		map = write_matchstick(map, nb_line, index);
		index = index + 1;
		i = 0;
	}
	return (map);
}
