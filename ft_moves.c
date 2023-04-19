/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:11:52 by macastan          #+#    #+#             */
/*   Updated: 2023/04/04 11:12:02 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_move(t_data *data, char tecla)
{
	if (tecla == 'W')
	{
		if (data->map[data->player_y - 1][data->player_x] == '1')
			return (0);
		if (data->map[data->player_y - 1][data->player_x] == 'C')
			return (1);
		if (data->map[data->player_y - 1][data->player_x] == 'E' &&
			data->caught_collect == data->total_collect)
			return (1);
		if (data->map[data->player_y - 1][data->player_x] == '0')
			return (1);
	}
	if (tecla == 'S')
	{
		if (data->map[data->player_y + 1][data->player_x] == '1')
			return (0);
		if (data->map[data->player_y + 1][data->player_x] == 'C')
			return (1);
		if (data->map[data->player_y + 1][data->player_x] == 'E' &&
			data->caught_collect == data->total_collect)
			return (1);
		if (data->map[data->player_y + 1][data->player_x] == '0')
			return (1);
	}
	return (0);
}

int	check_move2(t_data *data, char tecla)
{
	if (tecla == 'A')
	{
		if (data->map[data->player_y][data->player_x - 1] == '1')
			return (0);
		if (data->map[data->player_y][data->player_x - 1] == 'C')
			return (1);
		if (data->map[data->player_y][data->player_x - 1] == 'E' &&
			data->caught_collect == data->total_collect)
			return (1);
		if (data->map[data->player_y][data->player_x - 1] == '0')
			return (1);
	}
	if (tecla == 'D')
	{
		if (data->map[data->player_y][data->player_x + 1] == '1')
			return (0);
		if (data->map[data->player_y][data->player_x + 1] == 'C')
			return (1);
		if (data->map[data->player_y][data->player_x + 1] == 'E' &&
			data->caught_collect == data->total_collect)
			return (1);
		if (data->map[data->player_y][data->player_x + 1] == '0')
			return (1);
	}
	return (0);
}

int	move(char tecla, t_data *data)
{
	if (tecla == 'W' && check_move(data, 'W') == 1)
		move_w(data);
	if (tecla == 'S' && check_move(data, 'S') == 1)
		move_s(data);
	if (tecla == 'A' && check_move2(data, 'A') == 1)
		move_a(data);
	if (tecla == 'D' && check_move2(data, 'D') == 1)
		move_d(data);
	if (data->map[data->player_y][data->player_x] == 'C')
	{
		data->caught_collect++;
		data->map[data->player_y][data->player_x] = '0';
		if (data->caught_collect == data->total_collect)
			change_exit(data);
	}
	if (data->map[data->player_y][data->player_x] == 'E' &&
				data->caught_collect == data->total_collect)
	{
		ft_printf("🏆 Congratulations, you won the game!\n");
		game_end(data);
	}
	return (0);
}

int	ft_moves(int keysym, t_data *data)
{
	if (keysym == 65307)
		game_end(data);
	if (keysym == 119)
		move('W', data);
	if (keysym == 115)
		move('S', data);
	if (keysym == 97)
		move('A', data);
	if (keysym == 100)
		move('D', data);
	return (0);
}
