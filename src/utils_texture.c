/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:57:09 by mbouaza           #+#    #+#             */
/*   Updated: 2023/07/13 13:58:10 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_squar(t_cube *cub, int w, int h, uint32_t color)
{
	int	x;
	int	y;

	x = w;
	while (x < w + cub->m_size)
	{
		y = h;
		while (y < h + cub->m_size)
		{
			if (y == h || y == (h + cub->m_size) || x == w
				|| x == (w + cub->m_size))
				mlx_put_pixel(cub->map_img, x, y, GREY);
			else
				mlx_put_pixel(cub->map_img, x, y, color);
			y++;
		}
		x++;
	}
}

// load_textures //

int	load_textures(t_textures *t)
{
	t->text_no = mlx_load_png(t->t_no);
	if (!t->text_no)
		return (1);
	t->text_so = mlx_load_png(t->t_so);
	if (!t->text_so)
		return (1);
	t->text_ea = mlx_load_png(t->t_ea);
	if (!t->text_ea)
		return (1);
	t->text_we = mlx_load_png(t->t_we);
	if (!t->text_we)
		return (1);
	t->text_do = mlx_load_png("./img_t/Door.png");
	if (!t->text_do)
		return (1);
	return (0);
}

// draw_2d_map //

// draw a mini-map //

void	draw_2d_map(t_cube *cub)
{
	int	i;
	int	j;

	cub->map_img = mlx_new_image(cub->mlx, cub->map_s_x * (cub->m_size + 1),
			cub->map_s_y * (cub->m_size + 1));
	i = 0;
	while (cub->mmap[i])
	{
		j = 0;
		while (cub->mmap[i][j])
		{
			if (cub->mmap[i][j] == '1')
				draw_squar(cub, j * cub->m_size, i * cub->m_size, WHI);
			else if (cub->mmap[i][j] == '0' || cub->mmap[i][j] == cub->p_letter)
				draw_squar(cub, j * cub->m_size, i * cub->m_size, BLACK);
			else if (cub->mmap[i][j] == '2' || cub->mmap[i][j] == '3')
				draw_squar(cub, j * cub->m_size, i * cub->m_size, RED);
			j++;
		}
		i++;
	}
	mlx_image_to_window(cub->mlx, cub->map_img, 0, 0);
	cub->map_img->instances[0].z = 1;
}

// background_color //

// init the color of C and F //

void	background_color(t_cube *cub)
{
	int		i;
	char	**line;
	char	**c;

	i = 0;
	line = NULL;
	c = NULL;
	while (i < begining_map(cub->all_map))
	{
		line = ft_split(cub->all_map[i], ' ');
		if (line[0][0] == 'C' || line[0][0] == 'F')
		{
			c = ft_split(line[1], ',');
			if (line[0][0] == 'C')
				cub->t->ce = pix_ft(f_toi(c[0]), f_toi(c[1]), f_toi(c[2]), 255);
			else if (line[0][0] == 'F')
				cub->t->fl = pix_ft(f_toi(c[0]), f_toi(c[1]), f_toi(c[2]), 255);
			free_tab(c);
		}
		free_tab(line);
		i++;
	}
}

// texture_orientation //

void	texture_orientation(t_cube *c, int n)
{
	int		j;
	char	**texture;

	j = 0;
	while (c->all_map[j])
	{
		texture = ft_split(c->all_map[j], ' ');
		if (texture[0][0] == 'N' && texture[0][1] == 'O' && n == 0)
			c->t->t_no = ft_strdup(texture[1]);
		else if (texture[0][0] == 'S' && texture[0][1] == 'O' && n == 1)
			c->t->t_so = ft_strdup(texture[1]);
		else if (texture[0][0] == 'W' && texture[0][1] == 'E' && n == 2)
			c->t->t_we = ft_strdup(texture[1]);
		else if (texture[0][0] == 'E' && texture[0][1] == 'A' && n == 3)
			c->t->t_ea = ft_strdup(texture[1]);
		free_tab(texture);
		j++;
	}
	if (n != 3)
		texture_orientation(c, n + 1);
	else
		delete_all_newline(c);
}
