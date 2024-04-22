#include "so_long.h"

void	ft_error_map(char *str, t_game *game)
{
	if (game->error == 0)
		ft_printf("%s", str);
	game->error++;
}

void	destroy_map(t_game *game)
{
	int	i;

	i = 0;
	while(game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	window_destroy(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	destroy_map(game);
	free(game->mlx);
	exit(1);
}

void	ft_error(char *str, t_game *game)
{
	ft_printf("%s", str);
	window_destroy(game);
	exit(1);
}