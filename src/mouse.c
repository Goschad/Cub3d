/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 06:58:36 by mbouaza           #+#    #+#             */
/*   Updated: 2023/07/03 04:44:52 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	mouse_control(t_cube *cub)
{
	mlx_get_mouse_pos(cub->mlx, &(cub->mouse_x), &(cub->mouse_y));
	if (cub->mouse_x < WINW / 2)
	{
		cub->pa -= 0.05;
		if (cub->pa < 0)
			cub->pa += 2 * PI;
	}
	else if (cub->mouse_x > WINW / 2)
	{
		cub->pa += 0.05;
		if (cub->pa > 2 * PI)
			cub->pa -= 2 * PI;
	}
	if (cub->mouse_x != WINW / 2 || cub->mouse_y != WINH / 2)
	{
		cub->ray->pdx = cosf(cub->pa) * 5;
		cub->ray->pdy = sinf(cub->pa) * 5;
		cub->ray->pdxs = cosf(cub->pa + P2) * 2;
		cub->ray->pdys = sinf(cub->pa + P2) * 2;
		mlx_set_mouse_pos(cub->mlx, WINW / 2, WINH / 2);
		cub->mouse_x = WINW / 2;
		cub->mouse_y = WINH / 2;
	}
}
