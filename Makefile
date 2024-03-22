NAME = so_long

CFLAGS = -Wall -Wextra -I ./includes 

RM = rm -rf

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS =	mandatory/so_long.c			\
		mandatory/game_play.c		\
		mandatory/display_game.c	\
		mandatory/error.c			\
		mandatory/usage.c			\
		mandatory/print_map.c		\
		parsing/check_extension.c	\
		parsing/check_map.c			\
		parsing/clear_data.c		\
		parsing/check_map_valid.c	\
		utils/ft_putstr_fd.c		\
		utils/ft_split.c			\
		utils/ft_strjoin_utils.c	\
		utils/flood_fill.c			\
		utils/ft_strncmp.c			\
		utils/ft_split_up.c			\
		gnl/get_next_line.c			\
		gnl/get_next_line_utils.c	\

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	cc $(MLX_FLAGS) $(OBJS) -o $(NAME)

%.o:%.c includes/so_long.h
	cc $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re