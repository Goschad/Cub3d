/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 01:55:06 by mbouaza           #+#    #+#             */
/*   Updated: 2023/07/13 16:15:46 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "get_next_line/get_next_line.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <string.h>

// define //

# define DOF 50

# define WHI 0xFFFFFFFF
# define GREY 0x808080FF
# define BLACK 0x000000FF
# define RED 0xFF0000FF
# define GRE 0x00FF00FF

# define PI 3.1415926535
# define P2 1.57079632675
# define P3 4.71238898038
# define DR 0.0174533

# define WINW 1080
# define WINH 720
# define SPEED 0.25

# define KEY_FORWARD MLX_KEY_W
# define KEY_BACKWARD MLX_KEY_S
# define KEY_STRAF_RIGHT MLX_KEY_D
# define KEY_STRAF_LEFT MLX_KEY_A
# define KEY_ROTATE_RIGHT MLX_KEY_RIGHT
# define KEY_ROTATE_LEFT MLX_KEY_LEFT
# define KEY_RUN MLX_KEY_LEFT_SHIFT
# define KEY_UP MLX_KEY_UP
# define KEY_EMOTE MLX_KEY_F
# define KEY_OPEN MLX_KEY_R

// delimited size map //

# define W 50
# define H 50

// gabin struct //

typedef struct s_size
{
	int		height;
	int		width;
	int		*tab_x;
	int		*tab_y;
	char	**map;
	int		cmp;
	int		k;
	int		l;
	int		i;
	int		j;
	int		newj;
	char	letter;
	int		status;
}		t_size;

typedef struct s_coordinate
{
	int	y;
	int	x;
}		t_coordinate;

typedef struct s_check
{
	int	no;
	int	no2;
	int	so;
	int	so2;
	int	we;
	int	we2;
	int	ea;
	int	ea2;
	int	other;
	int	point;
}	t_check;

// struct //

typedef struct s_textures
{
	char			*t_no;
	char			*t_so;
	char			*t_ea;
	char			*t_we;
	int				fl;
	int				ce;
	mlx_texture_t	*text_no;
	mlx_texture_t	*text_so;
	mlx_texture_t	*text_ea;
	mlx_texture_t	*text_we;
	mlx_texture_t	*text_do;
}	t_textures;

typedef struct s_keys
{
	int	key_w;
	int	key_a;
	int	key_s;
	int	key_d;
	int	key_r;
	int	key_l;
	int	key_u;
	int	key_f;
	int	key_e;
	int	key_m;
}	t_keys;

typedef struct s_ray
{
	float			pdx;
	float			pdy;
	float			pdxs;
	float			pdys;
	float			pxx;
	float			pyy;
	float			px;
	float			py;
	float			pa;
	float			rx;
	float			ry;
	float			ra;
	float			xo;
	float			yo;
	float			ray_nb;
	float			r;
	float			dist;
	float			dis_h;
	float			hx;
	float			hy;
	float			a_tan;
	float			dis_v;
	float			vx;
	float			vy;
	float			ntan;
	float			shade;
	float			ca;
	float			line_h;
	float			t_width;
	float			t_height;
	float			ty_step;
	float			ty_off;
	float			line_o;
	float			ty;
	float			tx;
	int				hmt;
	int				vmt;
	int				mx;
	int				my;
	int				dof;
	int				y;
	int				c;
	int				w;
	int				h;
	int				z;
	int				xy[2];
	mlx_texture_t	*t;
}	t_ray;

typedef struct s_cube
{
	int			i;
	int			map_s_x;
	int			map_s_y;
	float		px;
	float		py;
	float		pa;
	int			m_size;
	int			p_size;
	int			p_color;
	float		speed;
	float		jumping;
	char		*wea;
	char		**all_map;
	char		**map;
	char		**mmap;
	int			emote;
	int			weapon;
	char		p_letter;
	bool		door;
	int			mouse_x;
	int			mouse_y;
	mlx_image_t	*player_img;
	mlx_image_t	*map_img;
	mlx_image_t	*background;
	mlx_image_t	*weapon_img;
	t_textures	*t;
	t_ray		*ray;
	t_keys		keys;
	mlx_t		*mlx;
}	t_cube;

// main //

// init //

int		check_letter(char *line);
void	init_all(t_cube *cube, char **argv, t_size *size,
			t_coordinate *coordinate);
void	init_image(t_cube *cub);

// quit //

void	quit_program(t_cube *cub);

// lib_utils //

char	*ft_strdup(char *s1);
char	**ft_strrdup(char **s1);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin2(char const *s1, char const *s2);

// another_utils //

int		ft_strrlen(char **str);
void	delete_all_newline(t_cube *cub);
int32_t	pix_ft(int32_t r, int32_t g, int32_t b, int32_t a);
void	freel(char **str, int n);

// ft_split //

char	**ft_split(char const *s, char c);

// ft_atoi //

int		f_toi(const char *str);

// ft_itoa //

char	*ft_itoa(int nbr);

// error //

void	ft_error(char *str);
void	free_tab(char **tab);

// check //

int		check_all(t_cube *cub, char *file,
			t_size *size, t_coordinate *coordinate);

// check_2.c //

int		delimited_size(char **map);
int		check_cub(char *f);
int		search_g(char **map);

// true_map //

char	**copy_true_map(char **map);

// utils_texture //

void	draw_2d_map(t_cube *cub);
int		load_textures(t_textures *t);
void	background_color(t_cube *cub);
void	texture_orientation(t_cube *c, int n);

// parse_map //

char	**copy_map(char *path);
int		begining_map(char **map);
int		init_cub_file(t_cube *cub, char *path);

// character_utils //

int		get_position(t_cube *cub);

// player //

void	render_player(t_cube *cub);
void	init_player(t_cube *cub);
void	draw_color(mlx_image_t *img, int xy[2], int x, int color);

// key //

void	key_init(t_cube *cub);
void	better_key_hook(void *param);
void	key(mlx_key_data_t keydata, void *param);

// hide_map //

char	**hide_map(char **map);
int		verif_empty(char *line);

// raycasting //

void	raycaster(t_cube *cub);

// horizontal_ray //

void	horizontal(t_cube *cub);

// vertical_ray //

void	vertical(t_cube *cub);

// math //

void	draw(t_cube *cub);
void	fix_angle(float *ra);
float	distance(float x, float y, float fx, float fy);
int		pixel_to_color(t_cube *cub, uint32_t x, uint32_t y);

// mouse //

void	mouse_control(t_cube *cub);

// move_utils //

void	all_move(t_cube *cub);
void	all_rotate(t_cube *cub);

// weapon //

void	init_weapon(t_cube *cub);

// emote //

void	init_emote(t_cube *cub);

// door //

void	auto_close_door(t_cube *cub);
void	open_door(t_cube *cub);
void	free_all_size(t_size *size);

/* gabin */

// utils_texture_check //

char	*remove_space(char *line);
void	init_check(t_check *check);
void	check_slash(char **map, t_check *check);

// utils_texture_check_2 //

int		check_texture(t_cube *cube);
int		nbr_empty_line(char **map);

// utils_texture_check_3 //

char	**remove_empty_line(char **map);
int		check_color(char *line);
int		verif_color(char **map);

// utils_map_check //

char	**replace(char **map, t_size *size);
char	**contour(char **map, t_size *size);
void	init_contour(char ***new_map, t_size *size);
void	find_map_dimensions(char **map, t_size *size);
void	search_begin(char **map, t_coordinate *coordinate, char c);

// utils_map_check_2 //

void	replace_door(char **map, char c, char r);
int		verif_finish_map(char **map);
void	vrf_map(int *k, int *i, t_size *size, int nb);
void	init_deep_algo(t_size *size, t_cube *cube,
			t_coordinate *coordinate, int nb);

// utils_map_check_3 //

void	contour_all(char **new_map, t_size *size, char **map);
void	init_deep(int *k, int *i, int *j);
void	deep_algo2(int *i, int *j, int *k, t_size *size);

// utils_map_check_4 //

void	delete_n(t_size *size);
int		continue_deep(t_size *size, t_cube *cube, t_coordinate *coordinate);
int		len_str(char *s);

// utils_map_check_5 //

int		max_nb(t_size *size);
int		deep_algo(t_cube *cube, t_size *size, t_coordinate *coordinate, int nb);
char	*copy_first(char *line);
void	init_deep_algo2(t_coordinate *coordinate, int *i, int *j, t_size *size);
void	character_letter(t_cube *cub, char **map);

#endif
