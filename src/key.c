/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 04:34:12 by mbouaza           #+#    #+#             */
/*   Updated: 2023/07/13 14:33:19 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// set_key //

// change value of a key determined //

static void	set_key(mlx_key_data_t keydata, keys_t key, int *value)
{
	if (keydata.key == key && keydata.action == MLX_PRESS)
		*value = 1;
	if (keydata.key == key && keydata.action == MLX_RELEASE)
		*value = 0;
}

// key_init //

// init all controls //

void	key_init(t_cube *cub)
{
	cub->keys.key_w = 0;
	cub->keys.key_a = 0;
	cub->keys.key_s = 0;
	cub->keys.key_d = 0;
	cub->keys.key_r = 0;
	cub->keys.key_l = 0;
	cub->keys.key_u = 0;
	cub->keys.key_f = 0;
	cub->keys.key_e = 0;
	cub->keys.key_m = 1;
}

// key //

// the fonction for the key_hook() //

void	key(mlx_key_data_t keydata, void *param)
{
	t_cube	*cub;

	cub = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		quit_program(cub);
	if (keydata.key == MLX_KEY_M)
		cub->keys.key_m = 0;
	if (keydata.key == MLX_KEY_N)
	{
		mlx_set_mouse_pos(cub->mlx, WINW / 2, WINH / 2);
		mlx_set_cursor_mode(cub->mlx, MLX_MOUSE_HIDDEN);
		cub->keys.key_m = 1;
	}
	set_key(keydata, KEY_FORWARD, &cub->keys.key_w);
	set_key(keydata, KEY_BACKWARD, &cub->keys.key_s);
	set_key(keydata, KEY_STRAF_RIGHT, &cub->keys.key_d);
	set_key(keydata, KEY_STRAF_LEFT, &cub->keys.key_a);
	set_key(keydata, KEY_ROTATE_LEFT, &cub->keys.key_l);
	set_key(keydata, KEY_ROTATE_RIGHT, &cub->keys.key_r);
	set_key(keydata, KEY_UP, &cub->keys.key_u);
	set_key(keydata, KEY_EMOTE, &cub->keys.key_f);
	set_key(keydata, KEY_OPEN, &cub->keys.key_e);
}

void	better_key_hook(void *param)
{
	t_cube	*cub;

	cub = param;
	all_rotate(cub);
	all_move(cub);
	render_player(cub);
	raycaster(cub);
	if (cub->keys.key_m == 1)
		mouse_control(cub);
	else
		mlx_set_cursor_mode(cub->mlx, MLX_MOUSE_NORMAL);
	if (cub->keys.key_e == 1)
		open_door(cub);
	auto_close_door(cub);
	if (cub->emote != 1)
		init_weapon(cub);
	init_emote(cub);
}
