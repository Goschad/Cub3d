/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 02:08:33 by mbouaza           #+#    #+#             */
/*   Updated: 2023/07/13 13:46:23 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// delete_textures //

static void	delete_textures(t_textures *texture)
{
	if (texture->text_do)
		mlx_delete_texture(texture->text_do);
	if (texture->text_no)
		mlx_delete_texture(texture->text_no);
	if (texture->text_so)
		mlx_delete_texture(texture->text_so);
	if (texture->text_we)
		mlx_delete_texture(texture->text_we);
	if (texture->text_ea)
		mlx_delete_texture(texture->text_ea);
}

void	quit_program(t_cube *cub)
{
	delete_textures(cub->t);
	if (cub->t->t_ea)
		free(cub->t->t_ea);
	if (cub->t->t_no)
		free(cub->t->t_no);
	if (cub->t->t_so)
		free(cub->t->t_so);
	if (cub->t->t_we)
		free(cub->t->t_we);
	if (cub->t)
		free(cub->t);
	if (cub->ray)
		free(cub->ray);
	if (cub->map)
		free_tab(cub->map);
	if (cub->mmap)
		free_tab(cub->mmap);
	if (cub->all_map)
		free_tab(cub->all_map);
	if (cub->mlx)
		mlx_terminate(cub->mlx);
	free(cub);
	exit(0);
}
