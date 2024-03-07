/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:15:42 by mle-duc           #+#    #+#             */
/*   Updated: 2024/03/07 16:29:42 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_text_img(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->textures[i].mlx_img = NULL;
		i++;
	}
}

static void	init_values(t_data *data)
{
	data->perp_wall_dist = 0;
	data->raydir_y = 0;
	data->raydir_x = 0;
	data->draw_start = 0;
	data->draw_end = 0;
	data->line_height = 0;
	data->wall_color = 0;
	data->sidedist_x = 0;
	data->sidedist_y = 0;
	data->deltadist_x = 0;
	data->deltadist_y = 0;
	data->map_x = 0;
	data->map_y = 0;
	data->step_x = 0;
	data->step_y = 0;
	data->camera_x = 0;
	data->move_speed = 0.007 * 5.0;
	data->rot_sp = 0.010 * 3.0;
	data->left_key = 0;
	data->right_key = 0;
	data->w_key = 0;
	data->s_key = 0;
	data->a_key = 0;
	data->d_key = 0;
}

static void	set_values(t_data *data, t_parsing *p)
{
	init_values(data);
	data->pos_x = p->_player_y + 0.5;
	data->pos_y = p->_player_x + 0.5;
	init_text_img(data);
	load_textures(data, p);
	set_direction(data, p);
	set_floor_colors(data, p);
	set_ceiling_colors(data, p);
	data->map = p->_map;
	data->parsing = p;
}

t_data	*initialize(int x, int y, t_parsing *p)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx_ptr = mlx_init();
	if (!(data->mlx_ptr))
	{
		free(data);
		return (NULL);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, x, y, \
	"cub3d - educlos,mleduc");
	if (!(data->win_ptr))
	{
		free(data->mlx_ptr);
		free(data);
		return (NULL);
	}
	set_values(data, p);
	return (data);
}
