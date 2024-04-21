/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapmasters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rode-lim <rode-lim@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:45:29 by rode-lim          #+#    #+#             */
/*   Updated: 2024/04/18 10:45:29 by rode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player(t_game *game, int i, int j)
{
    ft_put_image(game, game->player, j * 64, i * 64);
}

void	ft_exit(t_game *game, int i, int j)
{
    mlx_put_image_to_window(game->mlx, game->win, game->exit, j * 64, i * 64);
}

void	ft_collectible(t_game *game, int i, int j)
{
    mlx_put_image_to_window(game->mlx, game->win, game->collectible, j * 64, i * 64);
}

void	ft_walls(t_game *game, int i, int j)
{
    mlx_put_image_to_window(game->mlx, game->win, game->wall, j * 64, i * 64);
}