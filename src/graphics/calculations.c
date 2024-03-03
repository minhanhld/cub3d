/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:07:21 by mle-duc           #+#    #+#             */
/*   Updated: 2024/03/03 09:46:01 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_delta_dist(t_data *data)
{
	data->raydir_x = data->dir_x + data->plane_x * data->camera_x;
	data->raydir_y = data->dir_y + data->plane_y * data->camera_x;
	data->map_x = (int)data->pos_x;
	data->map_y = (int)data->pos_y;
	if (data->raydir_x == 0)
		data->deltadist_x = 1e30;
	else
		data->deltadist_x = fabs(1 / data->raydir_x);
	if (data->raydir_y == 0)
		data->deltadist_y = 1e30;
	else
		data->deltadist_y = fabs(1 / data->raydir_y);
}

void	calculate_sidedist(t_data *data)
{
	if (data->raydir_x < 0)
	{
		data->step_x = -1;
		data->sidedist_x = (data->pos_x - data->map_x) * data->deltadist_x;
	}
	else
	{
		data->step_x = 1;
		data->sidedist_x = (data->map_x + 1.0 - data->pos_x) \
		* data->deltadist_x;
	}
	if (data->raydir_y < 0)
	{
		data->step_y = -1;
		data->sidedist_y = (data->pos_y - data->map_y) * data->deltadist_y;
	}
	else
	{
		data->step_y = 1;
		data->sidedist_y = (data->map_y + 1.0 - data->pos_y) \
		* data->deltadist_y;
	}
}

void	check_if_hit(t_data *data, int *side, int *hit)
{
	while (*hit == 0)
	{
		if (data->sidedist_x < data->sidedist_y)
		{
			data->sidedist_x += data->deltadist_x;
			data->map_x += data->step_x;
			*side = 0;
		}
		else
		{
			data->sidedist_y += data->deltadist_y;
			data->map_y += data->step_y;
			*side = 1;
		}
		if ((data->map)[data->map_x][data->map_y] > 0)
			*hit = 1;
	}
}

void	calculate_perpwalldist(t_data *data, int side)
{
	if (side == 0)
		data->perp_wall_dist = data->sidedist_x - data->deltadist_x;
	else
		data->perp_wall_dist = data->sidedist_y - data->deltadist_y;
}

void	calculate_drawing_settings(t_data *data)
{
	data->line_height = (int)(WINDOW_HEIGHT / data->perp_wall_dist);
	data->draw_start = -data->line_height / 2 + WINDOW_HEIGHT / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + WINDOW_HEIGHT / 2;
	if (data->draw_end >= WINDOW_HEIGHT)
		data->draw_end = WINDOW_HEIGHT - 1;
}
