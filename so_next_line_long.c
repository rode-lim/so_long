/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_next_line_long.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rode-lim <rode-lim@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:16:52 by rode-lim          #+#    #+#             */
/*   Updated: 2024/04/23 14:16:52 by rode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_line(int	fd)
{
	char	buffer;
	int		lenght;
	int		bytes;

	lenght = 0;
	buffer = 0;
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, &buffer, 1);
		if (buffer != '\n')
			lenght++;
		else
			break ;
	}
	return (lenght);		
}

int	ft_count_line(int	fd)
{
	int		linecount;
	char	buffer;
	int		bytes;

	linecount = 1;
	buffer = 0;
	while (1)
	{
		bytes = read(fd, &buffer, 1);
		if (bytes < 1)
			break ;
		if (buffer == '\n')
			linecount++;
	}
	if (buffer == '1')
		linecount++;
	return (linecount);
}

void	extra_free(char *line)
{
	free(line);
	line = NULL;
}

char *get_next_line(int fd)
{
	char	buffer;
	char	*line;
	int		readbytes;
	int		i;

	readbytes = 1;
	i = 0;
	line = (char *)malloc(ft_line(fd) + 1);
	buffer = 0;
	if (fd < 0)
		return (NULL);
	while (readbytes > 0)
	{
		readbytes = read(fd, &buffer, 1);
		if (readbytes <= 0)
			break ;
		line[i++] = buffer;
		if (buffer == '\n')
			break ;
	}
	line[i] = '\0';
	if (!*line)
		extra_free(line);
	return (line);
}