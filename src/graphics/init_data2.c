/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:31:00 by mle-duc           #+#    #+#             */
/*   Updated: 2024/03/03 09:58:13 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_north_south(t_data *data, t_parsing *p)
{
	data->dir_y = 0;
	data->plane_x = 0;
	if (p->_player_d == 'N')
	{
		data->dir_x = -1;
		data->plane_y = 0.66;
	}
	else
	{
		data->dir_x = 1;
		data->plane_y = -0.66;
	}
}

void	set_west_east(t_data *data, t_parsing *p)
{
	data->dir_x = 0;
	data->plane_y = 0;
	if (p->_player_d == 'W')
	{
		data->dir_y = -1;
		data->plane_x = -0.66;
	}
	else
	{
		data->dir_y = 1;
		data->plane_x = 0.66;
	}
}

void	set_direction(t_data *data, t_parsing *p)
{
	if (p->_player_d == 'N' || p->_player_d == 'S')
		set_north_south(data, p);
	else if (p->_player_d == 'W' || p->_player_d == 'E')
		set_west_east(data, p);
}

void	set_floor_colors(t_data *data, t_parsing *p)
{
	t_pos	*tmp;
	int		color;

	tmp = p->pos;
	while (tmp != NULL)
	{
		if (*(tmp->value) == 'F')
		{
			color = 65536 * tmp->range[0] + 256 \
			* tmp->range[1] + tmp->range[2];
			data->floor_color = color;
		}
		tmp = tmp->next;
	}
}

void	set_ceiling_colors(t_data *data, t_parsing *p)
{
	t_pos	*tmp;
	int		color;

	tmp = p->pos;
	while (tmp != NULL)
	{
		if (*(tmp->value) == 'C')
		{
			color = 65536 * tmp->range[0] + 256 \
			* tmp->range[1] + tmp->range[2];
			data->ceiling_color = color;
		}
		tmp = tmp->next;
	}
}
