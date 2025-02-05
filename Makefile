NAME = so_long
CC = cc
CFLAGS = -Imlx_linux -Iheaders -Wall -Wextra -Werror -g3 
SRCS =	sources/error_cleanup.c \
		sources/game_start.c \
		sources/initializers.c \
		sources/main.c \
		sources/map_checkers.c \
		sources/map_loader.c \
		sources/map_nav.c \
		\
		libft/ft_strlen.c \
		libft/ft_strlcat.c \
		libft/ft_strjoin.c \
		\
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c 
OBJS = $(SRCS:.c=.o)
MLX_DIR = mlx_linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a


all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(OBJS) $(MLX_LIB) $(CFLAGS) -L/usr/lib -I/usr/include -lXext -lX11 -lm -lz -o $(NAME)

$(MLX_LIB):
	make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
