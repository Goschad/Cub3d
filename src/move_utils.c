/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:22:29 by mbouaza           #+#    #+#             */
/*   Updated: 2023/07/03 04:02:11 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// modife for 2 //

static void	move_x(t_cube *cub, float dx)
{
	int		i;
	float	nb;

	i = 0;
	nb = 0;
	nb = cub->px + dx * cub->speed + 5 * (dx > 0);
	if (cub->map[(int)cub->py / cub->map_s_x][(int)nb / cub->map_s_x] == '1'
		|| cub->map[(int)cub->py / cub->map_s_x][(int)nb / cub->map_s_x] == '2')
		return ;
	cub->px += dx * cub->speed;
}

static void	move_y(t_cube *cub, float dy)
{
	int		i;
	float	nb;

	i = 0;
	nb = 0;
	nb = cub->py + dy * cub->speed + 5 * (dy > 0);
	if (cub->map[(int)nb / cub->map_s_x][(int)cub->px / cub->map_s_x] == '1'
		|| cub->map[(int)nb / cub->map_s_x][(int)cub->px / cub->map_s_x] == '2')
		return ;
	cub->py += dy * cub->speed;
}

// all_move //

// make all possible move //

void	all_move(t_cube *cub)
{
	if (cub->keys.key_w != 0)
	{
		move_x(cub, cub->ray->pdx);
		move_y(cub, cub->ray->pdy);
	}
	if (cub->keys.key_s != 0)
	{
		move_x(cub, -cub->ray->pdx);
		move_y(cub, -cub->ray->pdy);
	}
	if (cub->keys.key_d != 0)
	{
		move_x(cub, cub->ray->pdxs);
		move_y(cub, cub->ray->pdys);
	}
	if (cub->keys.key_a != 0)
	{
		move_x(cub, -cub->ray->pdxs);
		move_y(cub, -cub->ray->pdys);
	}
}

// all_rotate //

// can turn in left or right //

void	all_rotate(t_cube *cub)
{
	if (cub->keys.key_l != 0)
	{
		cub->pa -= 0.05;
		if (cub->pa < 0)
			cub->pa += 2 * PI;
		cub->ray->pdx = cosf(cub->pa) * 5;
		cub->ray->pdy = sinf(cub->pa) * 5;
		cub->ray->pdxs = cosf(cub->pa + P2) * 2;
		cub->ray->pdys = sinf(cub->pa + P2) * 2;
	}
	if (cub->keys.key_r != 0)
	{
		cub->pa += 0.05;
		if (cub->pa > 2 * PI)
			cub->pa -= 2 * PI;
		cub->ray->pdx = cosf(cub->pa) * 5;
		cub->ray->pdy = sinf(cub->pa) * 5;
		cub->ray->pdxs = cosf(cub->pa + P2) * 2;
		cub->ray->pdys = sinf(cub->pa + P2) * 2;
	}
}
