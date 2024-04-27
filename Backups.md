```
void	window_destroy(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->size_y)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	exit(1);
}
```
### Old Window_Destroy function