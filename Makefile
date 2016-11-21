# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mperronc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 12:07:00 by mperronc          #+#    #+#              #
#    Updated: 2016/03/23 15:52:51 by mperronc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Thanks to fdaudre- for his tutorial #

SRC_PATH = ./src/

SRC_NAME =  allocate_board.c \
			choose_move.c \
			filler.c \
			find_moves.c \
			free_data.c \
			free_game.c \
			get_board.c \
			get_player_symbols.c \
			get_data_line.c \
			get_header_line.c \
			init_game.c \
			parse_line.c \
			parse_piece.c \
			play_piece.c \
			print_board.c \
			t_moves_funcs.c \
			try_move.c \
			update_board.c

OBJ_PATH = ./obj/

INC_PATH = ./includes/

NAME = resources/players/mperronc.filler

CC = clang
CFLAGS = -Wall -Wextra -Werror -g

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

filler: all
	cd resources && ./filler_vm -f maps/map01 -p1 players/mperronc.filler -p2 players/hcao.filler

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) -L ./libft -lft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

.PHONY: clean fclean re

clean:
	make -C ./libft clean
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: clean
	make -C ./libft fclean
	rm -fv $(NAME)

re:	fclean all
	make -C ./libft re
