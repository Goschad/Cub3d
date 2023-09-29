/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 02:02:59 by mbouaza           #+#    #+#             */
/*   Updated: 2023/07/13 14:22:00 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// null_init_texture_struct //

static void	null_init_texture_struct(t_cube *cube)
{
	cube->t = malloc(sizeof(t_textures));
	cube->t->t_no = NULL;
	cube->t->t_so = NULL;
	cube->t->t_we = NULL;
	cube->t->t_ea = NULL;
	cube->t->text_do = NULL;
	cube->t->text_no = NULL;
	cube->t->text_so = NULL;
	cube->t->text_we = NULL;
	cube->t->text_ea = NULL;
	cube->weapon_img = NULL;
	cube->p_color = RED;
	cube->door = false;
	cube->t->fl = 0;
	cube->emote = 0;
	cube->weapon = 0;
	cube->t->ce = 0;
	cube->map_s_x = 0;
	cube->map_s_y = 0;
	cube->speed = SPEED;
	cube->mlx = NULL;
	cube->mouse_x = WINW / 2;
	cube->mouse_y = WINH / 2;
}

// check_letter //

int	check_letter(char *line)
{
	int	i;
	int	no;

	i = 0;
	no = 0;
	while (line[i])
	{
		if (line[i] >= '1' && (line[i] <= '9' || line[i] == 'F'
				|| line[i] == 'C' || line[i] == ',' || line[i] == '\n'))
		{
			if (line[i] == 'F' || line[i] == 'C')
				no++;
			i++;
		}
		else
			return (0);
	}
	if (no > 1)
		return (0);
	return (1);
}

// short_cut_cut //

static void	short_cut_cut(t_cube *cube, t_size *size, t_coordinate *c)
{
	if (cube->map_s_y == 0 || cube->map_s_x == 0 || cube->all_map == NULL)
	{
		if (cube->map != NULL)
			free_all_size(size);
		free(c);
		return (ft_error("empty map\n"), free(size), quit_program(cube));
	}
	cube->m_size = 256 / cube->map_s_x;
	cube->p_size = cube->m_size / 4;
	size->letter = cube->p_letter;
}

// init_all //

void	init_all(t_cube *cube, char **argv, t_size *size,
	t_coordinate *coordinate)
{	
	null_init_texture_struct(cube);
	init_cub_file(cube, argv[1]);
	cube->map_s_y = ft_strrlen(cube->map);
	if (cube->map != NULL)
		cube->map_s_x = ft_strlen(cube->map[0]);
	short_cut_cut(cube, size, coordinate);
	if (check_all(cube, argv[1], size, coordinate))
		return (quit_program(cube));
	background_color(cube);
	texture_orientation(cube, 0);
	if (get_position(cube))
		quit_program(cube);
	cube->ray = malloc(sizeof(t_ray));
	cube->mlx = mlx_init(WINW, WINH, "cub3D", true);
	mlx_set_window_limit(cube->mlx, WINW, WINH, WINW, WINH);
	if (load_textures(cube->t))
		return (ft_error("texture load error\n"), quit_program(cube));
	cube->speed = SPEED * ft_strrlen(cube->map) * 0.1;
}

// init_image //

void	init_image(t_cube *cub)
{
	init_player(cub);
	draw_2d_map(cub);
	cub->background = mlx_new_image(cub->mlx, WINW, WINH + 200);
	raycaster(cub);
	mlx_image_to_window(cub->mlx, cub->background, 0, 0);
	cub->background->instances[0].z = 0;
}
