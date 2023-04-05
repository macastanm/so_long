/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:24:09 by macastan          #+#    #+#             */
/*   Updated: 2023/03/21 12:31:37 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	struct_start(t_data *data)
{
	data->mlx_ptr = 0;
	data->win_ptr = 0;
	data->wall_img = 0;
	data->empty_img = 0;
	data->collect_img = 0;
	data->exit_img = 0;
	data->player_img = 0;
	data->map = 0;
	data->x = 0;
	data->y = 0;
	data->player_x = 0;
	data->player_y = 0;
	data->exit_x = 0;
	data->exit_y = 0;
	data->lines = 0;
	data->columns = 0;
	data->total_collect = 0;
	data->caught_collect = 0;
	data->moves = 0;
	data->exit = 0;
	data->player = 0;
	data->fd = 0;
}

int	check_ber(char *namefile)
{
	int	i;

	i = ft_strlen(namefile) - 4;
	if (ft_strncmp(".ber", &namefile[i], 4) != 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_printf("ERROR\n.ber file is missing!\n"));
	if (check_ber(argv[1]) != 1)
	{
		ft_printf("ERROR\nWrong file! It must be .ber file.\n");
		return (0);
	}
	struct_start(&data);
	if (get_map(&data, argv[1]) != 1)
	{
		return (0);
	}
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (ft_printf("ERROR\nMLX ERROR\n"));
	game_start(&data);
	return (1);
}
