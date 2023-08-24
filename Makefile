# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 21:52:01 by osarsar           #+#    #+#              #
#    Updated: 2023/08/24 13:44:45 by osarsar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
GET_NEXT_LINE = get_next_line
LIBFT = libft
SRC_FILE =	get_next_line.c		\
			get_next_line_utils.c	\
			so_long.c			\
			analyse_map.c	\
			analyse_map_utils.c	\
			creat_map.c	\
			creat_map_utils.c	\
			move_player.c	\
			move_player_utils.c	\
			error.c

all: $(NAME)

%.o: %.c
	@echo "Compiling: $< "
	@cc -Wall -Wextra -Werror -c $< -o $@

$(NAME):$(SRC_FILE:.c=.o)
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a .
	@ar -r $(NAME) $(SRC_FILE:.c=.o)
	@cc so_long.c -lmlx -framework OpenGL -framework AppKit libft.a -o so_long
	@echo "so_long compiled!"


clean:
	@rm -rf $(SRC_FILE:.c=.o)
	@make clean -C $(LIBFT) 
	@make clean -C so_long_bonus 
	@echo "all object files erased!"


fclean:	clean
	@rm -rf $(NAME)
	@rm so_long
	@rm so_long_bonus/so_long_bonus
	@make fclean -C $(LIBFT)
	@make fclean -C so_long_bonus
	@echo "libft.a erased!"


bonus:
	@make all -C so_long_bonus

re:	fclean all
	@echo "Cleaned and rebuilt everything for so_long!"

