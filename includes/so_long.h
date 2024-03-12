/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:25:41 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/11 00:59:01 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <stddef.h>
# include <math.h>
# include <mlx.h>

typedef struct s_map
{
	int	c;
	int	e;
}	t_map;

typedef struct s_data
{
	void	*mlx_p;
	void	*win_p;
	t_map	*map;
}	t_data;

void	usage(void);
void	error(void);
size_t	ft_strlen(char *str);
void	ft_putstr_fd(char *str, int fd);
#endif