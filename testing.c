#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == 123)
	{
		vars->x -= 10;
		mlx_pixel_put(vars->mlx, vars->win, vars->x, vars->y, 0xFFFFFF);
	}
	if (keycode == 124)
	{
		vars->x += 10;
		mlx_pixel_put(vars->mlx, vars->win, vars->x, vars->y, 0xFFFFFF);
	}
	if (keycode == 125)
	{
		vars->y += 10;
		mlx_pixel_put(vars->mlx, vars->win, vars->x, vars->y, 0xFFFFFF);
	}
	if (keycode == 126)
	{
		vars->y -= 10;
		mlx_pixel_put(vars->mlx, vars->win, vars->x, vars->y, 0xFFFFFF);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
	{
		printf("Error\nInvalid number of arguments\n");
		return (1);
	}
	vars.mlx = mlx_init();
	if (!vars.mlx)
	{
		printf("Error\nFailed to initialize mlx\n");
		return (1);
	}
	vars.win = mlx_new_window(vars.mlx, 800, 600, "My game");
	if (!vars.win)
	{
		printf("Error\nFailed to create window\n");
		return (1);
	}
	vars.x = 400;
	vars.y = 300;
	mlx_pixel_put(vars.mlx, vars.win, vars.x, vars.y, 0xFFFFFF);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}