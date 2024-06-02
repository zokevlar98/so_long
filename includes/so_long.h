/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:25:41 by zqouri            #+#    #+#             */
/*   Updated: 2024/06/02 22:18:09 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define LEFT 123
# define DOWN 125
# define RIGHT 124
# define BOUTON_CLOSE 17

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
	int		p;
	int		c;
	int		e;
	int		move;
	char	*line;
	char	**map;
	char	**map_copy;
}	t_data;

void	usage(void);
void	error(t_data *data, char *str);
void	wrong_extension(void);
void	init_data(t_data *data);
void	init_imgs(t_data *data);
void	put_imgs_to_window(t_data *data, int x, int y);
void	display_game(t_data *data);
int		key_hook(int key_code, t_data *data);
void	check_file(t_data *data, char *argv);
void	check_extension(char *argv);
void	put_map(t_data *data, char **argv);
void	check_size(t_data *data);
void	check_border_up_down(t_data *data);
void	check_border_left_right(t_data *data);
void	count_map_character(t_data *data);
void	check_map_valid(t_data *data, char **argv);
void	copy_map(t_data *data);
void	search_player_position(t_data *data);
void	flood_fill(t_data *data);
void	check_map_copy(t_data *data);
void	check_characters(t_data *data);
void	free_map(char **map);
int		key_hook_mouse(t_data *data);
void	clear_data(t_data *data);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int nbr, int fd);
char	**ft_split_up(char *s);
void	ft_free(char **tab);
char	**ft_split(char *s, char c);
void	flood_fill(t_data *data);
void	game_play(t_data *data);
void	display_moves(t_data *data);
#endif