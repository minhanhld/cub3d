/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pix_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 02:54:24 by mle-duc           #+#    #+#             */
/*   Updated: 2024/02/20 16:10:40 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x > WINDOW_WIDTH - 1 || x < 1 || y > WINDOW_HEIGHT - 1 || y < 1)
		return ;
	pixel = img->addr + (img->l * y + x * (img->bpp / 8));
	*(int *)pixel = color;
}
