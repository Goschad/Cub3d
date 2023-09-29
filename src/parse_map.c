/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 02:24:47 by mbouaza           #+#    #+#             */
/*   Updated: 2023/07/13 14:17:01 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// map_size //

// return the size y of the .cub //

static int	map_size(char *path)
{
	int		fd;
	int		size;
	char	*line;

	size = 0;
	line = NULL;
	fd = open(path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		size++;
	}
	close(fd);
	return (size);
}

// add_newline //

static char	*add_newline(char **map, int size)
{
	char	*line;

	line = ft_strjoin2(map[size - 1], "\n");
	free(map[size - 1]);
	return (line);
}

// begining_map //

int	begining_map(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map && map[y])
	{
		x = 0;
		while (map && map[y][x])
		{
			if (map && (map[y][x] == ' ' || map[y][x] == '\t'
					|| map[y][x] == '\n'))
				x++;
			else if (map && (map[y][x] != '1' || map[y][x] == '2'))
				y++;
			else
				return (y);
			if (!map[y])
				return (y);
		}
		y++;
	}
	return (y);
}

// copy_map //

char	**copy_map(char *path)
{
	int		fd;
	int		size;
	char	*line;
	char	**map;

	size = map_size(path);
	fd = open(path, O_RDONLY);
	map = malloc(sizeof(char *) * (size + 1));
	size = 0;
	line = get_next_line(fd);
	if (!line)
		return (free(map), NULL);
	while (1)
	{
		map[size++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	line = add_newline(map, size);
	map[size - 1] = ft_strdup(line);
	map[size] = NULL;
	close(fd);
	return (free(line), map);
}

int	init_cub_file(t_cube *cub, char *path)
{
	cub->map = NULL;
	cub->mmap = NULL;
	cub->all_map = copy_map(path);
	if (cub->all_map == NULL)
		return (1);
	character_letter(cub, cub->all_map);
	cub->mmap = copy_true_map(cub->all_map);
	cub->map = hide_map(cub->mmap);
	return (0);
}
