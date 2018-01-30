##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## rush2
##

SRC	=	src/main.c	\
		src/str_to_int.c	\
		src/creat_map.c	\
		src/my_strlen.c	\
		src/check_nb_line.c	\
		src/print.c	\
		src/check_win.c	\
		src/check_match.c	\
		src/my_put_nbr.c	\
		src/get_next_line.c	\
		src/my_putstr.c

SRC_TEST	=	src/str_to_int.c	\
			src/my_strlen.c	\
			src/print.c	\
			src/my_putstr.c	\
			src/my_put_nbr.c	\
			tests/tests.c

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
	$(RM) $(NAME) test

re:	fclean all

tests_run:
	$(CC) -o test $(SRC_TEST) $(CFLAGS_TEST)
	./test

.PHONY:	all clean fclean re
