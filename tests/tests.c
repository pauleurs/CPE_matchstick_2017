/*
** EPITECH PROJECT, 2018
** tests
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fcntl.h>
#include <unistd.h>

int str_to_int(char *str);

Test (str_to_int, read_line) {
	int expected = 42;
	int got = str_to_int("42") ;
	cr_assert(got == expected);
}

Test (str_to_int_neg, read_line) {
        int expected = -42;
        int got = str_to_int("-42") ;
        cr_assert(got == expected);
}
