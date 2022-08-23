##
## EPITECH PROJECT, 2020
## My World
## File description:
## Makefile
##

SRC_FILES	=	main.c	\
		error_handler.c	\
		loader.c	\
		unloader.c	\
		window_main.c	\
		events/global_events.c	\
		windows/window_menu.c	\
		objects/global_objects.c	\
		animations/global_animations.c \
		managers/buttons_manager.c	\
		windows/editor_window.c	\
		managers/files_manager.c	\
		tools/map_tools.c	\
		events/editor_events.c	\
		objects/editor_objects.c	\
		tools/map_tools2.c	\
		tools/zone_tools.c	\
		objects/main_menu_objects.c	\
		tools/texts_tools.c	\
		managers/buttons_manager2.c	\
		managers/scenes_switch_manager.c	\
		tools/randomizer.c	\
		tools/gen_map.c	\
		managers/scenes_manager.c	\
		managers/scenes_manager_2.c	\
		events/main_menu_events.c	\
		map_renderer.c	\
		managers/edit_manager.c	\
		managers/edit_manager2.c	\
		map_renderer2.c

SRC_DIR	= ./sources/

SRC		=	$(foreach file, $(SRC_FILES), $(addprefix $(SRC_DIR), $(file)))

OBJ_FILES	=	$(notdir $(SRC_FILES:.c=.o))

OBJ_DIR	=	./obj/

OBJ		=	$(foreach file, $(OBJ_FILES), $(addprefix $(OBJ_DIR), $(file)))

NAME	=	my_world

CFLAGS	=	-I./includes/ -L./sources/lib/my/ -lmy -g3 -Wall -Wextra -l csfml-graphics -l csfml-system -l csfml-window -l csfml-audio -lm

all:	$(NAME)
	@echo "Build succesfull!"

$(NAME):	bins
	@make -C ./sources/lib/my
	@gcc -o $(NAME) $(OBJ) $(CFLAGS)

bins:
	@gcc -c $(SRC) $(CFLAGS)
	@mv $(OBJ_FILES) ./obj

clean:
	@make -C ./sources/lib/my clean
	@rm -f $(OBJ)

fclean:	clean
	@make -C ./sources/lib/my fclean
	@rm -f $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re bins