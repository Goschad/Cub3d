/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:27:51 by mbouaza           #+#    #+#             */
/*   Updated: 2023/06/28 05:15:52 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// draw_part_2 //

static void	draw_part_2(t_cube *cub)
{
	while (++cub->ray->z < cub->ray->w / cub->ray->ray_nb)
	{
		cub->ray->xy[0] = 0;
		cub->ray->xy[1] = cub->ray->line_o;
		draw_color(cub->background, cub->ray->xy, cub->ray->r * cub->ray->w
			/ cub->ray->ray_nb + cub->ray->z, cub->t->ce);
		if (cub->ray->line_o + cub->ray->line_h - 1 > WINH)
			cub->ray->line_h = WINH - cub->ray->line_o;
		cub->ray->xy[0] = cub->ray->line_h + cub->ray->line_o - 1;
		cub->ray->xy[1] = cub->ray->h + 200 - 1;
		draw_color(cub->background, cub->ray->xy,
			cub->ray->r * cub->ray->w / cub->ray->ray_nb + cub->ray->z,
			cub->t->fl);
	}
}

// distance //

// return the distance between two coordinate //

float	distance(float x, float y, float fx, float fy)
{
	return (sqrt((fx - x) * (fx - x) + (fy - y) * (fy - y)));
}

// fix_angle //

// change the value of rad if is less than 0 or superior than 2 PI //

void	fix_angle(float *ra)
{
	if (*ra < 0)
		*ra += 2 * PI;
	if (*ra > 2 * PI)
		*ra -= 2 * PI;
}

int	pixel_to_color(t_cube *cub, uint32_t x, uint32_t y)
{
	uint8_t		*pixel;
	uint32_t	color;

	if (!cub->ray->t)
		return (BLACK);
	if (x >= cub->ray->t->width || y >= cub->ray->t->height)
		return (BLACK);
	pixel = &cub->ray->t->pixels[(y * cub->ray->t->width + x)
		* cub->ray->t->bytes_per_pixel];
	color = (pixel[0] << 24) + (pixel[1] << 16) + (pixel[2] << 8) + pixel[3];
	return (color);
}

void	draw(t_cube *cub)
{
	cub->ray->y = 0;
	while (cub->ray->y < cub->ray->line_h)
	{
		cub->ray->c = pixel_to_color(cub, cub->ray->tx, cub->ray->ty);
		cub->ray->z = 0;
		while (cub->ray->z < cub->ray->w / cub->ray->ray_nb)
			mlx_put_pixel(cub->background,
				cub->ray->r * cub->ray->w / cub->ray->ray_nb + cub->ray->z++,
				cub->ray->line_o + cub->ray->y, cub->ray->c);
		cub->ray->ty += cub->ray->ty_step;
		cub->ray->y++;
	}
	cub->ray->z = -1;
	draw_part_2(cub);
}
