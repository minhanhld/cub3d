/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:08:32 by mle-duc           #+#    #+#             */
/*   Updated: 2024/03/03 09:20:28 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	clear(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
}

void	handle_wrong_path(t_data *data, t_parsing *p)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (data->textures[i].mlx_img != NULL)
			mlx_destroy_image(data->mlx_ptr, data->textures[i].mlx_img);
	}
	clear(data);
	free_structs(p);
	exit(1);
}

int	load_textures(t_data *data, t_parsing *p)
{
	load_north(data, p);
	load_south(data, p);
	load_east(data, p);
	load_west(data, p);
	return (0);
}
