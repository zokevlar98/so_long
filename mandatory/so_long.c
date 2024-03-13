/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:10:54 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/13 18:07:13 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_data(t_data *data)
{
	data->mlx_p = NULL;
	data->win_p = NULL;
	data->fd = 0;
	data->hauteur = 0;
	data->largeur = 0;
	data->x = 0;
	data->y = 0;
	data->line = NULL;
	data->map = NULL;
}

int	main(int argc, char *argv[])
{
	t_data	*data;
	int	i = 0;

	data = malloc(sizeof(t_data));
	if (!data)
		error();
	init_data(data);
	if (argc == 2)
	{
		check_paths(argv[1]);
		data->map = put_map(data, argv);
		while (data->map[i] != NULL)
		{
			printf("%s", data->map[i]);
			i++;
		}
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