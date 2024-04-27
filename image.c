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