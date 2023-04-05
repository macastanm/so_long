/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:43:48 by macastan          #+#    #+#             */
/*   Updated: 2023/03/22 14:44:03 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_count(char *line, int fd)
{
	int	i;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		i++;
	}
	free(line);
	return (i);
}

char	**map_coordinates(t_data *data, char *line, int fd)
{
	int		i;
	char	**mapa;

	i = 0;
	mapa = malloc(sizeof(char *) * (data->lines));
	if (!mapa)
	{
		ft_printf("Malloc error\n");
		return (0);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		mapa[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
	free(line);
	return (mapa);
}

int	columns_count(char *line_zero)
{
	int	i;

	i = 0;
	while (line_zero[i])
		i++;
	return (i);
}

int	get_map(t_data *data, char *file)
{
	char	*line;

	line = 0;
	data->x = 0;
	data->y = 0;
	data->lines = 0;
	data->fd = open(file, O_RDONLY);
	if (data->fd < 0)
		return (ft_printf("Invalid file descriptor.\n"));
	data->lines = line_count(line, data->fd);
	close(data->fd);
	data->fd = open(file, O_RDONLY);
	data->map = map_coordinates(data, line, data->fd);
	data->columns = columns_count(data->map[0]);
	player_position(data);
	close(data->fd);
	data->fd = open(file, O_RDONLY);
	if (map_validations(data) != 1)
	{
		ft_free_map(data);
		return (0);
	}
	close(data->fd);
	return (1);
}
