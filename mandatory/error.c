/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:15:13 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/13 00:26:12 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error(void)
{
	perror("\033[31mERROR");
	exit (EXIT_FAILURE);
}

void	wrong_extension(void)
{
	ft_putstr_fd("\033[31mError: Bad arguments extension\n", 2);
	ft_putstr_fd("Like : ./so_long map.ber\n", 1);
	exit (EXIT_FAILURE);
}
