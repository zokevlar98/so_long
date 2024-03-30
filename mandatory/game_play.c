/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:53:53 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/30 06:57:13 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_moves(t_data *data)
{
	ft_putstr_fd("Moves : ", STDOUT_FILENO);
	(data->move)++;
	ft_putnbr_fd(data->move, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

void	game_over(t_data *data, int win)
{
	if (win == 1)
	{
		clear_data(data);
		ft_putstr_fd("YOU WIN!\n", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	if (win == 0)
	{
		clear_data(data);
		ft_putstr_fd("YOU LOSE!\n", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	else
		error(data, "ERROR: game_over failed\n");
}

void	move_player(t_data *data, int key_code, int x, int y)
{
	x = data->x;
	y = data->y;
	if (key_code == W || key_code == UP)
		x--;
	if (key_code == A || key_code == LEFT)
		y--;
	if (key_code == S || key_code == DOWN)
		x++;
	if (key_code == D || key_code == RIGHT)
		y++;
	if (data->map[x][y] == '0' || data->map[x][y] == 'C')
	{
		data->map[data->x][data->y] = '0';
		data->x = x;
		data->y = y;
		if (data->map[x][y] == 'C')
			(data->c)--;
		data->map[x][y] = 'P';
		display_game(data);
		display_moves(data);
	}
	if (data->c == 0 && data->map[x][y] == 'E')
	{
		display_moves(data);
		game_over(data, 1);
	}
}

int	key_hook(int key_code, t_data *data)
{
	if (key_code == 53)
		game_over(data, 0);
	if (key_code == W || key_code == A || key_code == S || key_code == D
		|| key_code == UP || key_code == LEFT || key_code == DOWN
		|| key_code == RIGHT)
		move_player(data, key_code, 0, 0);
	return (0);
}

void	game_play(t_data *data)
{
	data->mlx_p = mlx_init();
	if (data->mlx_p == NULL)
		error(data, "ERROR: mlx_init failed\n");
	init_imgs(data);
	data->win_p = mlx_new_window(data->mlx_p, (data->width) * 64, (data->height)
			* 64, "so_long");
	if (data->win_p == NULL)
		error(data, "ERROR: mlx_new_window failed\n");
	display_game(data);
	mlx_key_hook(data->win_p, key_hook, data);
	mlx_hook(data->win_p, BOUTON_CLOSE, 0, key_hook_mouse, data);
	mlx_loop(data->mlx_p);
}
