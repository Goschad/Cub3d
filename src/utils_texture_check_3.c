/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_texture_check_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 10:04:24 by mbouaza           #+#    #+#             */
/*   Updated: 2023/07/13 14:23:21 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// all_is_num

static int	all_is_num(char *color)
{
	int	i;

	i = 0;
	while (color[i])
	{
		if ((color[i] >= '0' && color[i] <= '9')
			|| color[i] == 10 || color[i] == ' ' || color[i] == '\t')
			i++;
		else
			return (1);
	}
	return (0);
}

// remove_empty_line //

char	**remove_empty_line(char **map)
{
	char	**n_map;
	char	*m;
	int		i;
	int		k;

	i = 0;
	k = 0;
	n_map = malloc(sizeof(char *)
			* (ft_strrlen(map) - nbr_empty_line(map) + 1));
	while (map[i])
	{
		if (verif_empty(map[i]))
		{
			m = remove_space(map[i]);
			n_map[k] = ft_strdup(m);
			free(m);
			k++;
		}
		i++;
	}
	n_map[k] = NULL;
	return (n_map);
}

// chec_nbr //

static int	check_nbr(char **verif)
{
	int	i;
	int	j;

	i = 0;
	while (verif[i])
	{
		j = 0;
		while (verif[i][j])
		{
			if (verif[i][0] == 32 || verif[i][0] == '\t' || verif[i][0] == 10)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// check_color //

int	check_color(char *line)
{
	int		i;
	char	**verif;
	char	**revif;

	i = 0;
	revif = ft_split(line, ' ');
	verif = ft_split(revif[1], ',');
	freel(revif, ft_strrlen(revif));
	if (ft_strrlen(verif) != 3 || check_nbr(verif) == 0)
		return (freel(verif, ft_strrlen(verif)), 0);
	while (verif[i])
	{
		if (all_is_num(verif[i]))
			return (freel(verif, ft_strrlen(verif)), 0);
		if (f_toi(verif[i]) >= 0 && f_toi(verif[i]) <= 255)
			i++;
		else
			return (freel(verif, ft_strrlen(verif)), 0);
	}
	return (freel(verif, ft_strrlen(verif)), 1);
}

// verif_color //

int	verif_color(char **map)
{
	int	i;
	int	f;
	int	c;

	i = -1;
	f = 0;
	c = 0;
	while (map[++i] != NULL)
	{
		if (map[i][0] == 'F')
		{
			f++;
			if (check_color(map[i]) == 0)
				return (0);
		}
		if (map[i][0] == 'C')
		{
			c++;
			if (check_color(map[i]) == 0)
				return (0);
		}
	}
	if (!(f == 1 && c == 1))
		return (0);
	return (1);
}
