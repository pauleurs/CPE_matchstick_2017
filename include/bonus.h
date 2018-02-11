/*
** EPITECH PROJECT, 2018
** bonus
** File description:
** paul-emile.leurs@epitech.eu
*/

#ifndef BONUS_H_
# define BONUS_H_
void recover_nb_line_2(int size, char **map, char **name, int max_matches);
void print_map_two_player(char **map, int size, int line, int player);
char **creat_map(int nb_line);
char **remove_matches(char **map, int line, int matches);
char **name_player(void);
int print_name_player(char **name, int player);
int check_win(char **map, int player, char **name);
int my_strlen(char *str);
int selected_mod_game(void);
int print_help(void);
int management_two_player(void);
void print_map(char **map, int size);
int nb_matches_line(int line, char **map);
void recover_nb_line_1(int size, char **map, char **name, int max_matches);
int main(void);
int size_map_ask(void);
int max_matches_ask(void);
void choose_line(char **map, int *line, char **name, int size);
char **creat_matches(char **map, int line);
int compteur(int touch, int min, int max, int nb);
int management_ai_player(void);
#endif
