/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:10:54 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/13 00:52:05 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	int		i;
	int		fd;
	char	**map;

	
	if (argc == 2)
	{
		check_paths(argv[1]);
		check_extension(argv[1]);
		fd = open(argv[1], O_RDWR, 0666);
		if (fd == -1)
			error();
		put_map(fd);
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