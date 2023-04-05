# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macastan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 12:31:46 by macastan          #+#    #+#              #
#    Updated: 2023/03/21 12:33:35 by macastan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT = ./libft-pf-gnl/libft.a
MLX = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lm 

SRC = so_long.c \
	get_map.c \
	map_validations.c \
	map_validations2.c \
	map_validations3.c \
	game_start.c \
	frees.c \
	game_end.c \
	ft_moves.c \
	ft_moves2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft-pf-gnl

$(NAME): $(OBJ) $(LIBFT)
	$(MAKE) -C ./minilibx-linux
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o so_long
		

clean:
	$(MAKE) clean -C ./libft-pf-gnl
	@$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft-pf-gnl
	@$(RM) $(NAME)

re: fclean all
