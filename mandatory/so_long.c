/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:10:54 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/17 21:30:13 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_data *data)
{
	data->mlx_p = NULL;
	data->win_p = NULL;
	data->fd = 0;
	data->hauteur = 0;
	data->largeur = 0;
	data->x = 0;
	data->y = 0;
	data->P = 0;
	data->C = 0;
	data->E = 0;
	data->line = NULL;
	data->map = NULL;
}

// void	ff(void)
// {
// 	system("leaks so_long");
// }

int	main(int argc, char *argv[])
{
	t_data	*data;

	// atexit(ff);
	data = malloc(sizeof(t_data));
	if (!data)
		error(data, "ERROR: Allcoation failed\n");
	if (argc == 2)
	{
		init_data(data);
		check_map_valid(data, argv);
		// For test leaks :
		// clear_data(data);
		// free(data);
	}
	else
		usage();
	return (0);
}

		// int	i = 0;
		// while (data->map_copy[i] != NULL)
		// {
		// 	printf("%s\n", data->map_copy[i]);
		// 	i++;
		// }