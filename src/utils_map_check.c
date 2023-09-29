/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 10:25:07 by mbouaza           #+#    #+#             */
/*   Updated: 2023/07/03 12:01:58 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// search_begin //

void	search_begin(char **map, t_coordinate *coordinate, char c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				coordinate->x = i;
				coordinate->y = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

// find_map_dimensions //

void	find_map_dimensions(char **map, t_size *size)
{
	int	i;
	int	length;

	i = 0;
	size->height = 0;
	size->width = 0;
	while (map[i] != NULL)
	{
		length = ft_strlen(map[i]);
		if (length > size->width)
			size->width = length;
		i++;
	}
	size->height = i;
}

// init_contour //

void	init_contour(char ***new_map, t_size *size)
{
	int	i;

	size->height += 2;
	size->width += 1;
	i = 0;
	*new_map = malloc(sizeof(char *) * (size->height + 1));
	while (i < size->height)
	{
		(*new_map)[i] = malloc(sizeof(char) * (size->width + 1));
		i++;
	}
	size->k = 0;
	size->l = 0;
}

// char	**contour(char **map, t_size *size) ==

char	**contour(char **map, t_size *size)
{
	char	**new_map;

	size->i = 0;
	init_contour(&new_map, size);
	while (size->i < size->height)
	{
		size->j = 0;
		size->l = 0;
		while (size->j < size->width)
			contour_all(new_map, size, map);
		new_map[size->i][size->width] = '\0';
		if (size->i > 0)
			size->k++;
		size->i++;
	}
	new_map[size->height] = NULL;
	return (new_map);
}

// replace //

char	**replace(char **map, t_size *size)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	while (i < size->height)
	{
		j = 0;
		max = ft_strlen(map[i]);
		while (j < (max - 1))
		{
			if (!(map[i][j] && (map[i][j] == '0'
				|| map[i][j] == '1' || map[i][j] == size->letter)))
				map[i][j] = '#';
			j++;
		}
		i++;
	}
	return (map);
}
