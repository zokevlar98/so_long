/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:53:53 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/20 07:08:47 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    init_imgs(t_data *data)
{
    int     width;
    int     height;
    
    data->img.player = mlx_xpm_file_to_image(data->mlx_p, "./images/player.xpm", &width, &height);
    if (!(data->img.player))
        error(data, "ERROR: mlx_xpm_file_to_image failed\n");
    data->img.coin = mlx_xpm_file_to_image(data->mlx_p, "./images/coin.xpm", &width, &height);
    if (!(data->img.coin))
        error(data, "ERROR: mlx_xpm_file_to_image failed\n");
    data->img.door = mlx_xpm_file_to_image(data->mlx_p, "./images/door.xpm", &width, &height);
    if (!(data->img.door))
        error(data, "ERROR: mlx_xpm_file_to_image failed\n");
    data->img.road = mlx_xpm_file_to_image(data->mlx_p, "./images/road.xpm", &width, &height);
    if (!(data->img.road))
        error(data, "ERROR: mlx_xpm_file_to_image failed\n");
    data->img.wall = mlx_xpm_file_to_image(data->mlx_p, "./images/wall.xpm", &width, &height);
    if (!(data->img.wall))
        error(data, "ERROR: mlx_xpm_file_to_image failed\n");
}

void    put_imgs_to_window(t_data *data, int x, int y)
{
    if (data->map[x][y] == 'P')
        mlx_put_image_to_window(data->mlx_p, data->win_p, data->img.player, y * 64, x * 64);
    if (data->map[x][y] == 'C')
        mlx_put_image_to_window(data->mlx_p, data->win_p, data->img.coin, y * 64, x * 64);
    if (data->map[x][y] == 'E')
        mlx_put_image_to_window(data->mlx_p, data->win_p, data->img.door, y * 64, x * 64);
    if (data->map[x][y] == '0')
        mlx_put_image_to_window(data->mlx_p, data->win_p, data->img.road, y * 64, x * 64);
    if (data->map[x][y] == '1')
        mlx_put_image_to_window(data->mlx_p, data->win_p, data->img.wall, y * 64, x * 64);
}

void    display_game(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->map[i])
    {
        j = -1;
        while (data->map[i][++j])
            put_imgs_to_window(data, i, j);
        i++;
    }
}

void    display_moves(t_data *data)
{
    ft_putstr_fd("Moves : ", 1);
    (data->move)++;
    ft_putnbr_fd(data->move, 1);
    ft_putchar_fd('\n', 1);
}

void    close(t_data *data)
{
    
}

void    move_player(t_data *data, int key_code)
{
    int x;
    int y;

    x = data->x;
    y = data->y;
    if (key_code == W)
        x--;
    if (key_code == A)
        y--;
    if (key_code == S)
        x++;
    if (key_code == D)
        y++;
    if (data->map[x][y] == '0' || data->map[x][y] == 'C')
    {
        data->map[data->x][data->y] = '0';
        data->x = x;
        data->y = y;
        if (data->map[x][y] == 'C')
            (data->C)--;
        data->map[x][y] = 'P';
        mlx_clear_window(data->mlx_p, data->win_p);
        display_game(data);
        display_moves(data);
    }
    if (data->C == 0 && data->map[x][y] == 'E')
    {
        clear_data(data);
        printf("You win\n");
        exit(EXIT_SUCCESS);
    }
}

int key_hook(int key_code, t_data *data)
{
    if (key_code == 53)
        clear_data(data);
    if (key_code == W || key_code == A || key_code == S || key_code == D)
        move_player(data, key_code);
    return (0);
}

void    game_play(t_data *data)
{
    data->mlx_p = mlx_init();
    if (data->mlx_p == NULL)
        error(data, "ERROR: mlx_init failed\n");
    init_imgs(data);
    data->win_p = mlx_new_window(data->mlx_p, (data->width) * 64, (data->height) * 64, "so_long");
    if (data->win_p == NULL)
        error(data, "ERROR: mlx_new_window failed\n");
    display_game(data);
    mlx_key_hook(data->win_p, key_hook, data);
    mlx_loop(data->mlx_p);
}
