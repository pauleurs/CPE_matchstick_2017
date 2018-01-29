/*
** EPITECH PROJECT, 2018
** my_put_str.c
** File description:
** paul-emile.leurs@epitech.eu
*/

#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}

void my_put_nbr_1(int nb)
{
	int power = 1;

	while (nb / power != 0) {
		power *= 10;
	}
		power /= 10;
		while  (power != 0) {
		my_putchar(nb / power + 48);
		nb %= power;
		power /= 10;
	}
}

int my_put_nbr(int nb)
{
	if (nb < 0) {
		my_putchar('-');
		nb = - nb;
	} else {
		if (nb == 0)
			my_putchar('0');
	}
	my_put_nbr_1(nb);
	return (1);
}
