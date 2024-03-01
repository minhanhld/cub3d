/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:51:54 by mle-duc           #+#    #+#             */
/*   Updated: 2024/02/27 16:26:34 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_textures(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 7)
	{
		mlx_destroy_image(data->mlx_ptr, data->textures[i].mlx_img);
	}
}
void	hooks(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_input, data);
	//mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &cross, data);
	mlx_hook(data->win_ptr, 17, 1L << 0, &cross, data);
	mlx_loop(data->mlx_ptr);
}

void	clear(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	destroy_textures(data);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
}

void	fdf(void)
{
	t_data	*data;
	t_img	img;


	data = initialize(WINDOW_WIDTH, WINDOW_HEIGHT);
	img.mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.l, &img.endian);
	data->img = img;
	hooks(data);
	clear(data);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	fdf();
}
