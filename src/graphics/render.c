/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:32:46 by mle-duc           #+#    #+#             */
/*   Updated: 2024/03/07 16:23:06 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			img_pix_put(img, j++, i, color);
		i++;
	}
}

int	render(t_data *d)
{
	if (d->win_ptr == NULL)
		return (1);
	render_background(&d->img, 0x000000);
	move_player(d);
	raycast(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img.mlx_img, 0, 0);
	return (0);
}
