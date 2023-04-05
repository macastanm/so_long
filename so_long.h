/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:24:53 by macastan          #+#    #+#             */
/*   Updated: 2023/03/21 10:32:58 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include "./minilibx-linux/mlx.h"
# include "./libft-pf-gnl/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define WALL "./textures/wall.xpm"
# define EMPTY "./textures/empty.xpm"
# define COLLECT "./textures/collect.xpm"
# define EXIT "./textures/exit.xpm"
# define PLAYER "./textures/player.xpm"
# define WINSIZE 64

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall_img;
	void	*empty_img;
	void	*collect_img;
	void	*exit_img;
	void	*player_img;
	char	**map;
	int		x;
	int		y;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		lines;
	int		columns;
	int		total_collect;
	int		caught_collect;
	int		moves;
	int		exit;
	int		player;
	int		fd;
}				t_data;

// so_long

void	struct_start(t_data *data);
int		check_ber(char *namefile);

// get_map

char	**map_coordinates(t_data *data, char *line, int fd);
int		get_map(t_data *data, char *file);
int		columns_count(char *line_zero);
int		line_count(char *line, int fd);

// map_validations

void	player_position(t_data *data);
char	**map_duplicate(t_data *data);
int		map_validations2(t_data *data);
int		map_validations(t_data *data);

// map_validations2

char	*ft_char_check(const char *str, int c);
int		check_wrong_char(t_data *data);
int		check_rectangle(t_data *data);
int		map_closed(t_data *data);

// map_validations3

void	exit_position(t_data *data);
int		map_path(t_data *data, char **map_dup, int x, int y);
//void	print_map(char **map);

// game_start

void	put_texture(t_data *data, int i, int j);
void	put_img(t_data *data);
void	xpm_to_img(t_data *data);
void	game_start(t_data *data);

// frees

void	ft_free_map(t_data *data);
void	ft_free_map2(char **map, int linha);

// ft_moves

int		ft_moves(int keysym, t_data *data);
int		move(char tecla, t_data *data);
int		check_move2(t_data *data, char tecla);
int		check_move(t_data *data, char tecla);

//ft_moves2

void	move_d(t_data *data);
void	move_a(t_data *data);
void	move_s(t_data *data);
void	move_w(t_data *data);

//game_end

int		game_end(t_data *data);

#endif
