/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** paul-emile.leurs@epitech.eu
*/

#include <unistd.h>
#include "my.h"

void my_putstr(char *const str)
{
	int size = my_strlen(str);

	write (1, str, size);
}
