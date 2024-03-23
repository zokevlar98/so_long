/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:42:24 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/23 00:06:21 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dfs(t_data *data, int i, int j, int *coin_count)
{
	if (i < 0 || j < 0 || i >= data->height || j >= data->width
		|| data->map_copy[i][j] == '1' || data->map_copy[i][j] == 'V')
		return ;
	if (*coin_count > 0 && data->map_copy[i][j] != 'E')
	{
		if (data->map_copy[i][j] == 'C')
			(*coin_count)--;
		data->map_copy[i][j] = 'V';
	}
	else if (data->map_copy[i][j] == 'E')
	{
		data->map_copy[i][j] = 'V';
		return ;
	}
	else if (*coin_count == 0)
		data->map_copy[i][j] = 'V';
	dfs(data, i, j - 1, coin_count);
	dfs(data, i, j + 1, coin_count);
	dfs(data, i - 1, j, coin_count);
	dfs(data, i + 1, j, coin_count);
}

void	flood_fill(t_data *data)
{
	int	coin_count;

	coin_count = data->c;
	dfs(data, data->x, data->y, &coin_count);
}
