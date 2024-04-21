CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L/home/lima/minilibx_linux -lmlx -lXext -lX11
NAME = my_program
SRC = main.c \ map.c \ mapmaster.c \ windows.c \ image.c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(LDFLAGS)

clean:
	rm -f $(NAME)

re: clean all