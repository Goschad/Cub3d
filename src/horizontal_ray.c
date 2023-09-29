/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: GIGI <GIGI@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:43:21 by mbouaza           #+#    #+#             */
/*   Updated: 2023/06/28 05:27:34 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// horizontal_part_2 //

// ray hit horizontal wall second part //

static void	horizontal_part_2(t_cube *cub)
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
			n->hmt = cub->map[n->my][n->mx] - 49;
			n->hx = n->rx;
			n->hy = n->ry;
			n->dis_h = distance(n->px, n->py, n->hx, n->hy);
			n->dof = DOF;
		}
		else
		{
			n->rx += n->xo;
			n->ry += n->yo;
			n->dis_h = 1000000;
			n->dof++;
		}
	}
}

// horizontal //

// ray hit horizontal wall first part //

void	horizontal(t_cube *cub)
{
	t_ray	*n;

	((void)0, n = cub->ray, n->dof = 0, n->hx = n->px);
	((void)0, n->hy = n->py, n->a_tan = -1 / tan(n->ra));
	if (n->ra > PI)
	{
		n->ry = (((int)n->py / cub->map_s_x) * cub->map_s_x) - 0.0001;
		n->rx = (n->py - n->ry) * n->a_tan + n->px;
		n->yo = -cub->map_s_x;
		n->xo = -n->yo * n->a_tan;
	}
	else if (n->ra < PI)
	{
		n->ry = (((int)n->py / cub->map_s_x) * cub->map_s_x) + cub->map_s_x;
		n->rx = (n->py - n->ry) * n->a_tan + n->px;
		n->yo = cub->map_s_x;
		n->xo = -n->yo * n->a_tan;
	}
	else
	{
		n->ry = n->py;
		n->rx = n->px;
		n->dof = DOF;
	}
	horizontal_part_2(cub);
}
