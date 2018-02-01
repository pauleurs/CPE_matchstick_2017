/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** paul-emile.leurs@epitech.eu
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>

int management_game(char **map, int *nb)
{
	print_map(map);
	while (1) {
		my_putstr("\nYour turn:\n");
		if ((map = check_player(map, nb, -1)) == NULL)
			return (0);
		print_map(map);
		if (check_win(map, PLAYER) == 0)
			return (2);
		map = management_ia(map, nb[1]);
		if (check_win(map, IA) == 0)
			return (1);
	}
	return (0);
}

int main(int ac, char **av)
{
	int parametre[2];
	char **map;

	if (ac != 3)
		return (84);
	parametre[0] = str_to_int(av[1]);
	if (parametre[0] <= 1 || parametre[0] >= 100)
		return (84);
	parametre[1] = str_to_int(av[2]);
	if (parametre[1] <= 0)
		return (84);
	map = creat_map(parametre[0]);
	return (management_game(map, parametre));
}
