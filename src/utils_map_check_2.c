/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_check_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 10:32:58 by mbouaza           #+#    #+#             */
/*   Updated: 2023/07/03 12:11:44 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// replace_door //

void	replace_door(char **map, char c, char r)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == c)
				map[j][i] = r;
			i++;
		}
		j++;
	}
}

// vrf_map2 //

static void	vrf_map2(int *k, int *i, t_size *size)
{
	if (size->map[*i][size->newj] == 'x'
			&& (size->map[*i][size->newj + 1] == '#'
			|| size->map[*i][size->newj - 1] == '#'
			|| size->map[*i - 1][size->newj] == '#'
			|| size->map[*i + 1][size->newj] == '#'))
		size->map[*i][size->newj] = 'G';
	--*k;
}

// verif_finish_map //

int	verif_finish_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// vrf_map //i

// return le j //

void	vrf_map(int *k, int *i, t_size *size, int nb)
{
	if (nb == 1)
	{
		if (size->map[*i][size->newj + 1] == '0')
			size->newj++;
		else if (size->map[*i][size->newj - 1] == '0')
			size->newj--;
		else if ((*i + 1 <= size->height)
			&& size->map[*i + 1][size->newj] == '0')
			++*i;
		else if ((*i - 1 >= 0) && size->map[*i - 1][size->newj] == '0')
			--*i;
		size->map[*i][size->newj] = 'x';
		++*k;
	}
	else
		vrf_map2(k, i, size);
}

// init_deep_algo //

void	init_deep_algo(t_size *size, t_cube *cube,
	t_coordinate *coordinate, int nb)
{
	char	**mapp;
	char	**mapp2;

	if (nb == 0)
	{
		mapp = ft_strrdup(cube->mmap);
		replace_door(mapp, '2', '0');
		search_begin(mapp, coordinate, size->letter);
		find_map_dimensions(mapp, size);
		size->tab_x = malloc(sizeof(int) * (pow(size->height, 3)));
		size->tab_y = malloc(sizeof(int) * (pow(size->width, 3)));
		replace(mapp, size);
		mapp2 = contour(mapp, size);
		size->map = ft_strrdup(mapp2);
		freel(mapp2, size->height);
		freel(mapp, (size->height - 2));
	}
}
