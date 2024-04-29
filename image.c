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

void	*place_img(t_game *game, t_image img, int x, int y)
{
	img.img = mlx_xpm_file_to_image(img.wlx.mlx, img.path, &img.width, &img.height);
	if (!img.img)
		ft_error("Xpm file wrong or missing.\n", game);
	mlx_put_image_to_window(img.wlx.mlx, img.wlx.win, img.img, x, y);
	mlx_destroy_image(img.wlx.mlx, img.img);
	return (img.img);
}

t_block	get_block(char name)
{
	t_block	map[6];
	int	i;

	map[0] = (t_block){"0", "images/floor.xpm"};
	map[1] = (t_block){"1", "images/wall.xpm"};
	map[2] = (t_block){"P", "images/player.xpm"};
	map[3] = (t_block){"C", "images/collectible.xpm"};
	map[4] = (t_block){"E", "images/exit.xpm"};
	map[5] = (t_block){NULL, NULL};
	i = 0;
	while (map[i].name != NULL)
	{
		if (map[i].name[0] == name)
		{
			return (map[i]);
			break;
		}
		i++;
	}
	return (map[5]);
}