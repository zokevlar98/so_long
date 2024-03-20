/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:25:41 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/20 06:54:43 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#define W 13
#define A 0
#define S 1
#define D 2

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
	int		width;
	int		height;
	int		x;
	int		y;
	int		P;
	int		C;
	int		E;
	int		move;
	char	*line;
	char	**map;
	char	**map_copy;
}	t_data;


//Mandatory :
void	usage(void);
void	error(t_data *data, char *str);
void	wrong_extension(void);
void	init_data(t_data *data);

//PARSING :
void	check_file(t_data *data, char *argv);
void	check_extension(char *argv);
void	put_map(t_data *data, char **argv);
void	check_size(t_data *data);
void	check_border_up_down(t_data *data);
void	check_border_left_right(t_data *data);
void	count_map_character(t_data *data);
void	check_map_valid(t_data *data, char **argv);
void    copy_map(t_data *data);
void    serche_player_position(t_data *data);
void    flood_fill(t_data *data);
void	check_map_copy(t_data *data);
//mazal 5asse parsing
void	free_map(char **map);
void	clear_data(t_data *data);

//Fonction utils :
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int nbr, int fd);
char	**ft_split_up(char *s);
void	ft_free(char **tab);
void	check_characters(t_data *data);
char	**ft_split(char *s, char c);
void    flood_fill(t_data *data);
//Game_play :
void    game_play(t_data *data);
#endif