/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:29:02 by mle-duc           #+#    #+#             */
/*   Updated: 2024/03/01 15:22:53 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	strafe_left_right(int keysym, t_data *data)
{
	if (keysym == XK_a)
	{
		if (data->map[(int)(data->posX + data->planeX \
		* data->moveSpeed)][(int)(data->posY)] == 0)
			data->posX -= data->planeX * data->moveSpeed;
		if (data->map[(int)data->posX][(int)(data->posY + data->planeY \
		* data->moveSpeed)] == 0)
			data->posY -= data->planeY * data->moveSpeed;
	}
	else if (keysym == XK_d)
	{
		if (data->map[(int)(data->posX + data->planeX \
		* data->moveSpeed)][(int)(data->posY)] == 0)
			data->posX += data->planeX * data->moveSpeed;
		if (data->map[(int)data->posX][(int)(data->posY + data->planeY \
		* data->moveSpeed)] == 0)
			data->posY += data->planeY * data->moveSpeed;
	}
}

static void	move_fw_bw(int keysym, t_data *data)
{
	if (keysym == XK_w)
	{
		if (data->map[(int)(data->posX + data->dirX \
		* data->moveSpeed)][(int)(data->posY)] == 0)
			data->posX += data->dirX * data->moveSpeed;
		if (data->map[(int)data->posX][(int)(data->posY + data->dirY \
		* data->moveSpeed)] == 0)
			data->posY += data->dirY * data->moveSpeed;
	}
	else if (keysym == XK_s)
	{
		if (data->map[(int)(data->posX + data->dirX \
		* data->moveSpeed)][(int)(data->posY)] == 0)
			data->posX -= data->dirX * data->moveSpeed;
		if (data->map[(int)data->posX][(int)(data->posY + data->dirY \
		* data->moveSpeed)] == 0)
			data->posY -= data->dirY * data->moveSpeed;
	}
}

static void	rotate_left_right(int keysym, t_data *d)
{
	double	old_dir_x;
	double	old_px;

	if (keysym == XK_Left)
	{
		old_dir_x = d->dirX;
		d->dirX = d->dirX * cos(d->rotSpeed) \
		- d->dirY * sin(d->rotSpeed);
		d->dirY = old_dir_x * sin(d->rotSpeed) + d->dirY * cos(d->rotSpeed);
		old_px = d->planeX;
		d->planeX = d->planeX * cos(d->rotSpeed) \
		- d->planeY * sin(d->rotSpeed);
		d->planeY = old_px * sin(d->rotSpeed) + d->planeY * cos(d->rotSpeed);
	}
	else if (keysym == XK_Right)
	{
		old_dir_x = d->dirX;
		d->dirX = d->dirX * cos(-d->rotSpeed) \
		- d->dirY * sin(-d->rotSpeed);
		d->dirY = old_dir_x * sin(-d->rotSpeed) + d->dirY * cos(-d->rotSpeed);
		old_px = d->planeX;
		d->planeX = d->planeX * cos(-d->rotSpeed) \
		- d->planeY * sin(-d->rotSpeed);
		d->planeY = old_px * sin(-d->rotSpeed) + d->planeY * cos(-d->rotSpeed);
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
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
	exit(0);
}
