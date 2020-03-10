##
## EPITECH PROJECT, 2019
## my_hunter
## File description:
## Makefile
##

C_FLAGS = -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -W -Wall -Wextra -g3 -I./include

SRC = my_hunter.c \
	animation.c \
	creation.c \
	tutorial.c \
	exit.c \
	main_menu.c \
	mouvement.c \
	destroy.c \
	menu_pause.c \
	score.c \

OBJ = $(SRC:.c=.o)

NAME = my_hunter

all	: $(NAME)

$(NAME)	:	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(C_FLAGS)

clean	:
	rm -f *.o

fclean	:	clean
	rm -f $(NAME)

re	:	fclean all