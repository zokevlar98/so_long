/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:04:38 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/21 20:30:16 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_map(t_data *data)
{
	int	i;

	i = -1;
	data->map_copy = malloc(sizeof(char *) * (data->height + 1));
	if (data->map_copy == NULL)
		error(data, "ERROR: Allcoation failed\n");
	while (data->map[++i])
		data->map_copy[i] = ft_strdup(data->map[i]);
	data->map_copy[i] = NULL;
}

void	serche_player_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->x = i;
				data->y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	check_map_copy(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map_copy[i])
	{
		j = 0;
		while (data->map_copy[i][j])
		{
			if (data->map_copy[i][j] == 'C' || data->map_copy[i][j] == 'E')
				error(data, "ERROR: Map is not valid \n");
			j++;
		}
		i++;
	}
}

void	check_map_valid(t_data *data, char **argv)
{
	check_file(data, argv[1]);
	put_map(data, argv);
	check_size(data);
	check_border_up_down(data);
	check_border_left_right(data);
	check_characters(data);
	count_map_character(data);
	serche_player_position(data);
	copy_map(data);
	flood_fill(data);
	check_map_copy(data);
	// serche_player_position(data);
}
