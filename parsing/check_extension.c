/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:34:36 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/17 16:25:18 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file(t_data *data, char *argv)
{
	data->fd = open(argv, O_RDWR, 0666);
	if (data->fd == -1)
	{
		close(data->fd);
		error(data, "ERROR: NO such Directory or file\n");
	}
	check_extension(argv);
}

void	check_extension(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
		i++;
	i = i - 4;
	if (ft_strncmp(&argv[i], ".ber", ft_strlen(".ber")) != 0)
		wrong_extension();
}

void	check_map_character(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				(data->C)++;
			if (data->map[i][j] == 'E')
				(data->E)++;
			if (data->map[i][j] == 'P')
				(data->P)++;
			j++;
		}
		i++;
	}
	if (data->P != 1 || data->E != 1 || data->C < 1)
		error(data, "ERROR: Map Invalid\n");
}
