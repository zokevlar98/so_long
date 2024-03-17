/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:04:38 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/17 18:36:31 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_valid(t_data *data, char **argv)
{
	check_file(data, argv[1]);
	put_map(data, argv);
	check_size(data);
	check_border_up_down(data);
	check_border_left_right(data);
	check_characters(data);
	check_map_character(data);
    // check_valid_path(data);
    copy_map(data);
    serche_player_position(data);
}

// void    check_valid_path(t_data *data)
// {
//     copy_map(data);
//     serche_player_position(data);
//     Backtracking_path(data, data->x, data->y);
// }

void    copy_map(t_data *data)
{
    int i;
    int j;

    i = 0;
    data->map_copy = malloc(sizeof(char *) * (data->hauteur + 1));
    if (data->map_copy == NULL)
        error(data, "ERROR: Allcoation failed\n");
    while (data->map[i])
    {
        j = 0;
        data->map_copy[i] = malloc(sizeof(char) * (data->largeur + 1));
        if (data->map_copy[i] == NULL)
            error(data, "ERROR: Allcoation failed\n");
        while (data->map[i][j])
        {
            data->map_copy[i][j] = data->map[i][j];
            j++;
        }
        i++;
    }
    data->map_copy[i] = NULL;
}

void    serche_player_position(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == 'P')
            {
                data->x = i;
                data->y = j;
                return ;
            }
            j++;
        }
        i++;
    }
}

// void    Backtracking_path(t_data *data, int i, int j)
// {
//     char **map;

//     map = data->map_copy;
//     if (map[i][j] == '0' || map[i][j] == 'C' || map[i][j] == 'P')
//     {
//         if (map[i][j] == 'C')
//             data->C--;
//         map[i][j] = 'V';
//         if (i > 0)
//             Backtracking_path(data, i - 1, j);
//         if (j > 0)
//             Backtracking_path(data, i, j - 1);
//         if (i < data->hauteur - 1)
//             Backtracking_path(data, i + 1, j);
//         if (j < data->largeur - 1)
//             Backtracking_path(data, i, j + 1);
//     }
//     else if (map[i][j] == 'E' && data->C == 0)
//         return ;
//     else
//         error(data, "ERROR: Map is not valid\n");
// }

void	flood_fill(t_data *data, int i, int j)
{
    if (i < 0 || j < 0 || i >= data->largeur
        || j >= data->hauteur || data->map_copy[i][j] == '1'
            || data->map_copy[i][j] == 'X')
        return ;
    if (((data->map_copy[i + 1][j] == 'E')
        || (data->map_copy[i - 1][j] == 'E'))
        && ((data->map_copy[i][j + 1] == '1')
            || (data->map_copy[i][j - 1] == '1')))
        return ;
    if (((data->map_copy[i][j + 1] == 'E')
        || (data->map_copy[i][j - 1] == 'E'))
        && ((data->map_copy[i + 1][j] == '1')
        || (data->map_copy[i - 1][j] == '1')))
        return ;
    if (data->map_copy[i][j] == 'E' ||
        data->map_copy[i][j] == 'C')
        data->map_copy[i][j] = '0';
    data->map_copy[i][j] = 'X';
    flood_fill(data, i - 1, j);
    flood_fill(data, i + 1, j);
    flood_fill(data, i, j - 1);
    flood_fill(data, i, j + 1);
}

/* Funtion recursive to use flood fill*/
void	ft_to_fill(t_data *data, int i, int j)
{
    flood_fill(data, i, j);
}

void	verify_win(t_data *data)
{
    int		i;
    int		j;

    i = 0;
    serche_player_position(data);
    ft_to_fill(data, data->x, data->y);
    while (data->map_copy[i])
    {
        j = 0;
        while (data->map_copy[i][j])
        {
            if (data->map_copy[i][j] == 'C'
                || data->map_copy[i][j] == 'E')
                error(data, "ERROR: Map is not valid\n");
            j++;
        }
        i++;
    }
}