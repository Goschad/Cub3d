/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_check_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 21:28:55 by mbouaza           #+#    #+#             */
/*   Updated: 2023/07/03 12:12:13 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	gabin_phenix(char **map, int x, int y, char c)
{
	static int	s_x;
	static int	s_y;
	static int	status = 0;

	s_y = ft_strrlen(map);
	if (y < 0 || y >= s_y || x < 0)
		return (status);
	s_x = len_str(map[y]);
	if (x >= s_x || map[y][x] == c)
		return (0);
	if (map[y][x] == 'x' || map[y][x] == ' ')
		status = 1;
	map[y][x] = c;
	gabin_phenix(map, x + 1, y, c);
	gabin_phenix(map, x, y + 1, c);
	gabin_phenix(map, x, y - 1, c);
	gabin_phenix(map, x - 1, y, c);
	return (status);
}

// continue_deep2 //

static int	continue_deep2(t_cube *cube, t_size *size,
	t_coordinate *coordinate, int zero)
{
	if (zero == 1)
		return (deep_algo(cube, size, coordinate, 1));
	else
	{
		if (search_g(size->map) == 1)
			return (1);
	}
	size->status = gabin_phenix(size->map, 0, 0, '1');
	if (size->status == 1)
		return (1);
	return (0);
}

// delete_n //

void	delete_n(t_size *size)
{
	int	i;
	int	j;

	i = 0;
	while (size->map[i])
	{
		j = 0;
		while (size->map[i][j])
		{
			if (size->map[i][j] == size->letter)
			{
				if (size->map[i][j + 1] == '#' || size->map[i][j - 1] == '#'
					|| size->map[i - 1][j] == '#'
						|| size->map[i + 1][j] == '#' )
					size->map[i][j] = 'G';
				else
					size->map[i][j] = '1';
			}
			j++;
		}
		i++;
	}
}

// continue_deep //

int	continue_deep(t_size *size, t_cube *cube, t_coordinate *coordinate)
{
	int	i;
	int	j;
	int	zero;

	delete_n(size);
	i = 0;
	zero = 0;
	while (size->map[i] && zero == 0)
	{
		j = 0;
		while (size->map[i][j])
		{
			if (size->map[i][j] == '0')
			{
				size->map[i][j] = size->letter;
				zero = 1;
				break ;
			}
			j++;
		}
		i++;
	}
	return (continue_deep2(cube, size, coordinate, zero));
}

// len_str //

int	len_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
