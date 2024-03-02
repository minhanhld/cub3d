/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:07:59 by mle-duc           #+#    #+#             */
/*   Updated: 2024/03/02 21:21:37 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast(t_img *img, t_data *data)
{

	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	int		hit = 0;
	int		side;

	int		x = 0;
	int		a = -1;
	while (++a < WINDOW_HEIGHT)
	{
		int	tempX = -1;
		while (++tempX < WINDOW_WIDTH)
		{
			img_pix_put(img, tempX, a, data->floor_color);
			img_pix_put(img, tempX, WINDOW_HEIGHT - a - 1, data->ceiling_color);
		}
	}
	//
	//raycast
	while (x < WINDOW_WIDTH)
	{
		double	cameraX = 2 * x / (double)WINDOW_WIDTH - 1;
		double	rayDirX = data->dirX + data->planeX * cameraX;
		double	rayDirY = data->dirY + data->planeY * cameraX;
		mapX = (int)data->posX;
		mapY = (int)data->posY;

		if(rayDirX == 0)
			deltaDistX = 1e30;
		else
			deltaDistX = fabs(1 / rayDirX);
		if (rayDirY == 0)
			deltaDistY = 1e30;
		else
			deltaDistY = fabs(1 / rayDirY);
		hit = 0;
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (data->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - data->posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (data->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - data->posY) * deltaDistY;
		}
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if ((data->map)[mapX][mapY] > 0)
				hit = 1;
		}
		if (side == 0)
			perpWallDist = sideDistX - deltaDistX;
		else
			perpWallDist = sideDistY - deltaDistY;
		int	lineHeight = (int)(WINDOW_HEIGHT / perpWallDist);

		int	drawStart = -lineHeight/2 + WINDOW_HEIGHT/2;
		if (drawStart < 0)
			drawStart = 0;
		int	drawEnd = lineHeight/2 + WINDOW_HEIGHT/2;
		if (drawEnd >= WINDOW_HEIGHT)
			drawEnd = WINDOW_HEIGHT - 1;

		int	texNum = data->map[mapX][mapY];

		double	wallX;
		if (side == 0)
			wallX = data->posY + perpWallDist * rayDirY;
		else
			wallX = data->posX + perpWallDist * rayDirX;
		wallX -= floor(wallX);

		int	texX = (int)(wallX * 64.0);
		if (side == 0 && rayDirX > 0)
			texX = 64 - texX - 1;
		if (side == 1 && rayDirY < 0)
			texX = 64 - texX - 1;

		double	step = 1.0 * 64 / lineHeight;
		double	texPos = (drawStart - WINDOW_HEIGHT / 2 + lineHeight / 2) * step;
		int	j = drawStart;
		while (j < drawEnd)
		{
			int	color;
			int	texY = (int)texPos & (64 -1);
			texPos += step;
			//color = texture[texNum][64 * texY + texX];
			if (side == 1 && rayDirY < 0)
			{
				color = *(int *)(data->textures[3].addr + (texY * data->textures[3].l + texX * (data->textures[3].bpp/8)));
				img_pix_put(img, x, j, color);

			}
			else if (side == 1 && rayDirY > 0)
			{
				color = *(int *)(data->textures[2].addr + (texY * data->textures[2].l + texX * (data->textures[2].bpp/8)));
				img_pix_put(img, x, j, color);
			}
			else if (side == 0 && rayDirX < 0)
			{
				color = *(int *)(data->textures[0].addr + (texY * data->textures[0].l + texX * (data->textures[0].bpp/8)));
				img_pix_put(img, x, j, color);
			}
			else if (side == 0 && rayDirX > 0)
			{
				color = *(int *)(data->textures[1].addr + (texY * data->textures[1].l + texX * (data->textures[1].bpp/8)));
				img_pix_put(img, x, j, color);
			}
			j++;
		}
		x++;
	}
}
