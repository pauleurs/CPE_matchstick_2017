/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** paul-emile.leurs@epitech.eu
*/

int my_strlen(char const *str)
{
	int size = 0;

	while (str[size] != '\0')
		size = size + 1;
	return (size);
}
