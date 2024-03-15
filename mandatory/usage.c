/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:14:21 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/14 21:04:57 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	usage(void)
{
	ft_putstr_fd("\033[31mError: Bad arguments\n", 2);
	ft_putstr_fd("Like : ./so_long map.ber\n", 1);
	exit (EXIT_FAILURE);
}
