/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:25:41 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/13 17:00:36 by zqouri           ###   ########.fr       */
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
# include "../gnl/get_next_line.h"

typedef struct s_img
{
	void	*player;
	void	*coin;
	void	*door;
	void	*road;
	void	*wall;
}	t_img;

typedef struct s_data
{
	t_img	img;
	void	*mlx_p;
	void	*win_p;
	int		fd;
	int		hauteur;
	int		largeur;
	int		x;
	int		y;
	char	*line;
	char	**map;
}	t_data;


//Mandatory
void	usage(void);
void	error(void);
void	wrong_extension(void);

//PARSING :
void	check_paths(char *argv);
void	check_extension(char *argv);
char	**put_map(t_data *data, char **argv);
//size_t	ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *str, int fd);
char	**ft_split_up(char *s);
#endif