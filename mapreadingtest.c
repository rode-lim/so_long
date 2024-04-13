#include "so_long.h"

void	ft_readmap(t_vars *vars, char *map, int len)
{
	void	*img;
	char	*relative_paths[] = {"./images/1.xpm", "./images/2.xpm", "./images/3.xpm", "./images/4.xpm"};
	int		img_width;
	int		img_height;
	int reader;
	int index;

	reader = 0;
	while (reader < len)
	{
		index = -1;
		if (map[reader] == '1') index = 0;
		else if (map[reader] == '0') index = 1;
		else if (map[reader] == 'P') index = 2;
		else if (map[reader] == 'E') index = 3;

		if (index != -1)
		{
			img = mlx_xpm_file_to_image(vars->mlx, relative_paths[index], &img_width, &img_height);
			if (img == NULL) {
				fprintf(stderr, "Failed to load image\n");
				return;
			}
			mlx_put_image_to_window(vars->mlx, vars->win, img, reader * img_width, 0);
		}
		reader++;
	}
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int i;
	int testa;
	int final;
	t_vars vars;

	if (argc != 2)
	{
		printf("Error\nInvalid number of arguments\n");
		return (1);
	}

	testa = ft_strlen(argv[1]);
	final = 64 * testa;

	vars.mlx = mlx_init();
	if (!vars.mlx)
	{
		printf("Error\nFailed to initialize mlx\n");
		return (1);
	}
	vars.win = mlx_new_window(vars.mlx, final, 64, "My game");
	if (!vars.win)
	{
		printf("Error\nFailed to create window\n");
		return (1);
	}

	i = ft_strlen(argv[1]);
	printf("The length of the string is: %d\n", i);
	printf("\n");
	ft_readmap(&vars, argv[1], i);

	mlx_loop(vars.mlx);

	return (0);
}