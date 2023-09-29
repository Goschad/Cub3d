/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 02:47:05 by mbouaza           #+#    #+#             */
/*   Updated: 2023/07/13 14:24:14 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// check_file //

static int	check_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		close(fd);
		ft_error("file error\n");
		return (1);
	}
	close(fd);
	return (0);
}

// check_map //

static int	check_map(char **map)
{
	int	stat;
	int	y;
	int	x;

	y = -1;
	x = 0;
	stat = 0;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '0' || map[y][x] == '1' || map[y][x] == ' '
				|| map[y][x] == '\t' || map[y][x] == '2' || map[y][x] == '\n')
				;
			else if ((map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W'
				|| map[y][x] == 'E') && stat != 1)
				stat = 1;
			else
				return (1);
		}
	}
	if (stat == 1)
		return (0);
	return (1);
}

// check_args //

static int	check_args(char **all_map)
{
	int		y;
	int		i;
	char	**line;

	y = 0;
	i = 0;
	line = NULL;
	while (y < begining_map(all_map))
	{
		line = ft_split(all_map[y], ' ');
		if (ft_strrlen(line) != 2 && ft_strrlen(line) != 1)
			return (free_tab(line), 1);
		if (ft_strrlen(line) == 2)
			i++;
		free_tab(line);
		y++;
	}
	if (i == 6)
		return (0);
	return (1);
}

// free_short //

static void	free_short(t_coordinate *c, t_size *s)
{
	free_all_size(s);
	free(s);
	free(c);
}

int	check_all(t_cube *cub, char *file, t_size *size, t_coordinate *coordinate)
{
	size->status = 0;
	if (check_file(file))
		return (1);
	if (check_map(cub->mmap))
		return (ft_error("map error\n"), 1);
	if (check_args(cub->all_map))
		return (ft_error("check your args in the file .cub\n"), 1);
	if (check_texture(cub))
		return (ft_error("texture error\n"), 1);
	if (deep_algo(cub, size, coordinate, 0) == 1)
	{
		free_short(coordinate, size);
		return (ft_error("map error\n"), 1);
	}
	free_short(coordinate, size);
	if (delimited_size(cub->mmap))
		return (ft_error("map size error\n"), 1);
	return (0);
}
