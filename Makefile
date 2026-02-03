##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile for setting_up
##

CC = epiclang

SRC		=	src/destroy/destroy.c \
			src/events/manage_events.c \
			src/game/load_music_game.c \
			src/game/main_loop.c \
			src/menu/load_music_menu.c \
			src/menu/menu.c \
			src/score/load_score.c \
			src/sounds/init_sounds.c \
			src/sprite/animations.c \
			src/sprite/load_sprite.c \
			src/sprite/move_sprite.c \
			src/window/put_game.c \
			src/window/window_game.c \
			src/main.c

OBJ		= 	$(SRC:.c=.o)

NAME	=	my_hunter

CFLAGS	= 	-Wall -Wextra -I./include

CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./lib/my
	cc -o $(NAME) $(OBJ) -L./lib/my -lmy $(CFLAGS) $(CSFML)

clean:
	$(MAKE) -C ./lib/my clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./lib/my fclean

re: fclean all
