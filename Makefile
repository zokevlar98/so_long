NAME = so_long

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS =	gnl/get_next_line.c		\
		gnl/get_next_line_utils.c	\

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

%.o:%.c includes/so_long.h Makefile
	cc $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re