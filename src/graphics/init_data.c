/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:15:42 by mle-duc           #+#    #+#             */
/*   Updated: 2024/03/02 21:26:55 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_north_south(t_data *data, t_parsing *p)
{
	data->dirY = 0;
	data->planeX = 0;
	if (p->_playerD == 'N')
	{
		data->dirX = -1;
		data->planeY = 0.66;
	}
	else
	{
		data->dirX = 1;
		data->planeY = -0.66;
	}
}

static void	set_west_east(t_data *data, t_parsing *p)
{
	data->dirX = 0;
	data->planeY = 0;
	if (p->_playerD == 'W')
	{
		data->dirY = -1;
		data->planeX = -0.66;
	}
	else
	{
		data->dirY = 1;
		data->planeX = 0.66;
	}
}

static void	set_direction(t_data *data, t_parsing *p)
{
	if (p->_playerD == 'N' || p->_playerD == 'S')
		set_north_south(data, p);
	else if (p->_playerD == 'W' || p->_playerD == 'E')
		set_west_east(data, p);
}

static void	set_floor_colors(t_data *data, t_parsing *p)
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

static void	set_ceiling_colors(t_data *data, t_parsing *p)
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

static void	set_values(t_data *data, t_parsing *p)
{
	init_text_img(data);
	load_textures(data, p);
	data->moveSpeed = 0.017 * 5.0;
	data->rotSpeed = 0.017 * 3.0;
	data->posX = p->_playerY;
	data->posY = p->_playerX;
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
