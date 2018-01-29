/*
** EPITECH PROJECT, 2017
** d09
** File description:
** my.h
*/

#ifndef MY_H_
# define MY_H_
int str_to_int(char *str);
void print_map(char **map);
int check_win(char **map, int player);
int check_nb_line(char *str_line, int nb_line);
void print_resume(int line,int matches, int player);
char **creat_map(int nb_line);
int check_match(char *str_matches, int max_matches, char **map, int line);
int my_put_nbr(int nb);
char *get_next_line(int fd);
void my_putstr(char *const str);
int my_strlen(char *str);
#endif
