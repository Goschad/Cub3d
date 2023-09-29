/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:52:45 by GIGI              #+#    #+#             */
/*   Updated: 2023/07/03 04:42:07 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static mlx_texture_t	*emote_frame(t_cube *cub, int i)
{
	mlx_texture_t	*t;
	char			*path;
	char			*path2;

	mlx_set_window_title(cub->mlx, "???");
	path = ft_itoa(i);
	path2 = ft_strjoin2("./fuc_t/F-", path);
	free(path);
	path = ft_strjoin2(path2, ".png");
	t = mlx_load_png(path);
	free(path2);
	free(path);
	if (i == 23)
		mlx_set_window_title(cub->mlx, "cub3D");
	if (i == 23)
		cub->emote = 0;
	return (t);
}

void	init_emote(t_cube *cub)
{
	static int		anim = 0;
	static int		time = 0;
	mlx_texture_t	*text;

	if ((cub->emote == 1 || (cub->keys.key_f == 1
				&& cub->emote == 0)) && cub->weapon == 0)
	{
		cub->emote = 1;
		while (anim != 0 && ++time < 2)
			return ;
		mlx_delete_image(cub->mlx, cub->weapon_img);
		text = emote_frame(cub, anim);
		anim++;
		if (anim == 24)
			anim = 0;
		time = 0;
		cub->weapon_img = mlx_texture_to_image(cub->mlx, text);
		mlx_resize_image(cub->weapon_img, WINW / 4, WINH);
		mlx_image_to_window(cub->mlx, cub->weapon_img, WINW / 2, WINH / 18);
		mlx_delete_texture(text);
	}
}
