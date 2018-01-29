/*
** EPITECH PROJECT, 2018
** str_to_int
** File description:
** paul-emile.leurs@epitech.eu
*/

int str_to_int(char *str)
{
	int l = 0;
	int i = 0;

	if (str[0] == '-')
		i = i + 1;
	while (str[i] >= '0' && str[i] <= '9') {
		l = l * 10 + (str[i] - '0');
		i = i + 1;
	}
	if (str[0] == '-')
		l = l * (-1);
	return (l);
}
