/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:16:35 by GIGI              #+#    #+#             */
/*   Updated: 2023/07/13 16:28:00 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	auto_close_door(t_cube *cub)
{
	int	px;
	int	py;

	px = 0;
	py = 0;
	if (cub->door == true)
	{
		px = cos(cub->pa) * 15 + cub->px;
		py = sin(cub->pa) * 15 + cub->py;
		if (cub->map[py / cub->map_s_x][px / cub->map_s_x]
		&& cub->map[py / cub->map_s_x][px / cub->map_s_x] != '3'
		&& cub->map[(int)cub->py / cub->map_s_x][(int)cub->px / cub->map_s_x]
		== '0')
		{
			replace_door(cub->map, '3', '2');
			cub->door = false;
		}
	}
}

void	open_door(t_cube *cub)
{
	int	px;
	int	py;

	px = cos(cub->pa) * 6 + cub->px;
	py = sin(cub->pa) * 6 + cub->py;
	if (cub->map[py / cub->map_s_x][px / cub->map_s_x]
		&& cub->map[py / cub->map_s_x][px / cub->map_s_x] == '2'
		&& (cub->map[(int)cub->py / cub->map_s_x][(int)cub->px / cub->map_s_x]
		== '0' || cub->map[(int)cub->py / cub->map_s_x]
			[(int)cub->px / cub->map_s_x] == '3'))
	{
		cub->map[py / cub->map_s_x][px / cub->map_s_x] = '3';
		cub->door = true;
	}
}

// free_all_size //

void	free_all_size(t_size *size)
{
	free(size->tab_x);
	free(size->tab_y);
	freel(size->map, size->height);
}
