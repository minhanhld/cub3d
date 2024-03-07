/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:07:59 by mle-duc           #+#    #+#             */
/*   Updated: 2024/03/07 18:42:01 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	north_texture(t_data *data, int j, int x)
{
	double	wall_x;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;

	wall_x = data->pos_y + data->perp_wall_dist * data->raydir_y;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)data->textures[0].tex_width);
	step = 1.0 * data->textures[0].tex_height / data->line_height;
	tex_pos = (data->draw_start - WINDOW_HEIGHT / 2 \
	+ data->line_height / 2) * step;
	while (j < data->draw_end)	
	{
		tex_y = (int)tex_pos;
		tex_pos += step;
		data->wall_color = *(int *)(data->textures[0].addr + (tex_y \
		* data->textures[0].l + tex_x * (data->textures[0].bpp / 8)));
		img_pix_put(&data->img, x, j, data->wall_color);
		j++;
	}
}

void	south_texture(t_data *data, int j, int x)
{
	double	wall_x;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;

	wall_x = data->pos_y + data->perp_wall_dist * data->raydir_y;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)data->textures[1].tex_width);
	tex_x = data->textures[1].tex_width - tex_x - 1;
	step = 1.0 * data->textures[1].tex_height / data->line_height;
	tex_pos = (data->draw_start - WINDOW_HEIGHT / 2 \
	+ data->line_height / 2) * step;
	while (j < data->draw_end)
	{
		tex_y = (int)tex_pos;
		tex_pos += step;
		data->wall_color = *(int *)(data->textures[1].addr + (tex_y \
		* data->textures[1].l + tex_x * (data->textures[1].bpp / 8)));
		img_pix_put(&data->img, x, j, data->wall_color);
		j++;
	}
}

void	west_texture(t_data *data, int j, int x)
{
	double	wall_x;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;

	wall_x = data->pos_x + data->perp_wall_dist * data->raydir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)data->textures[2].tex_width);
	tex_x = data->textures[2].tex_width - tex_x - 1;
	step = 1.0 * data->textures[2].tex_height / data->line_height;
	tex_pos = (data->draw_start - WINDOW_HEIGHT / 2 \
	+ data->line_height / 2) * step;
	while (j < data->draw_end)
	{
		tex_y = (int)tex_pos;
		tex_pos += step;
		data->wall_color = *(int *)(data->textures[2].addr + (tex_y \
		* data->textures[2].l + tex_x * (data->textures[2].bpp / 8)));
		img_pix_put(&data->img, x, j, data->wall_color);
		j++;
	}
}

void	east_texture(t_data *data, int j, int x)
{
	double	wall_x;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;

	wall_x = data->pos_x + data->perp_wall_dist * data->raydir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)data->textures[3].tex_width);
	step = 1.0 * data->textures[3].tex_height / data->line_height;
	tex_pos = (data->draw_start - WINDOW_HEIGHT / 2 \
	+ data->line_height / 2) * step;
	while (j < data->draw_end)
	{
		tex_y = (int)tex_pos;
		tex_pos += step;
		data->wall_color = *(int *)(data->textures[3].addr + (tex_y \
		* data->textures[3].l + tex_x * (data->textures[3].bpp / 8)));
		img_pix_put(&data->img, x, j, data->wall_color);
		j++;
	}
}

void	raycast(t_data *data)
{
	int		hit;
	int		x;
	int		side;

	x = 0;
	draw_floor(data);
	while (x < WINDOW_WIDTH)
	{
		data->camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
		calculate_delta_dist(data);
		calculate_sidedist(data);
		hit = 0;
		check_if_hit(data, &side, &hit);
		calculate_perpwalldist(data, side);
		calculate_drawing_settings(data);
		if (side == 0 && data->raydir_x < 0)
			north_texture(data, data->draw_start, x);
		else if (side == 0 && data->raydir_x > 0)
			south_texture(data, data->draw_start, x);
		else if (side == 1 && data->raydir_y < 0)
			west_texture(data, data->draw_start, x);
		else if (side == 1 && data->raydir_y > 0)
			east_texture(data, data->draw_start, x);
		x++;
	}
}
