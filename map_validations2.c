/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:36:51 by macastan          #+#    #+#             */
/*   Updated: 2023/03/23 12:37:10 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_closed(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->columns)
	{
		if (data->map[0][i] != '1' || data->map[data->lines - 1][i] != '1')
			return (ft_printf("ERROR\n"));
		i++;
	}
	i = 1;
	while (i < data->lines)
	{
		if (data->map[i][0] != '1' || data->map[i][data->columns - 1] != '1')
			return (ft_printf("ERROR\n"));
		i++;
	}
	return (1);
}

int	check_rectangle(t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (i < data->columns)
	{
		i++;
	}
	while (x < data->lines)
	{
		while (data->map[x][y])
			y++;
		if (y == i)
		{
			x++;
			y = 0;
		}
		else
			return (ft_printf("ERROR\n"));
	}
	return (1);
}

int	check_wrong_char(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->lines)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (!ft_char_check("01PEC", data->map[i][j]))
			{
				return (ft_printf("ERROR\n"));
			}
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_char_check(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == c)
		return ((char *)str + i);
	return (0);
}
