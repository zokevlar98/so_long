/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:10:54 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/12 15:37:38 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	(void)argv;
	if (argc == 2)
	{
	}
	else
		usage();
	return (0);
}

//int	main(void)
//{
//	void	*mlx;
//	void	*mlx_win;

//	mlx = mlx_init();
//	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
//	mlx_loop(mlx);
//}