/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rode-lim <rode-lim@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:43:43 by rode-lim          #+#    #+#             */
/*   Updated: 2024/04/17 11:43:43 by rode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	data_start(t_game *game)
{
	game->player.x = 0;
	game->player.y = 0;
	game->player.move = 0;
	game->player.collect = 0;
	game->coincheck = 0;
	game->playercheck = 0;
	game->exitcheck = 0;
	game->error = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	ft_window_size(&game, argv);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.size_x, game.size_y, "so_long");
	data_start(&game);
	map_line(&game, argv);
	initialize_game(&game, width, height);
}
