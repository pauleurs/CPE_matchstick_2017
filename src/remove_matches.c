/*
** EPITECH PROJECT, 2018
** remove
** File description:
** paul-emile.leurs@epitech.eu
*/

#include "my.h"

char **remove_matches(char **map, int line, int matches)
{
	int size = my_strlen(map[line]) - 2;
	int i = 0;

	while (map[line][size] == ' ')
		size = size -1;
	while (matches != i) {
		map[line][size] = ' ';
		size = size - 1;
		i = i + 1;
	}
	return (map);
}
