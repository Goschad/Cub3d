/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:02:03 by mbouaza           #+#    #+#             */
/*   Updated: 2023/07/03 12:39:57 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// find_one //

static int	find_one(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			return (1);
		i++;
	}
	return (0);
}

static int	skip_first_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\f' || str[i] == '\v')
		i++;
	return (i);
}

// delimited_size //

int	delimited_size(char **map)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (map[j])
	{
		if (find_one(map[j]))
		{
			i = ft_strlen(map[j]);
			while (i > 0 && map[j][i] != '1')
				i--;
			if (i - skip_first_space(map[j]) > W || j > H)
				return (1);
			j++;
		}
		else
		{
			if (j > H)
				return (1);
			return (0);
		}
	}
	return (0);
}

// check_cub //

int	check_cub(char *f)
{
	int	i;

	i = ft_strlen(f) - 1;
	if (f[i - 3] == '.' && f[i - 2] == 'c' && f[i - 1] == 'u' && f[i] == 'b')
		return (0);
	ft_error("the file isn't a .cub\n");
	exit(1);
}

// search_g //

int	search_g(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'G')
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
