/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:48:36 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/30 06:48:23 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

void	destory_image(t_data *data)
{
	if (data->img.player)
		mlx_destroy_image(data->mlx_p, data->img.player);
	if (data->img.coin)
		mlx_destroy_image(data->mlx_p, data->img.coin);
	if (data->img.door)
		mlx_destroy_image(data->mlx_p, data->img.door);
	if (data->img.road)
		mlx_destroy_image(data->mlx_p, data->img.road);
	if (data->img.wall)
		mlx_destroy_image(data->mlx_p, data->img.wall);
}

void	clear_data(t_data *data)
{
	if (data != NULL)
	{
		if (data->line)
			free(data->line);
		if (data->map)
			free_map(data->map);
		if (data->map_copy)
			free_map(data->map_copy);
		if (data->mlx_p)
		{
			if (data->win_p)
			{
				destory_image(data);
				mlx_clear_window(data->mlx_p, data->win_p);
				mlx_destroy_window(data->mlx_p, data->win_p);
			}
		}
	}
}

int	key_hook_mouse(t_data *data)
{
	clear_data(data);
	ft_putstr_fd("YOU LOSE!\n", STDOUT_FILENO);
	exit(EXIT_SUCCESS);
}
