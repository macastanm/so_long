/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:10:11 by macastan          #+#    #+#             */
/*   Updated: 2023/03/27 11:10:22 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->lines)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
			{
				data->exit_x = j;
				data->exit_y = i;
			}
			j++;
		}
		i++;
	}
	return ;
}

int	map_path(t_data *data, char **map, int x, int y)
{
	static int	e;
	static int	c;

	if (x < 0 || y < 0 || x > data->columns || y > data->lines
		|| map[y][x] == '1' || map[y][x] == 'X')
		return (0);
	if (map[y][x] == 'E')
	{
		e++;
		map[y][x] = 'X';
		return (0);
	}
	if (map[y][x] == 'C')
		c++;
	map[y][x] = 'X';
	map_path(data, map, x, y + 1);
	map_path(data, map, x, y - 1);
	map_path(data, map, x + 1, y);
	map_path(data, map, x - 1, y);
	if (e == 1 && c == data->total_collect)
		return (1);
	else
		return (0);
}

/*void	print_map(char **map, t_data *data)
{
	int	i;
	int	j;
	i = 0;
	while (i < data->lines)
	{
		j = 0;
		while (j < data->columns)
		{
			ft_printf("%c", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}*/