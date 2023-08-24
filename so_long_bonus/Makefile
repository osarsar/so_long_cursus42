# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 21:52:01 by osarsar           #+#    #+#              #
#    Updated: 2023/08/24 13:46:04 by osarsar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
GET_NEXT_LINE = get_next_line
LIBFT = libft
SRC_FILE =	get_next_line.c		\
			get_next_line_utils.c	\
			so_long_bonus.c			\
			analyse_map_bonus.c	\
			analyse_map_utils_bonus.c	\
			creat_map_bonus.c	\
			creat_map_utils_bonus.c	\
			move_player_bonus.c	\
			move_player_utils_bonus.c	\
			error_bonus.c

all: $(NAME)

%.o: %.c so_long_bonus.h
	@echo "Compiling: $< "
	@cc -Wall -Wextra -Werror -c $< -o $@

$(NAME):$(SRC_FILE:.c=.o)
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a .
	@ar -r $(NAME) $(SRC_FILE:.c=.o)
	@cc so_long_bonus.c -lmlx -framework OpenGL -framework AppKit libft.a -o so_long_bonus
	@echo "so_long compiled!"


clean:
	@rm -rf $(SRC_FILE:.c=.o)
	@make clean -C $(LIBFT) 
	@echo "all object files erased!"


fclean:	clean
	@rm -rf $(NAME)
	@rm -rf so_long_bonus
	@make fclean -C $(LIBFT) 
	@echo "libft.a erased!"

re:	fclean all
	@echo "Cleaned and rebuilt everything for so_long!"

