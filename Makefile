NAME = so_long

CFLAGS = -Wall -Wextra -Werror -I ./includes

RM = rm -rf

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS =	parsing/ft_putstr_fd.c		\
		parsing/ft_split.c			\
		parsing/ft_strjoin_utils.c	\
		parsing/ft_strncmp.c		\
		parsing/check_extension.c	\
		parsing/put_map.c			\
		parsing/ft_split_up.c		\
		mandatory/error.c			\
		mandatory/usage.c			\
		mandatory/so_long.c			\
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