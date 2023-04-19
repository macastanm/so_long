/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:53:24 by macastan          #+#    #+#             */
/*   Updated: 2023/03/30 10:53:34 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_texture(t_data *data, int i, int j)
{
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->wall_img, (j * WINSIZE), (i * WINSIZE));
	if (data->map[i][j] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->empty_img, (j * WINSIZE), (i * WINSIZE));
	if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->collect_img, (j * WINSIZE), (i * WINSIZE));
	if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->exit_img, (j * WINSIZE), (i * WINSIZE));
	if (data->map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player_img, (j * WINSIZE), (i * WINSIZE));
}

void	put_img(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->lines)
	{
		j = 0;
		while (j < data->columns)
		{
			put_texture(data, i, j);
			data->x += WINSIZE;
			j++;
		}
		data->x = 0;
		data->y += WINSIZE;
		i++;
	}
}

void	xpm_to_img(t_data *data)
{
	data->wall_img = mlx_xpm_file_to_image(data->mlx_ptr,
			WALL, &data->x, &data->y);
	data->empty_img = mlx_xpm_file_to_image(data->mlx_ptr,
			EMPTY, &data->x, &data->y);
	data->collect_img = mlx_xpm_file_to_image(data->mlx_ptr,
			COLLECT, &data->x, &data->y);
	data->exit_img = mlx_xpm_file_to_image(data->mlx_ptr,
			EXIT, &data->x, &data->y);
	data->exit_open_img = mlx_xpm_file_to_image(data->mlx_ptr,
			EXIT_OPEN, &data->x, &data->y);
	data->player_img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYER, &data->x, &data->y);
}

void	game_start(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->columns * WINSIZE,
			data->lines * WINSIZE, "so_long");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		ft_free_map(data);
		return ;
	}
	xpm_to_img(data);
	put_img(data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &ft_moves, data);
	mlx_hook(data->win_ptr, DestroyNotify, ButtonPressMask, &game_end, data);
	mlx_loop(data->mlx_ptr);
}
