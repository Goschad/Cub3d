/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 04:11:26 by mbouaza           #+#    #+#             */
/*   Updated: 2023/06/28 05:11:10 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static mlx_image_t	*make_player(mlx_t *mlx, int w, int h, uint32_t color)
{
	mlx_image_t	*image;
	int			x;
	int			y;

	x = 0;
	image = mlx_new_image(mlx, w, h);
	while (x < (int)image->width)
	{
		y = 0;
		while (y < (int) image->height)
		{
			mlx_put_pixel(image, x, y, color);
			y++;
		}
		x++;
	}
	return (image);
}

// render_player //

void	render_player(t_cube *cub)
{
	cub->player_img->instances[0].x = cub->px * cub->m_size / cub->map_s_x;
	cub->player_img->instances[0].y = cub->py * cub->m_size / cub->map_s_x;
	cub->ray->pxx = cub->ray->pdx * 5 + cub->px;
	cub->ray->pyy = cub->ray->pdy * 5 + cub->py;
}

// init_player //

void	init_player(t_cube *cub)
{
	cub->px = cub->px * cub->map_s_x + cub->map_s_x * 3 / 8;
	cub->py = cub->py * cub->map_s_x + cub->map_s_x * 3 / 8;
	cub->ray->pdx = cosf(cub->pa) * 5;
	cub->ray->pdy = sinf(cub->pa) * 5;
	cub->ray->pdxs = cosf(cub->pa + P2) * 5;
	cub->ray->pdys = sinf(cub->pa + P2) * 5;
	cub->ray->pxx = cub->ray->pdx * 5 + cub->px;
	cub->ray->pyy = cub->ray->pdy * 5 + cub->py;
	if (cub->p_size < 2)
		cub->p_size = 2;
	cub->player_img = make_player(cub->mlx, cub->p_size,
			cub->p_size, cub->p_color);
	mlx_image_to_window(cub->mlx, cub->player_img, cub->px, cub->py);
	cub->player_img->instances[0].z = 2;
}

// draw_color //

// put a pixel with color of the img //

void	draw_color(mlx_image_t *img, int xy[2], int x, int color)
{
	int	i;

	i = xy[0] - 1;
	while (++i <= xy[1])
		mlx_put_pixel(img, x, i, color);
}
