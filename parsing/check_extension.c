/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:34:36 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/13 15:22:42 by zqouri           ###   ########.fr       */
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
		error();
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
