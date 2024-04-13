#ifndef SO_LONG_H
#define SO_LONG_H

#include "../minilibx_linux/mlx.h"

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>


// main.c
/* Function prototypes
void draw_zigzag_line(void *mlx, void *win, int x, int y);
void draw_zigzag_line2(void *mlx, void *win, int x, int y);
void draw_zigzag_line3(void *mlx, void *win, int x, int y);
void draw_zigzag_line4(void *mlx, void *win, int x, int y);
void draw_zigzag_line5(void *mlx, void *win, int x, int y);
void draw_zigzag_line6(void *mlx, void *win, int x, int y);
*/


// testing.c

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
}	t_vars;

//int		key_hook(int keycode, t_vars *vars);

#endif // SO_LONG_H