/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:10:54 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/28 23:15:18 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_data *data)
{
	data->mlx_p = NULL;
	data->win_p = NULL;
	data->fd = 0;
	data->width = 0;
	data->height = 0;
	data->x = 0;
	data->y = 0;
	data->p = 0;
	data->c = 0;
	data->e = 0;
	data->move = 0;
	data->line = NULL;
	data->map = NULL;
	data->map_copy = NULL;
}

// void	ff(void)
// {
// 	system("leaks so_long");
// }

int	main(int argc, char *argv[])
{
	t_data	*data;

	// atexit(ff);
	if (argc == 2)
	{
		data = (t_data *)malloc(sizeof(t_data));
		if (!data)
		{
			error(data, "ERROR: Allcoation failed\n");
			// ft_putstr_fd("\033[31m", 2);
			// ft_putstr_fd("ERROR: Allcoation failed\n", 2);
			// exit (EXIT_FAILURE);
		}
		init_data(data);
		check_map_valid(data, argv);
		game_play(data);
		if (data)
		{
			clear_data(data);
			free(data);
		}
	}
	else
		usage();
	return (0);
}
