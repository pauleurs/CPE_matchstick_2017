/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** paul-emile.leurs@epitch.eu
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

static char *str_cpy(char *dest, char *str, int *i, int index)
{
	while (str[index] != '\0') {
		dest[*i] = str[index];
		*i = *i + 1;
		index = index + 1;
	}
	return (dest);
}

char *new_line(char *line, char *buff, char *rest, int size_read, int check)
{
	int i = 0;
	int index = 0;
	char *tempo = malloc((READ_SIZE + 100) * sizeof(char));

	if (tempo == NULL)
		return (NULL);
	if (rest != NULL && check == 0)
		tempo = str_cpy(tempo, rest, &i, 0);
	if (line != NULL) {
		tempo = str_cpy(tempo, line, &i, 0);
		free (line);
	}
	while (index != size_read) {
		tempo[i] = buff[index];
		i = i + 1;
		index = index + 1;
	}
	if (tempo[i - 1] == '\n')
		tempo[i - 1] = '\0';
	else
		tempo[i] = '\0';
	return (tempo);
}

char *cut_str(char **rest, char *line, int size_read)
{
	int i = 0;
	int index = 0;
	int save = 0;

	if (line == NULL)
		return (NULL);
	while (line[i] != '\n' && line[i] != '\0')
		i = i + 1;
	save = i;
	i = i + 1;
	if (size_read == 0 || size_read != READ_SIZE) {
		line[save] = '\0';
		return (line);
	}
	while (line[i] != '\0')
		i = i + 1;
	(*rest) = malloc((4096) * sizeof(char));
	i = save;
	if (line[i] == '\n')
		i =i + 1;
	(*rest) = str_cpy(*rest, line, &index, i);
	(*rest)[i] = '\0';
	line[save] = '\0';
	return (line);
}

char *get_next_line(int fd)
{
	int i = READ_SIZE;
	char *line = NULL;
	static int size_read = READ_SIZE;
	static char *rest = NULL;
	int check = 0;
	char *buff = malloc((READ_SIZE) * sizeof(char));

	if (size_read == 0 || (size_read != i && fd != 0) || \
	READ_SIZE < 0 || buff == NULL)
		return (NULL);
	while (size_read != 0 && i == READ_SIZE) {
		i = 0;
		if ((size_read = read(fd, buff, READ_SIZE)) == -1)
			return (NULL);
		while (size_read != 0 && i != READ_SIZE && buff[i] != '\n')
			i = i + 1;
		if (size_read != 0) {
			if ((line = new_line(line, buff, rest, \
					size_read, check)) == NULL)
				return (NULL);
			check = 1;
		}
	}
	if (READ_SIZE != 1)
		line = cut_str(&rest, line, size_read);
	free (buff);
	return (line);
}
