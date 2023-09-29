/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 06:58:28 by mbouaza           #+#    #+#             */
/*   Updated: 2023/07/03 04:00:22 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static mlx_texture_t	*shot_frame(t_cube *cub, int i)
{
	mlx_texture_t	*t;
	char			*path;
	char			*path2;

	path = ft_itoa(i);
	path2 = ft_strjoin2("./wea_t/W-", path);
	free(path);
	path = ft_strjoin2(path2, ".png");
	t = mlx_load_png(path);
	free(path2);
	free(path);
	if (i == 23)
		cub->weapon = 0;
	return (t);
}

void	init_weapon(t_cube *cub)
{
	static int		anim = 0;
	static int		time = 0;
	mlx_texture_t	*text;

	while (anim != 0 && ++time < 2)
		return ;
	mlx_delete_image(cub->mlx, cub->weapon_img);
	if (cub->keys.key_u == 0 && anim == 0)
		text = mlx_load_png("./wea_t/W-0.png");
	else
	{
		mlx_set_window_title(cub->mlx, "PAN !");
		cub->weapon = 1;
		text = shot_frame(cub, anim);
		anim++;
		if (anim == 24)
			mlx_set_window_title(cub->mlx, "cub3D");
		if (anim == 24)
			anim = 0;
		time = 0;
	}
	cub->weapon_img = mlx_texture_to_image(cub->mlx, text);
	mlx_resize_image(cub->weapon_img, WINW / 2, WINH);
	mlx_image_to_window(cub->mlx, cub->weapon_img, WINW / 2, WINH / 3);
	mlx_delete_texture(text);
}
