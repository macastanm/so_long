/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:39:13 by macastan          #+#    #+#             */
/*   Updated: 2023/04/04 12:39:27 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->empty_img,
		data->player_x * WINSIZE, data->player_y * WINSIZE);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_img,
		data->player_x * WINSIZE, (data->player_y - 1) * WINSIZE);
	data->player_y -= 1;
	data->moves++;
	ft_printf("Player moves: %i\n", data->moves);
}

void	move_s(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->empty_img,
		data->player_x * WINSIZE, data->player_y * WINSIZE);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_img,
		data->player_x * WINSIZE, (data->player_y + 1) * WINSIZE);
	data->player_y += 1;
	data->moves++;
	ft_printf("Player moves: %i\n", data->moves);
}

void	move_a(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->empty_img,
		data->player_x * WINSIZE, data->player_y * WINSIZE);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_img,
		(data->player_x - 1) * WINSIZE, data->player_y * WINSIZE);
	data->player_x -= 1;
	data->moves++;
	ft_printf("Player moves: %i\n", data->moves);
}

void	move_d(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->empty_img,
		data->player_x * WINSIZE, data->player_y * WINSIZE);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_img,
		(data->player_x + 1) * WINSIZE, data->player_y * WINSIZE);
	data->player_x += 1;
	data->moves++;
	ft_printf("Player moves: %i\n", data->moves);
}
