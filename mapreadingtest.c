#include "so_long.h"

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
	int testa = ft_strlen(argv[1]);
	int final = 64 * testa;
	t_vars vars;

	i = 0;
	if (argc != 2)
	{
		printf("Error\nInvalid number of arguments\n");
		return (1);
	}
	if (argc == 2)
	{
		i = ft_strlen(argv[1]);
		printf("The length of the string is: %d\n", i);
		printf("\n");
	}

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
	mlx_loop(vars.mlx);

	return (0);
}