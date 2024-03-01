/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:07:59 by mle-duc           #+#    #+#             */
/*   Updated: 2024/02/29 00:21:25 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int worldMap[24][24]=
{
  {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

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
		float	rayDirX0 = data->dirX - data->planeX;
		float	rayDirY0 = data->dirY - data->planeY;
		float	rayDirX1 = data->dirX + data->planeX;
		float	rayDirY1 = data->dirY + data->planeY;

		int p = a - WINDOW_HEIGHT / 2;

		float	posZ = 0.5 * WINDOW_HEIGHT;

		float	rowDistance = posZ / p;

		float	floorStepX = rowDistance * (rayDirX1 - rayDirX0) / WINDOW_WIDTH;
		float	floorStepY = rowDistance * (rayDirY1 - rayDirY0) / WINDOW_WIDTH;

		float	floorX = data->posX + rowDistance * rayDirX0;
		float	floorY = data->posY + rowDistance * rayDirY0;
		int	tempX = -1;
		while (++tempX < WINDOW_WIDTH)
		{
			int	cellX = (int)floorX;
			int	cellY = (int)floorY;

			int	tx = (int)(64 * (floorX - cellX)) & (64 -1);
			int	ty = (int)(64 * (floorY - cellY)) & (64 -1);

			floorX += floorStepX;
			floorY += floorStepY;

			int	floorTexture = 1;
			int	ceilingTexture = 2;
			int	color;
			color = *(int *)(data->textures[floorTexture].addr + (ty * data->textures[floorTexture].l + tx * (data->textures[floorTexture].bpp/8)));
			img_pix_put(img, tempX, a, color);
			color = *(int *)(data->textures[ceilingTexture].addr + (ty * data->textures[ceilingTexture].l + tx * (data->textures[ceilingTexture].bpp/8)));
			img_pix_put(img, tempX, WINDOW_HEIGHT - a - 1, color);
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
			if (worldMap[mapX][mapY] > 0)
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

		int	texNum = worldMap[mapX][mapY] - 1;

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
			color = *(int *)(data->textures[texNum].addr + (texY * data->textures[texNum].l + texX * (data->textures[texNum].bpp/8)));
			img_pix_put(img, x, j, color);
			j++;
		}
		x++;
	}
}
