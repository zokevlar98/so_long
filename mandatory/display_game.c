/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:02:09 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/21 18:44:00 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    init_imgs(t_data *data)
{
	int     width;
	int     height;
	
	data->img.player = mlx_xpm_file_to_image(data->mlx_p, "./images/player.xpm", &width, &height);
	if (!(data->img.player))
		error(data, "ERROR: mlx_xpm_file_to_image failed\n");
	data->img.coin = mlx_xpm_file_to_image(data->mlx_p, "./images/coin.xpm", &width, &height);
	if (!(data->img.coin))
		error(data, "ERROR: mlx_xpm_file_to_image failed\n");
	data->img.door = mlx_xpm_file_to_image(data->mlx_p, "./images/door.xpm", &width, &height);
	if (!(data->img.door))
		error(data, "ERROR: mlx_xpm_file_to_image failed\n");
	data->img.road = mlx_xpm_file_to_image(data->mlx_p, "./images/road.xpm", &width, &height);
	if (!(data->img.road))
		error(data, "ERROR: mlx_xpm_file_to_image failed\n");
	data->img.wall = mlx_xpm_file_to_image(data->mlx_p, "./images/wall.xpm", &width, &height);
	if (!(data->img.wall))
		error(data, "ERROR: mlx_xpm_file_to_image failed\n");
}

void    put_imgs_to_window(t_data *data, int x, int y)
{
	if (data->map[x][y] == 'P')
		mlx_put_image_to_window(data->mlx_p, data->win_p, data->img.player, y * 64, x * 64);
	if (data->map[x][y] == 'C')
		mlx_put_image_to_window(data->mlx_p, data->win_p, data->img.coin, y * 64, x * 64);
	if (data->map[x][y] == 'E')
		mlx_put_image_to_window(data->mlx_p, data->win_p, data->img.door, y * 64, x * 64);
	if (data->map[x][y] == '0')
		mlx_put_image_to_window(data->mlx_p, data->win_p, data->img.road, y * 64, x * 64);
	if (data->map[x][y] == '1')
		mlx_put_image_to_window(data->mlx_p, data->win_p, data->img.wall, y * 64, x * 64);
}

void	display_game(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->map[i])
	{
		j = -1;
		while (data->map[i][++j])
			put_imgs_to_window(data, i, j);
		i++;
	}
}