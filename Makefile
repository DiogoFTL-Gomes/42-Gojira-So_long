NAME = so_long
CC = cc
CFLAGS = -Imlx_linux -O3 -Wall -Wextra -Werror
SRCS = teste.c
OBJS = $(SRCS:.c=.o)
MLX_DIR = mlx_linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(OBJS) -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I/usr/include -lXext -lX11 -lm -lz -o $(NAME)

$(MLX_LIB):
	make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re
