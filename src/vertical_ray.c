/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: GIGI <GIGI@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:43:13 by mbouaza           #+#    #+#             */
/*   Updated: 2023/06/28 04:26:55 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// vertical_part_2 //

// ray hit vertical wall second part //

static void	vertical_part_2(t_cube *cub)
{
	t_ray	*n;

	n = cub->ray;
	while (n->dof < DOF)
	{
		n->mx = (int)(n->rx) / cub->map_s_x;
		n->my = (int)(n->ry) / cub->map_s_x;
		if (n->mx + n->my * cub->map_s_x > 0 && n->mx < cub->map_s_x
			&& n->my < cub->map_s_y
			&& cub->map[n->my][n->mx] > '0' && cub->map[n->my][n->mx] < '3')
		{
			n->vmt = cub->map[n->my][n->mx] - 49;
			n->vx = n->rx;
			n->vy = n->ry;
			n->dis_v = distance(n->px, n->py, n->vx, n->vy);
			n->dof = DOF;
		}
		else
		{
			n->rx += n->xo;
			n->ry += n->yo;
			n->dis_v = 1000000;
			n->dof++;
		}
	}
}

// vertical //

// ray hit vertical wall first part //

void	vertical(t_cube *cub)
{
	t_ray	*n;

	((void)0, n = cub->ray, n->dof = 0, n->vx = n->px, n->vy = n->py);
	n->ntan = -tan(n->ra);
	if (n->ra > P2 && n->ra < P3)
	{
		n->rx = (((int)n->px / cub->map_s_x) * cub->map_s_x) - 0.0001;
		n->ry = (n->px - n->rx) * n->ntan + n->py;
		n->xo = -cub->map_s_x;
		n->yo = -n->xo * n->ntan;
	}
	else if (n->ra < P2 || n->ra > P3)
	{
		n->rx = (((int)n->px / cub->map_s_x) * cub->map_s_x) + cub->map_s_x;
		n->ry = (n->px - n->rx) * n->ntan + n->py;
		n->xo = cub->map_s_x;
		n->yo = -n->xo * n->ntan;
	}
	else
	{
		n->ry = n->py;
		n->rx = n->px;
		n->dof = DOF;
	}
	vertical_part_2(cub);
}
