/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:10:54 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/14 17:55:11 by zqouri           ###   ########.fr       */
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

	data = malloc(sizeof(t_data));
	if (!data)
		error("Malloc faile\n");
	init_data(data);
	if (argc == 2)
	{
		check_paths(argv[1]);
		data->map = put_map(data, argv);
		//int	i = 0;
		//while (data->map[i] != NULL)
		//{
		//	printf("%s\n", data->map[i]);
		//	i++;
		//}
		check_size(data);
		check_border_up_down(data);
		check_border_left_right(data);
		check_characters(data);
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