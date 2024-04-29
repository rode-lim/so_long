/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rode-lim <rode-lim@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:46:20 by rode-lim          #+#    #+#             */
/*   Updated: 2024/04/17 11:46:20 by rode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*------Libraries-------*/
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>

#include "/home/lima/minilibx_linux/mlx.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include "../ft_printf/ft_printf.h"

/*------Structures-------*/
typedef struct s_player
{
	int	x;
	int	y;
	int	move;
	int	collect;
}		t_player;

typedef struct s_texture
{
	void	*player;
	void	*exit;
	void	*collectible;
	void	*wall;
}			t_texture;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			*coinmap_x;
	int			*coinmap_y;
	int			coincheck;
	int			playercheck;
	int			exitcheck;
	int			error;
	size_t		size_x;
	int			size_y;
	t_texture	texture;
	t_player	player;
}				t_game;

typedef struct s_block
{
	char	*path;
	char	*name;
}			t_block;

typedef struct s_image
{
	struct s_game	wlx;
	char			*path;
	void			*img;
	int				width;
	int				height;
}					t_image;


/*------Function Prototypes-------*/
void	ft_window_size(t_game *data, char **argv);
void	ft_map(t_game *game, char **argv);
void	ft_player(t_game *game, int i, int j);
void	ft_exit(t_game *game, int i, int j);
void	ft_collectible(t_game *game, int i, int j);
void	map_master(t_game *game, int i, int j);
void	floor_make(t_game *game, int i);
void	create_maplenght(char *line, t_game *game, int i);
void	map_line(t_game *game, char **argv);
void	ft_put_image(t_game *game, t_image image, int x, int y);
void	data_start(t_game *game);
void	map_make(t_game *game, int i);
void	ft_error(char *str, t_game *game);
void	window_destroy(t_game *game);
void	ft_maperror(char *str, t_game *game);
void	destroy_map(t_game *game);
void	ft_walls(t_game *game, int i, int j);
void	*place_img(t_game *game, t_image img, int x, int y);
int		ft_count_line(int fd);
int		ft_line(int fd);
t_block	get_block(char name);

#endif