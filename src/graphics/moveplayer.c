/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:10:17 by mle-duc           #+#    #+#             */
/*   Updated: 2024/03/07 16:45:31 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	strafe_left_right(t_data *data)
{
	if (data->a_key == 1)
	{
		if (data->map[(int)(data->pos_x - data->plane_x \
		* data->move_speed)][(int)(data->pos_y)] == 0)
			data->pos_x -= data->plane_x * data->move_speed;
		if (data->map[(int)data->pos_x][(int)(data->pos_y - data->plane_y \
		* data->move_speed)] == 0)
			data->pos_y -= data->plane_y * data->move_speed;
	}
	else if (data->d_key == 1)
	{
		if (data->map[(int)(data->pos_x + data->plane_x \
		* data->move_speed)][(int)(data->pos_y)] == 0)
			data->pos_x += data->plane_x * data->move_speed;
		if (data->map[(int)data->pos_x][(int)(data->pos_y + data->plane_y \
		* data->move_speed)] == 0)
			data->pos_y += data->plane_y * data->move_speed;
	}
}

static void	move_fw_bw(t_data *data)
{
	if (data->w_key == 1)
	{
		if (data->map[(int)(data->pos_x + data->dir_x \
		* data->move_speed)][(int)(data->pos_y)] == 0)
			data->pos_x += data->dir_x * data->move_speed;
		if (data->map[(int)data->pos_x][(int)(data->pos_y + data->dir_y \
		* data->move_speed)] == 0)
			data->pos_y += data->dir_y * data->move_speed;
	}
	else if (data->s_key == 1)
	{
		if (data->map[(int)(data->pos_x - data->dir_x \
		* data->move_speed)][(int)(data->pos_y)] == 0)
			data->pos_x -= data->dir_x * data->move_speed;
		if (data->map[(int)data->pos_x][(int)(data->pos_y - data->dir_y \
		* data->move_speed)] == 0)
			data->pos_y -= data->dir_y * data->move_speed;
	}
}

static void	rotate_left_right(t_data *d)
{
	double	old_dir_x;
	double	old_px;

	if (d->left_key == 1)
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
	else if (d->right_key == 1)
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

void	move_player(t_data *data)
{
	rotate_left_right(data);
	move_fw_bw(data);
	strafe_left_right(data);
}
