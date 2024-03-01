/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:08:32 by mle-duc           #+#    #+#             */
/*   Updated: 2024/02/27 15:25:33 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_textures(t_data *data)
{
	int	width;
	int	height;

	data->textures[0].mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./src/textures/greystone.xpm", &width, &height);
	data->textures[0].addr = mlx_get_data_addr(data->textures[0].mlx_img, \
	&data->textures[0].bpp, &data->textures[0].l, &data->textures[0].endian);
	data->textures[1].mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./src/textures/barrel.xpm", &width, &height);
	data->textures[1].addr = mlx_get_data_addr(data->textures[1].mlx_img, &data->textures[1].bpp, &data->textures[1].l, &data->textures[1].endian);
	data->textures[2].mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./src/textures/colorstone.xpm", &width, &height);
	data->textures[2].addr = mlx_get_data_addr(data->textures[2].mlx_img, &data->textures[2].bpp, &data->textures[2].l, &data->textures[2].endian);
	data->textures[3].mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./src/textures/eagle.xpm", &width, &height);
	data->textures[3].addr = mlx_get_data_addr(data->textures[3].mlx_img, &data->textures[3].bpp, &data->textures[3].l, &data->textures[3].endian);
	data->textures[4].mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./src/textures/greenlight.xpm", &width, &height);
	data->textures[4].addr = mlx_get_data_addr(data->textures[4].mlx_img, &data->textures[4].bpp, &data->textures[4].l, &data->textures[4].endian);
	data->textures[5].mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./src/textures/pillar.xpm", &width, &height);
	data->textures[5].addr = mlx_get_data_addr(data->textures[5].mlx_img, &data->textures[5].bpp, &data->textures[5].l, &data->textures[5].endian);
	data->textures[6].mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./src/textures/mossy.xpm", &width, &height);
	data->textures[6].addr = mlx_get_data_addr(data->textures[6].mlx_img, &data->textures[6].bpp, &data->textures[6].l, &data->textures[6].endian);
	return (0);
}
