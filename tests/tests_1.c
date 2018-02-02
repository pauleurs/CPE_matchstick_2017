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

char *cut_str(char **rest, char *line, int size_read);
char *get_next_line (int fd);
int fd = -1;

void open_file (void)
{
	fd = open ("tests/data.txt", O_RDONLY );
	cr_redirect_stdout ();
}

void close_file (void)
{
	if (fd != -1)
		close (fd);
}

Test (get_next_line, read_line, . init = open_file , . fini = close_file ) {
	char *expected = "Confidence is so overrated.";
	char *got = get_next_line(fd) ;
	cr_assert_str_eq (got , expected) ;
}

Test (read_line_two, read_line , . init = open_file , . fini = close_file ) {
	char *expected = "ceci est un test";
	get_next_line(fd);
	char *got = get_next_line(fd);
	cr_assert_str_eq (got, expected);
}

Test (get_next_line_fd, read_line) {
	char *expected = "ok";
	char *test = "ok";
	char *got = get_next_line(-1);
	if (got != NULL)
		test = NULL;
	cr_assert_str_eq (test, expected);
}
