/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:08:46 by macastan          #+#    #+#             */
/*   Updated: 2023/03/30 15:08:57 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map2(char **map, int linha)
{
	int	i;

	i = 0;
	while (i < linha)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->lines)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}
