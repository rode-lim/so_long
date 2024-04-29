/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rode-lim <rode-lim@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:50:21 by rode-lim          #+#    #+#             */
/*   Updated: 2024/04/17 19:50:21 by rode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_make(t_game	*game, int i)
{
	int	j;
	t_image	img;
	t_block	map;

	img.wlx = *game;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			map = get_block(game->map[i][j]);
			img.path = map.path;
			place_img(game, img, (i * 64), (j * 64));
			j++;
		}
		i++;
	}
}

void	floor_make(t_game *game, int i)
{
	int	j;
	t_image	img;

	img.wlx = *game;
	j = 0;
	if (ft_strlen(game->map[i]) != game->size_x / 64
		&& i != (game->size_y / 64))
		ft_maperror("Wrong map format!\n", game);
	if (game->map[(game->size_y / 64)]
		&& game->map[(game->size_y / 64)][0] != '\0')
		ft_maperror("Wrong map!\n", game);
	while (game->map[i])
	{
		j = 0;
		while ((game->map[i][j]))
		{
			if (!ft_strchr("10PCE", game->map[i][j]))
				ft_error("Map doesn't meet the 10PCE criteria!\n", game);
			img.path = "./images/floor.xpm";
			place_img(game, img, (i * 64), (j * 64));
			j++;
		}
		i++;
	}
}

void	create_maplenght(char *line, t_game *game, int i)
{
	int	j;

	j = 0;
	game->map[i] = (char *)malloc(sizeof(char) * game->size_x + 1);
	if (!game->map[i])
	{
		ft_printf("Error\n");
		exit(1);
	}
	while (line[j] > 32)
	{
		if (line[j] == '\n')
			break;
		game->map[i][j] = line[j];
		j++;
	}
	game->map[i][j] = '\0';
	free(line);
	floor_make(game, i);
	map_make(game, i);
}

void	map_line(t_game *game, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	game->map = (char **)malloc(sizeof(char **) * game->size_y);
	if (!game->map)
	{
		ft_printf("Error\n");
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	while (i < game->size_y)
		game->map[i++] = NULL;
	i = 0;
	while (i < game->size_y / 64)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		create_maplenght(line, game, i);
		i++;
	}
	close(fd);
	if (game->error > 0)
		window_destroy(game);
}
