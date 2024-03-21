/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:34:36 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/21 18:48:41 by zqouri           ###   ########.fr       */
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

void	count_map_character(t_data *data)
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
				(data->c)++;
			if (data->map[i][j] == 'E')
				(data->e)++;
			if (data->map[i][j] == 'P')
				(data->p)++;
			j++;
		}
		i++;
	}
	if (data->p != 1 || data->e!= 1 || data->c < 1)
		error(data, "ERROR: Map Invalid\n");
}
