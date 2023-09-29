/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 01:58:06 by mbouaza           #+#    #+#             */
/*   Updated: 2023/07/13 13:38:21 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	test_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	else if (read(fd, 0, 0))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_cube			*cube;
	t_coordinate	*coordinate;
	t_size			*size;

	if (argc != 2 || check_cub(argv[1]) == 1)
		return (ft_error("Arguments error\n"), 1);
	if (test_file(argv[1]))
		return (ft_error("map error\n"), 1);
	cube = malloc(sizeof(t_cube));
	coordinate = malloc(sizeof(t_coordinate));
	size = malloc(sizeof(t_size));
	init_all(cube, argv, size, coordinate);
	mlx_set_cursor_mode(cube->mlx, MLX_MOUSE_HIDDEN);
	init_image(cube);
	key_init(cube);
	mlx_key_hook(cube->mlx, &key, cube);
	mlx_loop_hook(cube->mlx, &better_key_hook, cube);
	render_player(cube);
	raycaster(cube);
	mlx_loop(cube->mlx);
	quit_program(cube);
}
