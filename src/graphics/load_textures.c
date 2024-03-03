/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:16:23 by mle-duc           #+#    #+#             */
/*   Updated: 2024/03/03 09:23:54 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_north(t_data *data, t_parsing *p)
{
	int		width;
	int		height;
	t_pos	*tmp;
	char	*path;

	tmp = p->pos;
	path = NULL;
	while (tmp != NULL)
	{
		if (strcmp("NO ", tmp->value) == 0)
		{
			path = tmp->arg;
			break ;
		}
		tmp = tmp->next;
	}
	data->textures[0].mlx_img = \
	mlx_xpm_file_to_image(data->mlx_ptr, path, &width, &height);
	if (data->textures[0].mlx_img == NULL)
		handle_wrong_path(data, p);
	data->textures[0].tex_height = height;
	data->textures[0].tex_width = width;
	data->textures[0].addr = mlx_get_data_addr(data->textures[0].mlx_img, \
	&data->textures[0].bpp, &data->textures[0].l, &data->textures[0].endian);
}

void	load_south(t_data *data, t_parsing *p)

{
	int		width;
	int		height;
	t_pos	*tmp;
	char	*path;

	tmp = p->pos;
	path = NULL;
	while (tmp != NULL)
	{
		if (strcmp("SO ", tmp->value) == 0)
		{
			path = tmp->arg;
			break ;
		}
		tmp = tmp->next;
	}
	data->textures[1].mlx_img = \
	mlx_xpm_file_to_image(data->mlx_ptr, path, &width, &height);
	if (data->textures[1].mlx_img == NULL)
		handle_wrong_path(data, p);
	data->textures[1].tex_height = height;
	data->textures[1].tex_width = width;
	data->textures[1].addr = mlx_get_data_addr(data->textures[1].mlx_img, \
	&data->textures[1].bpp, &data->textures[1].l, &data->textures[1].endian);
}

void	load_east(t_data *data, t_parsing *p)

{
	int		width;
	int		height;
	t_pos	*tmp;
	char	*path;

	tmp = p->pos;
	path = NULL;
	while (tmp != NULL)
	{
		if (strcmp("EA ", tmp->value) == 0)
		{
			path = tmp->arg;
			break ;
		}
		tmp = tmp->next;
	}
	data->textures[3].mlx_img = \
	mlx_xpm_file_to_image(data->mlx_ptr, path, &width, &height);
	if (data->textures[3].mlx_img == NULL)
		handle_wrong_path(data, p);
	data->textures[3].tex_height = height;
	data->textures[3].tex_width = width;
	data->textures[3].addr = mlx_get_data_addr(data->textures[3].mlx_img, \
	&data->textures[3].bpp, &data->textures[3].l, &data->textures[3].endian);
}

void	load_west(t_data *data, t_parsing *p)
{
	int		width;
	int		height;
	t_pos	*tmp;
	char	*path;

	tmp = p->pos;
	path = NULL;
	while (tmp != NULL)
	{
		if (strcmp("WE ", tmp->value) == 0)
		{
			path = tmp->arg;
			break ;
		}
		tmp = tmp->next;
	}
	data->textures[2].mlx_img = \
	mlx_xpm_file_to_image(data->mlx_ptr, path, &width, &height);
	if (data->textures[2].mlx_img == NULL)
		handle_wrong_path(data, p);
	data->textures[2].tex_height = height;
	data->textures[2].tex_width = width;
	data->textures[2].addr = mlx_get_data_addr(data->textures[2].mlx_img, \
	&data->textures[2].bpp, &data->textures[2].l, &data->textures[2].endian);
}
