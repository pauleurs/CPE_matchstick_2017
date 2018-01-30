/*
** EPITECH PROJECT, 2017
** d09
** File description:
** my.h
*/

#ifndef MY_H_
# define MY_H_
# define PLAYER (0)
# define IA (1)
int str_to_int(char *str);
int check_nb_line(int nb_line);
void print_map(char **map);
char **management_ia(char **map, int max_matches);
char **remove_matches(char **map, int line, int matches);
int check_win(char **map, int player);
char **check_player(char **map, int *nb);
void print_resume(int line,int matches, int player);
int check_match(char **map, int line, int matches, int *nb);
char **creat_map(int nb_line);
int my_put_nbr(int nb);
char *get_next_line(int fd);
void my_putstr(char *const str);
int my_strlen(char *str);
#endif
