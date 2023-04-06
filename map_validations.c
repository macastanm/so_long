/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:27:13 by macastan          #+#    #+#             */
/*   Updated: 2023/03/23 11:27:40 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->lines)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->player++;
				data->player_x = j;
				data->player_y = i;
			}
			if (data->map[i][j] == 'E')
				data->exit++;
			if (data->map[i][j] == 'C')
				data->total_collect++;
			j++;
		}
		i++;
	}
	return ;
}

char	**map_duplicate(t_data *data)
{
	int		i;
	char	**mapa_dup;
	char	*line;

	i = 0;
	mapa_dup = malloc(sizeof(char *) * (data->lines));
	if (!mapa_dup)
	{
		ft_printf("Malloc error\n");
		return (0);
	}
	while (1)
	{
		line = get_next_line(data->fd);
		if (!line)
			break ;
		mapa_dup[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
	free(line);
	return (mapa_dup);
}

int	map_validations2(t_data *data)
{
	char	**map_dup;

	if (map_closed(data) != 1)
	{
		ft_printf("The maps must be closed by walls '1'!\n");
		return (0);
	}
	map_dup = map_duplicate(data);
	exit_position(data);
	if (map_path(data, map_dup, data->player_x, data->player_y) != 1)
	{
		ft_printf("ERROR\nThere is no valid path on this map!\n");
		ft_free_map2(map_dup, data->lines);
		return (0);
	}
	ft_free_map2(map_dup, data->lines);
	return (1);
}

int	map_validations(t_data *data)
{
	if (data->lines < 3 || data->columns < 3)
		return (ft_printf("ERROR\nMap too short!\n"));
	if (data->exit != 1 || data->player != 1 || data->total_collect < 1)
	{
		ft_printf("ERROR\nInvalid number of itens!\n");
		return (0);
	}
	if (check_rectangle(data) != 1)
	{
		ft_printf("The map must be rectangular!\n");
		return (0);
	}
	if (check_wrong_char(data) != 1)
		return (ft_printf("Wrong characters were found!\n"));
	if (map_validations2(data) != 1)
		return (0);
	return (1);
}
