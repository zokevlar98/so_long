/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:18:20 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/15 20:24:27 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr_fd(char *str, int fd)
{
	size_t	i;

	if (!str)
		return ;
	i = 0;
	while (i < ft_strlen(str))
	{
		write(fd, &str[i], 1);
		i++;
	}
}
