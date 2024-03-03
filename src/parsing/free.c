/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:13:50 by educlos           #+#    #+#             */
/*   Updated: 2024/03/03 09:52:48 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_double_array(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i] != 0)
	{
		if (str[i] != NULL)
			free(str[i]);
		i++;
	}
	free(str);
}

void	free_double_array_dest(char **str, int index_max)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (i < index_max)
	{
		if (str[i] != NULL)
			free(str[i]);
		i++;
	}
	free(str);
}

void	free_list(t_pos **pos)
{
	t_pos	*tmp;
	t_pos	*tmp2;

	if (!pos)
		return ;
	tmp = *pos;
	while (tmp != NULL)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		if (tmp2->range != NULL)
			free(tmp2->range);
		free(tmp2->arg);
		free(tmp2);
	}
	*pos = NULL;
}

void	free_structs(t_parsing *p)
{
	int	i;

	if (p->map != NULL)
		free_double_array(p->map);
	if (p->_map != NULL)
	{
		i = 0;
		while (p->_map[i] != 0)
		{
			free(p->_map[i]);
			i++;
		}
		free(p->_map);
	}
	if (p->pos != NULL)
		free_list(&p->begin);
	free(p);
}

void	free_map(t_map *m)
{
	free_double_array(m->_map);
	free(m);
}
