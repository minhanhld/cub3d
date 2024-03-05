/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:53:01 by mle-duc           #+#    #+#             */
/*   Updated: 2024/03/05 15:08:56 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	get_player_all(t_parsing *p, t_map *m)
{
	int	i;
	int	y;

	i = 0;
	while (m->_map[i] != 0)
	{
		y = 0;
		while (m->_map[i][y] != '\0')
		{
			if (m->_map[i][y] == 'N' || m->_map[i][y] == 'S' \
				|| m->_map[i][y] == 'E' || m->_map[i][y] == 'W')
			{
				p->_player_d = m->_map[i][y];
				p->_player_x = y;
				p->_player_y = i;
				m->_map[i][y] = '0';
			}
			y++;
		}
		i++;
	}
	return ;
}

void	convert_map_int(t_parsing *p, t_map *m)
{
	int	x;
	int	y;

	y = 0;
	p->_map = malloc(sizeof(int *) * (m->_last - m->_first + 1));
	if (!p->_map)
		return ;
	while (m->_map[y] != 0)
	{
		x = 0;
		p->_map[y] = malloc(sizeof(int) * ft_strlen(m->_map[y]));
		if (!p->_map[y])
			return ;
		while (m->_map[y][x] != '\0')
		{
			p->_map[y][x] = m->_map[y][x] - 48;
			if (m->_map[y][x] == 32)
				p->_map[y][x] = 0;
			x++;
		}
		y++;
	}
	p->_map[y] = 0;
}

void	struct_parsing(t_parsing *p, t_map *m)
{
	get_player_all(p, m);
	convert_map_int(p, m);
}
