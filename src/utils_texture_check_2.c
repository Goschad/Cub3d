/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_texture_check_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 05:59:28 by mbouaza           #+#    #+#             */
/*   Updated: 2023/07/12 22:32:50 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// verif_direction2 //

static int	verif_direction2(t_check *check)
{
	if (!(check->no == 1 && check->so == 1 && check->we == 1 && check->ea == 1
			&& check->other == 0))
		return (ft_error("niet"), 1);
	return (0);
}

// verif_direction //

static void	verif_direction(char **line, t_check *check)
{
	char	*space;

	space = line[0];
	if (ft_strcmp(space, "NO") == 0)
		check->no++;
	else if (ft_strcmp(space, "SO") == 0)
		check->so++;
	else if (ft_strcmp(space, "WE") == 0)
		check->we++;
	else if (ft_strcmp(space, "EA") == 0)
		check->ea++;
	else
		check->other++;
}

// nbr_empty_line //

int	nbr_empty_line(char **map)
{
	int	i;
	int	k;
	int	empty;
	int	nn_empty;

	i = -1;
	empty = 0;
	nn_empty = 0;
	while (map[++i])
	{
		k = 0;
		while (map[i][k] != '\0')
		{
			if (map[i][k] != ' ' && map[i][k] != '\t' && map[i][k] != '\n')
			{
				nn_empty = 1;
				break ;
			}
			k++;
		}
		if (nn_empty == 0)
			empty++;
		nn_empty = 0;
	}
	return (empty);
}

// check_direction //

static int	check_direction(char **map, t_check *check)
{
	int		i;
	char	**spliit;

	i = 0;
	while (map[i])
	{
		if (map[i][0] == 'S' || map[i][0] == 'N'
				|| map[i][0] == 'W' || map[i][0] == 'E')
		{
			spliit = ft_split(map[i], ' ');
			verif_direction(spliit, check);
			freel(spliit, ft_strrlen(spliit));
		}
		i++;
	}
	if (verif_direction2(check))
		return (1);
	else
		return (0);
}

// check_texture //

int	check_texture(t_cube *cube)
{
	t_check	*check;
	char	**map;
	int		res;
	char	**map2;

	map2 = ft_strrdup(cube->all_map);
	map = remove_empty_line(map2);
	free_tab(map2);
	check = malloc(sizeof(t_check));
	init_check(check);
	check_slash(map, check);
	if (verif_color(map) == 0)
		return (freel(map, ft_strrlen(map)), free(check), 1);
	res = check_direction(map, check);
	return (freel(map, ft_strrlen(map)), free(check), res);
}
