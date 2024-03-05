/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:29:02 by mle-duc           #+#    #+#             */
/*   Updated: 2024/03/05 09:38:57 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	strafe_left_right(int keysym, t_data *data)
{
	if (keysym == XK_a)
	{
		if (data->map[(int)(data->pos_x - data->plane_x \
		* data->move_speed)][(int)(data->pos_y)] == 0)
			data->pos_x -= data->plane_x * data->move_speed;
		if (data->map[(int)data->pos_x][(int)(data->pos_y - data->plane_y \
		* data->move_speed)] == 0)
			data->pos_y -= data->plane_y * data->move_speed;
	}
	else if (keysym == XK_d)
	{
		if (data->map[(int)(data->pos_x + data->plane_x \
		* data->move_speed)][(int)(data->pos_y)] == 0)
			data->pos_x += data->plane_x * data->move_speed;
		if (data->map[(int)data->pos_x][(int)(data->pos_y + data->plane_y \
		* data->move_speed)] == 0)
			data->pos_y += data->plane_y * data->move_speed;
	}
}

static void	move_fw_bw(int keysym, t_data *data)
{
	if (keysym == XK_w)
	{
		if (data->map[(int)(data->pos_x + data->dir_x \
		* data->move_speed)][(int)(data->pos_y)] == 0)
			data->pos_x += data->dir_x * data->move_speed;
		if (data->map[(int)data->pos_x][(int)(data->pos_y + data->dir_y \
		* data->move_speed)] == 0)
			data->pos_y += data->dir_y * data->move_speed;
	}
	else if (keysym == XK_s)
	{
		if (data->map[(int)(data->pos_x - data->dir_x \
		* data->move_speed)][(int)(data->pos_y)] == 0)
			data->pos_x -= data->dir_x * data->move_speed;
		if (data->map[(int)data->pos_x][(int)(data->pos_y - data->dir_y \
		* data->move_speed)] == 0)
			data->pos_y -= data->dir_y * data->move_speed;
	}
}

static void	rotate_left_right(int keysym, t_data *d)
{
	double	old_dir_x;
	double	old_px;

	if (keysym == XK_Left)
	{
		old_dir_x = d->dir_x;
		d->dir_x = d->dir_x * cos(d->rot_sp) \
		- d->dir_y * sin(d->rot_sp);
		d->dir_y = old_dir_x * sin(d->rot_sp) + d->dir_y * cos(d->rot_sp);
		old_px = d->plane_x;
		d->plane_x = d->plane_x * cos(d->rot_sp) \
		- d->plane_y * sin(d->rot_sp);
		d->plane_y = old_px * sin(d->rot_sp) + d->plane_y * cos(d->rot_sp);
	}
	else if (keysym == XK_Right)
	{
		old_dir_x = d->dir_x;
		d->dir_x = d->dir_x * cos(-d->rot_sp) \
		- d->dir_y * sin(-d->rot_sp);
		d->dir_y = old_dir_x * sin(-d->rot_sp) + d->dir_y * cos(-d->rot_sp);
		old_px = d->plane_x;
		d->plane_x = d->plane_x * cos(-d->rot_sp) \
		- d->plane_y * sin(-d->rot_sp);
		d->plane_y = old_px * sin(-d->rot_sp) + d->plane_y * cos(-d->rot_sp);
	}
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	rotate_left_right(keysym, data);
	move_fw_bw(keysym, data);
	strafe_left_right(keysym, data);
	return (0);
}

int	cross(t_data *data)
{
	destroy_textures(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	free_structs(data->parsing);
	free(data->mlx_ptr);
	free(data);
	exit(0);
}
