/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rode-lim <rode-lim@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:51:47 by rode-lim          #+#    #+#             */
/*   Updated: 2024/04/18 10:51:47 by rode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_put_image(t_game *game, t_image image, int x, int y)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, image, &x, &y);
	if (!img)
	{
		ft_printf("Error\n");
		exit(1);
	}
	return (img);	
}