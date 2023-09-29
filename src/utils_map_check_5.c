/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_check_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 21:39:22 by mbouaza           #+#    #+#             */
/*   Updated: 2023/07/03 11:54:13 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// max_nb //

int	max_nb(t_size *size)
{
	int	max;

	max = (size->height * size->height * size->height);
	return (max);
}

// deep_algo //

int	deep_algo(t_cube *cube, t_size *size, t_coordinate *coordinate, int nb)
{
	int	i;
	int	j;
	int	k;

	init_deep(&k, &i, &j);
	init_deep_algo(size, cube, coordinate, nb);
	init_deep_algo2(coordinate, &i, &j, size);
	size->cmp = max_nb(size);
	while (size->cmp--)
	{
		deep_algo2(&i, &j, &k, size);
		if (k < 0)
			break ;
		size->tab_x[k] = i;
		size->tab_y[k] = j;
	}
	return (continue_deep(size, cube, coordinate));
}

// copy_first //

char	*copy_first(char *line)
{
	int		i;
	int		k;
	char	*result;

	i = 0;
	k = 0;
	result = malloc(sizeof(int) * 4);
	if (line[i] == 'F' || line[i] == 'C')
		i++;
	while (line[i] != ',')
	{
		result[k] = line[i];
		k++;
		i++;
	}
	result[k] = '\0';
	return (result);
}

// init_deep_algo2 //

void	init_deep_algo2(t_coordinate *coordinate, int *i, int *j, t_size *size)
{
	search_begin(size->map, coordinate, size->letter);
	*i = coordinate->x;
	*j = coordinate->y;
	size->tab_x[0] = *i;
	size->tab_y[0] = *j;
}
