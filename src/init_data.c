/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:15:42 by mle-duc           #+#    #+#             */
/*   Updated: 2024/02/27 16:24:53 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*initialize(int x, int y)
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
	data->win_ptr = mlx_new_window(data->mlx_ptr, x, y, "cub3d - educlos,mleduc");
	if (!(data->win_ptr))
	{
		free(data->mlx_ptr);
		free(data);
		return (NULL);
	}
	/*data->textures = malloc(sizeof(t_img) * 8);
	if (!data->textures)
		return (NULL);
	*/
	load_textures(data);
	data->moveSpeed = 0.017 * 5.0;
	data->rotSpeed = 0.017 * 3.0;
	data->posX = 22;
	data->posY = 12;
	data->dirX = -1;
	data->dirY = 0;
	data->planeX = 0;
	data->planeY = 0.66;
	return (data);
}
