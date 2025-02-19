NAME = so_long
CC = cc
CFLAGS = -Imlx_linux -Iheaders -Wall -Wextra -Werror -g3 
SRCS =	sources/main.c \
		sources/error_cleanup.c \
		sources/game_start.c \
		sources/initializers.c \
		sources/map_checkers.c \
		sources/map_loader.c \
		sources/map_nav.c \
		sources/load_textures.c \
		sources/render_frames.c
OBJS = $(SRCS:.c=.o)

MLX_DIR = mlx_linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

GNL_DIR = get_next_line
GNL_LIB = $(GNL_DIR)/libgnl.a

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB) $(LIBFT_LIB) $(GNL_LIB)
	$(CC) $(OBJS) $(CFLAGS) $(MLX_LIB) $(LIBFT_LIB) $(GNL_LIB) -L/usr/lib -I/usr/include -lXext -lX11 -lm -lz -lbsd -o $(NAME)

$(MLX_LIB):
	make -C $(MLX_DIR)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(GNL_LIB):
	make -C $(GNL_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(MLX_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(GNL_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(GNL_DIR)

re: fclean all

.PHONY: all clean fclean re
