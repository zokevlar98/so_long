/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:15:13 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/21 20:25:25 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(t_data *data, char *str)
{
	clear_data(data);
	ft_putstr_fd("\033[31m", 2);
	ft_putstr_fd(str, 2);
	exit (EXIT_FAILURE);
}

void	wrong_extension(void)
{
	ft_putstr_fd("\033[31mError: Bad arguments extension\n", 2);
	ft_putstr_fd("Like : ./so_long map.ber\n", 1);
	exit (EXIT_FAILURE);
}
