##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## rush2
##

SRC	=	src/main.c	\
		src/str_to_int.c	\
		src/remove_matches.c	\
		src/creat_map.c	\
		src/my_strlen.c	\
		src/print.c	\
		src/management_ia.c	\
		src/check_win.c	\
		src/check_match.c	\
		src/my_put_nbr.c	\
		src/get_next_line.c	\
		src/my_putstr.c	\
		src/check_player.c

SRC_TEST	=	src/str_to_int.c	\
			src/my_strlen.c	\
			src/print.c	\
			src/my_putstr.c	\
			src/my_put_nbr.c	\
			tests/tests.c

SRC_BONUS	=	bonus/print_help.c	\
			bonus/management_two_player.c	\
			bonus/choose_game.c	\
			bonus/main.c	\
			src/creat_map.c	\
			src/remove_matches.c	\
			src/my_strlen.c

CFLAGS	+=	 -I./include -Wall -Wextra -g3

CFLAGS_TEST	+=	--coverage -lcriterion -lgcov -I./include

NAME	=	matchstick

CC	=	gcc

RM	=	rm -f

RM_1	=	rm -f *.gc*

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
clean:
	$(RM) $(OBJ) $(RM_1)

fclean: clean
	$(RM) $(NAME) test bonus_1

re:	fclean all

bonus_1: fclean
	$(CC) -o bonus_1 $(SRC_BONUS) -I./include -Wall -Wextra -lncurses
	./bonus_1

tests_run:
	$(CC) -o test $(SRC_TEST) $(CFLAGS_TEST)
	./test

.PHONY:	all clean fclean re
