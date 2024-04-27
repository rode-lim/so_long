CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L/home/lima/minilibx_linux -lmlx -lXext -lX11 -L/home/lima/ft_printf -lftprintf -L/home/lima/libft -lft
NAME = my_program
SRC = main.c \
		map.c \
		windows.c \
		image.c \
		handle_errors.c \
		so_next_line_long.c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(LDFLAGS)

clean:
	rm -f $(NAME)

re: clean all