NAME    	= so_long

CFLAGS  	= -Wall -Werror -Wextra -O3 -g
INCLUDE 	= -I include

LIBFTDIR	= ../Libft
LIBFT   	= $(LIBFTDIR)/libft.a

LIBMLXDIR 	= ../mlx
LIBMLX  	= $(LIBMLXDIR)/libmlx_Linux.a


LFLAGS  	= -L$(LIBMLXDIR) -lmlx -L${LIBFTDIR} -lft
UNAME   	:= $(shell uname)
ifeq ($(UNAME), Darwin)
			CC = gcc
			LFLAGS += -framework OpenGL -framework AppKit
else ifeq ($(UNAME), FreeBSD)
			CC = clang
else
			CC = gcc
			FLAGS += -D LINUX
			LFLAGS += -lbsd -lXext -lX11 -lm
endif

SRC_DIR 	= mainfiles
SRC     	= $(wildcard $(SRC_DIR)/*.c)
OBJ     	= $(SRC:%.c=%.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			make -s -C $(LIBFTDIR)
			make -s -C $(LIBMLXDIR)
			$(CC) main.c $(FLAGS) $(OBJ) $(INCLUDE) $(LIBFT) $(LIBMLX) $(LFLAGS) -o $(NAME)

clean :
			@make clean -s -C $(LIBFTDIR)
			rm -rf $(OBJ)

fclean:		clean
			rm -rf $(LIBFT)
			rm -rf $(NAME)

re:		fclean all