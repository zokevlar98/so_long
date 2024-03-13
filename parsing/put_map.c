/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 00:44:43 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/13 18:08:13 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**put_map(t_data *data, char **argv)
{
	char	*tmp;

	data->fd = open(argv[1], O_RDWR, 0666);
	if (data->fd == -1)
		error();
	tmp = get_next_line(data->fd);
	while (tmp)
	{
		data->line = ft_strjoin(data->line, tmp);
		free(tmp);
		tmp = get_next_line(data->fd);
		(data->hauteur)++;
	}
	if (data->hauteur == 0)
		error();
	data->map = ft_split_up(data->line);
	if (data->map == NULL)
		error();
	return (data->map);
}
	//RAT3mar array two 2 dimention bash mn be3d ntcheker 0 et 1 et E et C