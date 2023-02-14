##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Gautier BONHUR
##

NAME			=	my_defender

SRC_MAIN		= main.c

SRC				=	$(addprefix src/, \
					mydefender.c \
					check_game_status.c \
					init_struct.c \
					scenes/1/one.c \
					scenes/1/analyse_event.c \
					scenes/1/chest_helper.c \
					scenes/1/settings.c \
					scenes/2/analyse_event.c \
					scenes/2/pause.c \
					scenes/2/towers/init_towers_main.c \
					scenes/2/towers/init_towers.c \
					scenes/2/settings.c \
					csfml/draw.c \
					scenes/2/move_object.c \
					scenes/2/check_damage/damage.c \
					scenes/2/towers/move_rect_towers.c \
					scenes/2/towers/destroy_towers.c \
					scenes/2/towers/check_click_towers.c \
					scenes/2/towers/init_sprites_info_towers.c \
					scenes/2/move_enemies.c \
					scenes/2/basement_positions.c \
					scenes/2/score.c \
					scenes/2/basement.c \
					scenes/2/towers/draw.c \
					scenes/2/towers/change_circle_pos.c \
					scenes/2/towers/change_rotation.c \
					scenes/2/arrow.c \
					scenes/2/two.c \
					scenes/2/money.c \
					scenes/2/check_money.c \
					scenes/2/enemies_life.c \
					scenes/2/init_sprites_two.c \
					init_sprites/init_sprites.c \
					init_sprites/init_fps_sprites.c \
					init_sprites/init_skip_button.c \
					csfml/destroy/destroy.c \
					csfml/destroy/destroy_sound.c \
					csfml/analyse_events.c \
					csfml/create_sprite.c  \
					csfml/move_rect.c \
					csfml/set_pos.c \
					csfml/scale.c \
					csfml/create_sound.c \
					errors/check_env.c \
					lib/my_putchar.c \
					lib/lenght_int.c \
					lib/my_putstr.c \
					lib/my_strcmp.c \
					lib/my_strlen.c \
					lib/my_strcat.c \
					lib/str_to_array/str_to_array.c \
					lib/str_to_array/strmanipulation.c \
					lib/str_to_array/count_size_argv.c \
					lib/count_separators.c)

SRC_TESTS = tests/tests_main.c

OBJ				=			$(SRC:.c=.o)

OBJ_MAIN		=			$(SRC_MAIN:.c=.o)

CFLAGS 			= 			-I./includes

GRAPHICS 		= -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

CRITERION		= 			--coverage -lcriterion

all: 			$(NAME)

$(NAME):		$(OBJ) $(OBJ_MAIN)
	gcc -o $(NAME) $(OBJ) $(OBJ_MAIN) $(LDFLAGS) $(GRAPHICS)

tests_run: $(OBJ)
	make re
	gcc -o unit_tests $(SRC) $(SRC_TESTS) $(CFLAGS) $(CRITERION)
	./unit_tests
	rm unit_tests

clean:
	rm -f $(OBJ)
	rm -f *.o
	rm -f *.gcda
	rm -f *.gcno
	rm -f unit_tests

fclean:			clean
	rm -f $(NAME)

re:	$(NAME)

.PHONY: fclean tests_run clean re make
