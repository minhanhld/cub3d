/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 08:39:29 by mle-duc           #+#    #+#             */
/*   Updated: 2024/03/03 09:29:43 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor(t_data *data)
{
	int		x;
	int		y;

	y = -1;
	while (++y < WINDOW_HEIGHT)
	{
		x = -1;
		while (++x < WINDOW_WIDTH)
		{
			img_pix_put(&data->img, x, y, data->floor_color);
			img_pix_put(&data->img, x, WINDOW_HEIGHT - y - 1, \
			data->ceiling_color);
		}
	}
}
