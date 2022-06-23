##
## EPITECH PROJECT, 2021
## <DON'T FORGET TO PUT PROJECT NAME HERE!!!!>
## File description:
## Makefile
##

## Variable to be modified
rm = rm -rf

TARGET = my_defender

CFLAGS = -Wextra -Wall -Iinclude

LDFLAGS	=	-L./ -lmy -lcsfml-graphics -lcsfml-window	\
			-lcsfml-audio -lcsfml-system -lm

SRC	=	sources/my_defender.c	\
		sources/initialisation.c\
		sources/events.c		\
		sources/game_status.c	\
		sources/error_handling.c\
		sources/increase_button_level.c	\
		sources/increase_button_menu.c	\
		sources/destroy_window.c	\
		sources/level1.c	\
		sources/glow_base.c	\
		sources/build.c	\
		sources/level1_things.c	\
		sources/main.c	\
		sources/draw_tower.c	\
		sources/init_button.c	\
		sources/set_volumne.c	\
		sources/upgrade.c	\
		sources/sell.c	\
		sources/draw_tower2.c	\
		sources/draw_tower3.c	\
		sources/defenddraw.c	\
		sources/enemy_path.c	\
		sources/enemy_anim.c	\
		sources/init_level1.c	\
		sources/init_enemy.c	\

OBJ	=	$(SRC:.c=.o)

LIB_MAKE_PATH	=	lib/my/

LIB	= libmy.a

all:	$(LIB)	$(TARGET)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $^\
	&& printf "[\033[1;35mcompiled\033[0m] % 29s\n" $< |  tr ' ' '.'\
	|| printf "[\033[1;31merror\033[0m] % 29s\n" $< |  tr ' ' '.'

$(LIB):
	@$(MAKE) -C $(LIB_MAKE_PATH)

$(TARGET): $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)
	@echo -e "\e[1;36mFinished compiling $@\e[0m"

.PHONY:	all	fclean	clean	re

debug: CFLAGS += -g3
debug: clean all

clean:
	@$(rm) $(OBJ)
	@echo "Removed .o files"
	@$(MAKE) -C $(LIB_MAKE_PATH) clean

fclean: clean
	@$(rm) $(TARGET)
	@echo "Removed binary file"
	@$(MAKE) -C $(LIB_MAKE_PATH) fclean

re: fclean all
