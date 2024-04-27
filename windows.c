/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rode-lim <rode-lim@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:00:09 by rode-lim          #+#    #+#             */
/*   Updated: 2024/04/17 12:00:09 by rode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_window_size(t_game *data, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	data->size_x = (ft_line(fd) * 64);
	data->size_y = (ft_count_line(fd) * 64);
	if (data->size_x == 0 || data->size_y == 0)
	{
		ft_printf("Empty map!\n");
		exit(1);
	}
}

