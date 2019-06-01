##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/player.c	\
		src/my_menu.c	\
		src/button.c	\
		src/open_tab.c	\
		fight/fct_event.c		\
		fight/character.c		\
		fight/init_struct.c		\
		fight/enemy_turn.c		\
		fight/player_turn.c		\
		fight/create_text.c		\
		fight/init_player_struct.c	\
		fight/init_enemy_struct.c	\
		fight/my_put_nbr_str.c	\
		fight/my_revstr.c	\
		fight/fight.c	\
		src/rpg1.c	\
		src/rpg2.c	\
		src/rpg3.c	\
		src/rpg4.c	\
		src/rpg5.c	\
		src/rpg6.c	\
		src/rpg7.c	\
		src/rpg8.c	\
		src/mus.c	\
		src/victory.c

CFLAGS  =  	-L./lib/my/ -lmy -Iinclude				\
		-lcsfml-graphics -lcsfml-window -lcsfml-system	\
		-lcsfml-audio -g3

NAME	=	my_rpg

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my/
	gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
	make clean -C ./lib/my/
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./lib/my/
	rm -f $(NAME)

re:	fclean all
