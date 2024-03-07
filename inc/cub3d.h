/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:12:25 by mle-duc           #+#    #+#             */
/*   Updated: 2024/03/07 16:45:46 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include "parsing.h"

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		l;
	int		endian;
	int		tex_height;
	int		tex_width;
}	t_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	double		move_speed;
	double		rot_sp;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;

	double		perp_wall_dist;
	double		raydir_y;
	double		raydir_x;
	double		draw_start;
	double		draw_end;
	double		line_height;

	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		camera_x;

	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;

	int			left_key;
	int			right_key;
	int			a_key;
	int			d_key;
	int			w_key;
	int			s_key;

	int			wall_color;
	int			floor_color;
	int			ceiling_color;
	t_img		textures[4];
	int			**map;
	t_parsing	*parsing;
}	t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

//minilibx
int			handle_keypress(int keysym, t_data *data);
int			handle_keyrelease(int keysym, t_data *data);
int			cross(t_data *data);
int			render(t_data *d);
void		img_pix_put(t_img *img, int x, int y, int color);
void		move_player(t_data *data);

//drawing
void		raycast(t_data *data);
int			load_textures(t_data *data, t_parsing *p);
void		cub3d(t_parsing *p);
void		destroy_textures(t_data *data);
void		draw_floor(t_data *data);

//calculations
void		calculate_delta_dist(t_data *data);
void		calculate_sidedist(t_data *data);
void		check_if_hit(t_data *data, int *side, int *hit);
void		calculate_perpwalldist(t_data *data, int side);
void		calculate_drawing_settings(t_data *data);

//textures
void		load_north(t_data *data, t_parsing *p);
void		load_south(t_data *data, t_parsing *p);
void		load_west(t_data *data, t_parsing *p);
void		load_east(t_data *data, t_parsing *p);
void		handle_wrong_path(t_data *data, t_parsing *p);

//data initialization
t_data		*initialize(int x, int y, t_parsing *p);
void		set_north_south(t_data *data, t_parsing *p);
void		set_west_east(t_data *data, t_parsing *p);
void		set_direction(t_data *data, t_parsing *p);
void		set_floor_colors(t_data *data, t_parsing *p);
void		set_ceiling_colors(t_data *data, t_parsing *p);

#endif
