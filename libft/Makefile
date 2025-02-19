# Variáveis
CC = cc
CFLAGS = -Wall -Wextra -Werror -I../headers
SRCS = 	ft_strlen.c \
		ft_strlcat.c \
		ft_strjoin.c \
		ft_putchar_fd.c \
		ft_putnbr_fd.c
OBJS = $(SRCS:.c=.o)
NAME = libft.a

# Regra padrão (equivalente a make all)
all: $(NAME)

# Criação da biblioteca libft.a
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Remove arquivos .o
clean:
	rm -f $(OBJS)

# Remove arquivos .o e a biblioteca
fclean: clean
	rm -f $(NAME)

# Recompila tudo do zero
re: fclean all

# Impede que o Makefile trate estas palavras como nomes de arquivos
.PHONY: all clean fclean re
