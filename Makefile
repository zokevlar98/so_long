NAME = so_long

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS =	parsing/ft_strlen.c			\
		parsing/ft_putstr_fd.c		\
		parsing/ft_split.c			\
		parsing/ft_strjoin.c		\
		parsing/ft_strncmp.c		\
		mandatory/error.c			\
		mandatory/usage.c			\
		mandatory/so_long.c			\

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	cc $(MLX_FLAGS) $(OBJS) -o $(NAME)

%.o:%.c includes/so_long.h Makefile
	cc $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re