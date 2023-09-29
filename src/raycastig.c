/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:31:15 by mbouaza           #+#    #+#             */
/*   Updated: 2023/06/28 05:46:53 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// magic_maths //

static void	magic_maths(t_cube *cub)
{
	if (cub->ray->line_h > cub->ray->h)
	{
		cub->ray->ty_off = (cub->ray->line_h - cub->ray->h) / 2.0;
		cub->ray->line_h = cub->ray->h;
	}
	cub->ray->line_o = (cub->ray->h / 2 - cub->ray->line_h / 2);
	cub->ray->ty = cub->ray->ty_step * cub->ray->ty_off;
	if (cub->ray->shade != 1)
	{
		cub->ray->tx = (int)(cub->ray->rx / (cub->map_s_x / cub->ray->t_width))
			% (int)cub->ray->t_width;
		if (cub->ray->ra < PI)
			cub->ray->tx = cub->ray->t_width - 1 - cub->ray->tx;
	}
	else
	{
		cub->ray->tx = (int)(cub->ray->ry / (cub->map_s_x / cub->ray->t_width))
			% (int)cub->ray->t_height;
		if (cub->ray->ra > P2 && cub->ray->ra < P3)
			cub->ray->tx = cub->ray->t_width - 1 - cub->ray->tx;
	}
}

// setup //

static void	setup(t_cube *cub)
{
	cub->ray->ca = cub->ray->pa - cub->ray->ra;
	cub->ray->dist = cub->ray->dist * cosf(cub->ray->ca);
	fix_angle(&cub->ray->ca);
	cub->ray->line_h = (cub->map_s_x * cub->ray->h) / cub->ray->dist;
	cub->ray->t_width = cub->ray->t->width;
	cub->ray->t_height = cub->ray->t->height;
	cub->ray->ty_step = cub->ray->t_height / (float)cub->ray->line_h;
	cub->ray->ty_off = 0;
}

// short_things //

static void	short_things(t_cube *cub)
{
	cub->ray->hmt = cub->ray->vmt;
	cub->ray->rx = cub->ray->vx;
	cub->ray->ry = cub->ray->vy;
	cub->ray->dist = cub->ray->dis_v;
	if (cub->ray->hmt == 1)
		cub->ray->t = cub->t->text_do;
	else if (cub->ray->ra > P2 && cub->ray->ra < P3)
		cub->ray->t = cub->t->text_we;
	else
		cub->ray->t = cub->t->text_ea;
}

// orientation //

static void	orientation(t_cube *cub)
{
	cub->ray->shade = 1;
	if (cub->ray->dis_v < cub->ray->dis_h)
		short_things(cub);
	else if (cub->ray->dis_v >= cub->ray->dis_h)
	{
		cub->ray->shade = 0.5;
		cub->ray->rx = cub->ray->hx;
		cub->ray->ry = cub->ray->hy;
		cub->ray->dist = cub->ray->dis_h;
		if (cub->ray->hmt == 1)
			cub->ray->t = cub->t->text_do;
		else if (cub->ray->ra > PI)
			cub->ray->t = cub->t->text_no;
		else
			cub->ray->t = cub->t->text_so;
	}
	else
		cub->ray->t = cub->t->text_no;
}

// raycaster //

// make the mathe-magic to make "3D" in my map thanks to ray //

void	raycaster(t_cube *cub)
{
	cub->ray->w = WINW;
	cub->ray->h = WINH;
	cub->ray->px = cub->px + cub->p_size / 2;
	cub->ray->py = cub->py + cub->p_size / 2;
	cub->ray->ra = cub->pa - DR * 30;
	cub->ray->pa = cub->pa;
	fix_angle(&(cub->ray->ra));
	cub->ray->ray_nb = 512;
	cub->ray->r = 0;
	while (cub->ray->r < cub->ray->ray_nb)
	{
		cub->ray->hmt = 0;
		cub->ray->vmt = 0;
		horizontal(cub);
		vertical(cub);
		orientation(cub);
		setup(cub);
		magic_maths(cub);
		draw(cub);
		cub->ray->ra += DR * (60 / cub->ray->ray_nb);
		fix_angle(&(cub->ray->ra));
		cub->ray->r++;
	}
}
