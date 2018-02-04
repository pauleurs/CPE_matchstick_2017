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
#include "my.h"

void redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test (str_to_int, read_line)
{
	int expected = 42;
	int got = str_to_int("42") ;

	cr_assert(got == expected);
}

Test (str_to_int_neg, read_line)
{
	int expected = -42;
	int got = str_to_int("-42") ;

	cr_assert(got == expected);
}

Test (my_strlen, read_line)
{
	char *str = {"tests tests"};
	int expected = strlen(str);
	int got = my_strlen(str);

	cr_assert(got == expected);
}

Test (my_putstr, simple_string, .init = redirect_all_std)
{
	my_putstr("hello world");
	cr_assert_stdout_eq_str("hello world");
}

Test (print_resume_player, simple_map, .init = redirect_all_std)
{
	print_resume(3, 3, 0);
	cr_assert_stdout_eq_str("Player removed 3 match(es) from line 3\n");
}

Test (print_resume_ia, simple_map, .init = redirect_all_std)
{
	print_resume(1, 10, 1);
	cr_assert_stdout_eq_str("AI removed 10 match(es) from line 1\n");
}
