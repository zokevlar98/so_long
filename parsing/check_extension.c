/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:34:36 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/14 20:23:42 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_paths(char *argv)
{
	int	fd;
	
	fd = open(argv, O_RDWR, 0666);
	if (fd == -1)
	{
		close(fd);
		error("ERROR: NO such Directory or file\n");
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
	int	c;
	int	e;
	int	p;

	i = 0;
	c = 0;
	e = 0;
	p = 0;
	while (data->map[i])
	{
		if (ft_strchr(data->map[i], 'C'))
			c++;
		if (ft_strchr(data->map[i], 'E'))
			e++;
		if (ft_strchr(data->map[i], 'P'))
			p++;
		i++;
	}
	if (p != 1 || e != 1 || c < 1)
		error("ERROR: Map Invalid\n");
}