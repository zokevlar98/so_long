/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:42:24 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/17 20:42:56 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    dfs(t_data *data, int i, int j)
{
    if (i < 0 || j < 0 || i >= data->hauteur || j >= data->largeur
        || data->map_copy[i][j] == '1' || data->map_copy[i][j] == 'V')
        return ;
    if (data->map_copy[i][j] == 'C')
        data->C--;
    data->map_copy[i][j] = 'V';
    dfs(data, i - 1, j);
    dfs(data, i + 1, j);
    dfs(data, i, j - 1);
    dfs(data, i, j + 1);
}

void    flood_fill(t_data *data)
{
    dfs(data, data->x, data->y);
}
