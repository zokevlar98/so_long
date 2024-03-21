/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 00:44:43 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/21 20:31:17 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_map(t_data *data, char **argv)
{
	char	*tmp;

	data->fd = open(argv[1], O_RDWR, 0666);
	if (data->fd == -1)
		error(data, "ERROR: No such file\n");
	tmp = get_next_line(data->fd);
	while (tmp)
	{
		data->line = ft_strjoin(data->line, tmp);
		free(tmp);
		tmp = get_next_line(data->fd);
		(data->height)++;
	}
	if (data->height == 0)
		error(data, "ERROR: Map Empty\n");
	data->map = ft_split(data->line, '\n');
	if (data->map == NULL)
		error(data, "ERROR: Allcoation failed\n");
}

void	check_size(t_data *data)
{
	size_t	i;

	i = 0;
	data->width = (int)ft_strlen(data->map[0]);
	while (data->map[i])
	{
		if (data->width != (int)ft_strlen(data->map[i]))
			error(data, "Invalid map len!\n");
		i++;
	}
}

void	check_border_up_down(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (data->map[i][j])
	{
		if (data->map[i][j] != '1')
			error(data, "ERROR: No wall in border up\n");
		j++;
	}
	while (data->map[i] != NULL)
		i++;
	i--;
	j = 0;
	while (data->map[i][j])
	{
		if (data->map[i][j] != '1')
			error(data, "ERROR: No wall in border down\n");
		j++;
	}
}

void	check_border_left_right(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		if (data->map[i][j] != '1')
			error(data, "ERROR: No wall in border left\n");
		j = ft_strlen(data->map[i]) - 1;
		if (data->map[i][j] != '1')
			error(data, "ERROR: No wall in border right\n");
		i++;
	}
}

void	check_characters(t_data *data)
{
	int		i;
	int		j;
	char	**ptr;

	i = 0;
	ptr = data->map;
	while (ptr[i] != NULL)
	{
		j = 0;
		while (ptr[i][j])
		{
			if (ptr[i][j] != '0' && ptr[i][j] != '1' && ptr[i][j] != 'C'
				&& ptr[i][j] != 'E' && ptr[i][j] != 'P')
			{
				ft_free(ptr);
				error(data, "ERROR: Invalide Character\n");
			}
			j++;
		}
		i++;
	}
}
