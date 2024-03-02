/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:08:32 by mle-duc           #+#    #+#             */
/*   Updated: 2024/03/02 21:20:37 by mle-duc          ###   ########.fr       */
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

void	load_north(t_data *data, t_parsing *p)
{
	int	width;
	int	height;
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
	data->textures[0].mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, path, &width, &height);
	if (data->textures[0].mlx_img == NULL)
		handle_wrong_path(data, p);
	data->textures[0].addr = mlx_get_data_addr(data->textures[0].mlx_img, \
	&data->textures[0].bpp, &data->textures[0].l, &data->textures[0].endian);
}

void	load_south(t_data *data, t_parsing *p)

{
	int	width;
	int	height;
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
	data->textures[1].mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, path, &width, &height);
	if (data->textures[1].mlx_img == NULL)
		handle_wrong_path(data, p);
	data->textures[1].addr = mlx_get_data_addr(data->textures[1].mlx_img, \
	&data->textures[1].bpp, &data->textures[1].l, &data->textures[1].endian);
}

void	load_east(t_data *data, t_parsing *p)

{
	int	width;
	int	height;
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
	data->textures[2].mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, path, &width, &height);
	if (data->textures[2].mlx_img == NULL)
		handle_wrong_path(data, p);
	data->textures[2].addr = mlx_get_data_addr(data->textures[2].mlx_img, \
	&data->textures[2].bpp, &data->textures[2].l, &data->textures[2].endian);
}

void	load_west(t_data *data, t_parsing *p)
{
	int	width;
	int	height;
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
	data->textures[3].mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, path, &width, &height);
	if (data->textures[3].mlx_img == NULL)
		handle_wrong_path(data, p);
	data->textures[3].addr = mlx_get_data_addr(data->textures[3].mlx_img, \
	&data->textures[3].bpp, &data->textures[3].l, &data->textures[3].endian);
}

int	load_textures(t_data *data, t_parsing *p)
{
	//int	width;
	//int	height;

	load_north(data, p);
	load_south(data, p);
	load_east(data, p);
	load_west(data, p);
	/*
	data->textures[1].addr = mlx_get_data_addr(data->textures[1].mlx_img, &data->textures[1].bpp, &data->textures[1].l, &data->textures[1].endian);
	data->textures[2].mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./src/textures/colorstone.xpm", &width, &height);
	data->textures[2].addr = mlx_get_data_addr(data->textures[2].mlx_img, &data->textures[2].bpp, &data->textures[2].l, &data->textures[2].endian);
	data->textures[3].mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./src/textures/eagle.xpm", &width, &height);
	data->textures[3].addr = mlx_get_data_addr(data->textures[3].mlx_img, &data->textures[3].bpp, &data->textures[3].l, &data->textures[3].endian);
	*/
	return (0);
}
