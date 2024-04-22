#include "so_long.h"

void	ft_error_map(char *str, t_game *game)
{
	if (game->error == 0)
		ft_printf("%s", str);
	game->error++;
}

void	ft_error(char *str, t_game *game)
{
	ft_printf("%s", str);
	window_destroy(game);
	exit(1);
}