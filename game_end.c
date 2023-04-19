/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:09:13 by macastan          #+#    #+#             */
/*   Updated: 2023/04/04 11:09:38 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_end(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->wall_img);
	mlx_destroy_image(data->mlx_ptr, data->empty_img);
	mlx_destroy_image(data->mlx_ptr, data->collect_img);
	mlx_destroy_image(data->mlx_ptr, data->exit_img);
	mlx_destroy_image(data->mlx_ptr, data->exit_open_img);
	mlx_destroy_image(data->mlx_ptr, data->player_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	ft_free_map(data);
	free(data->mlx_ptr);
	exit (0);
}

void	change_exit(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit_open_img,
		(data->exit_x * WINSIZE), (data->exit_y * WINSIZE));
	return ;
}
