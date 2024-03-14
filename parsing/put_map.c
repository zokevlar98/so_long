/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 00:44:43 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/14 18:17:32 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**put_map(t_data *data, char **argv)
{
	char	*tmp;

	data->fd = open(argv[1], O_RDWR, 0666);
	if (data->fd == -1)
		error("ERROR: No such file\n");
	tmp = get_next_line(data->fd);
	while (tmp)
	{
		data->line = ft_strjoin(data->line, tmp);
		free(tmp);
		tmp = get_next_line(data->fd);
		(data->hauteur)++;
	}
	if (data->hauteur == 0)
		error("ERROR: Map Empty\n");
	data->map = ft_split(data->line, '\n');
	if (data->map == NULL)
		error("ERROR: Faile Malloc\n");
	return (data->map);
}

void	check_size(t_data *data)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(data->map[0]);
	while (data->map[i])
	{
		if (len != ft_strlen(data->map[i]))
			error("Invalid map len!\n");
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
			error("ERROR: No wall in border up\n");
		j++;
	}
	while (data->map[i] != NULL)
		i++;
	i--;
	j = 0;
	while (data->map[i][j])
	{
		if (data->map[i][j] != '1')
			error("ERROR: No wall in border down\n");
		j++;
	}
}

void	check_border_left_right(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	data->largeur = (int)ft_strlen(data->map[i]) - 1;
	while (data->map[i])
	{
		j = 0;
		if (data->map[i][j] != '1')
			error("ERROR: No wall in border left\n");
		j = ft_strlen(data->map[i]) - 1;
		if (data->map[i][j] != '1')
			error("ERROR: No wall in border right\n");
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
				ft_free(ptr);//5assni mnin neb4i ne5raj free struct kamelha
				error("ERROR: Invalide Character\n");
			}
			j++;
		}
		i++;
	}
}