/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:12:25 by mle-duc           #+#    #+#             */
/*   Updated: 2024/02/28 22:33:30 by mle-duc          ###   ########.fr       */
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

# define WINDOW_WIDTH 640
# define WINDOW_HEIGHT 480

typedef struct s_map
{
	int		width;
	int		height;
	int		**grid;
	double	yo;
	double	xo;
	double	line_length;
}	t_map;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		l;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_map	*map;
	double	moveSpeed;
	double	rotSpeed;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	t_img	textures[8];
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

int	handle_input(int keysym, t_data *data);
int	cross(t_data *data);
int	render(t_data *d);
void	img_pix_put(t_img *img, int x, int y, int color);
t_data	*initialize(int x, int y);
void	raycast(t_img *img, t_data *data);
int	load_textures(t_data *data);
#endif
