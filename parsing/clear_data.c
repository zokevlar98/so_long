/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:48:36 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/17 18:07:18 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char	**map)
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

void	clear_data(t_data *data)
{
	if (data->line)
		free(data->line);
	if (data->map)
		free_map(data->map);
	if (data->map_copy)
		free_map(data->map_copy);
	//zid 3liha fermer window et free mlx_ptr ...
}