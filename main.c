// main.c

#include "so_long.h"

// // Define a struct to hold your application state
//typedef struct  s_vars {
//     void    *mlx;
//     void    *win;
//     int     x;
//     int     y;
//}               t_vars;

// Define a function to handle key press events
// int key_hook(int keycode, t_vars *vars)
// {
//     if (keycode == 'w') // Move up
//         vars->y--;
//     else if (keycode == 'a') // Move left
//         vars->x--;
//     else if (keycode == 's') // Move down
//         vars->y++;
//     else if (keycode == 'd') // Move right
//         vars->x++;

//     // Redraw the pixel at the new position
//     mlx_pixel_put(vars->mlx, vars->win, vars->x, vars->y, 0xFFFFFF);

//     return (0);
// }

// int main(void)
// {
//     t_vars vars;

//     vars.mlx = mlx_init();
//     if (!vars.mlx) {
//         printf("Failed to initialize mlx\n");
//         return (1);
//     }

//     vars.win = mlx_new_window(vars.mlx, 800, 600, "My game");
//     if (!vars.win) {
//         printf("Failed to create window\n");
//         return (1);
//     }

//     vars.x = 400; // Initial position
//     vars.y = 300;

//     // Draw the initial pixel
//     mlx_pixel_put(vars.mlx, vars.win, vars.x, vars.y, 0xFFFFFF);

//     // Set up the key press hook
//     mlx_key_hook(vars.win, key_hook, &vars);

//     mlx_loop(vars.mlx);

//     return (0);
// }

void draw_zigzag_line(void *mlx, void *win, int x, int y)
{
    int a;

    a = 0;
    y = 100;
    x = 250;
    while (a != 150)
    {
        mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
        y++;
        a++;
    }
}

void draw_zigzag_line2(void *mlx, void *win, int x, int y)
{
    x = 250;
    y = 250;
    while (x != 602)
    {
        mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
        x++;
    }
}

void draw_zigzag_line3(void *mlx, void *win, int x, int y)
{
    y = 250;
    x = 602;
    while (y != 400)
    {
        mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
        y++;
    }
}

void draw_zigzag_line4(void *mlx, void *win, int x, int y)
{
    x = 421;
    y = 100;
    while (y != 400)
    {
        mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
        y++;
    }
}

void draw_zigzag_line5(void *mlx, void *win, int x, int y)
{
    int a;

    a = 0;
    x = 421;
    y = 400;
    while (a != 170)
    {
        mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
        x--;
        a++;
    }
}
void draw_zigzag_line6(void *mlx, void *win, int x, int y)
{
    int a;

    a = 0;
    x = 421;
    y = 100;
    while (a != 180)
    {
        mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
        x++;
        a++;
    }
}


int main(void)
{
    void *mlx;
    void *win;
    int width = 800;
    int height = 600;

    mlx = mlx_init();
    if (!mlx) {
        printf("Failed to initialize mlx\n");
        return (1);
    }

    win = mlx_new_window(mlx, width, height, "My game");
    if (!win) {
        printf("Failed to create window\n");
        return (1);
    }

    draw_zigzag_line(mlx, win, 0, 0);
    draw_zigzag_line2(mlx, win, 0, 0);
    draw_zigzag_line3(mlx, win, 0, 0);
    draw_zigzag_line4(mlx, win, 0, 0);
    draw_zigzag_line5(mlx, win, 0, 0);
    draw_zigzag_line6(mlx, win, 0, 0);

    mlx_loop(mlx);

    return (0);
}