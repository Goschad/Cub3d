/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:38:45 by mbouaza           #+#    #+#             */
/*   Updated: 2023/06/27 19:28:18 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// start_angle //

// assigne the first direction thanks to the player letter //

static void	start_angle(t_cube *cub, char c)
{
	if (c == 'N')
		cub->pa = P3;
	if (c == 'S')
		cub->pa = P2;
	if (c == 'E')
		cub->pa = 0;
	if (c == 'W')
		cub->pa = PI;
}

// is_player //

// check if my player is the right letter //

static int	is_player(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (1);
	return (0);
}

// get_position //

// setup the position, the first direction of my character //

int	get_position(t_cube *cub)
{
	int	i;
	int	j;

	i = 0;
	cub->px = -1;
	cub->py = -1;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (is_player(cub->map[i][j]))
			{
				start_angle(cub, cub->map[i][j]);
				cub->px = j;
				cub->py = i;
			}
			j++;
		}
		i++;
	}
	if (cub->px == -1 || cub->py == -1)
		return (1);
	return (0);
}
