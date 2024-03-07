/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:29:02 by mle-duc           #+#    #+#             */
/*   Updated: 2024/03/07 16:44:20 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (keysym == XK_Left)
		data->left_key = 1;
	else if (keysym == XK_Right)
		data->right_key = 1;
	else if (keysym == XK_w)
		data->w_key = 1;
	else if (keysym == XK_s)
		data->s_key = 1;
	else if (keysym == XK_a)
		data->a_key = 1;
	else if (keysym == XK_d)
		data->d_key = 1;
	return (0);
}

int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == XK_Left)
		data->left_key = 0;
	else if (keysym == XK_Right)
		data->right_key = 0;
	else if (keysym == XK_w)
		data->w_key = 0;
	else if (keysym == XK_s)
		data->s_key = 0;
	else if (keysym == XK_a)
		data->a_key = 0;
	else if (keysym == XK_d)
		data->d_key = 0;
	return (0);
}

int	cross(t_data *data)
{
	destroy_textures(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	free_structs(data->parsing);
	free(data->mlx_ptr);
	free(data);
	exit(0);
}
