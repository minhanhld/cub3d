/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:53:39 by mle-duc           #+#    #+#             */
/*   Updated: 2024/03/03 09:53:39 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	recursive(t_pos *pos, char *str)
{
	int i;
	int result;
	int c;

	i = 0;
	c = 0;
	while(str[i] != '\0')
	{
		i = skip_space(str,i);
		result = 0;
		while (str[i] != ',' && str[i] != '\0')
		{
			if (c == 3)
				return (-1);
			if (str[i] < '0' || str[i] > '9')
			{
				return (-1);
			}
			result = result * 10 + (str[i] - 48);
			i++;
		}
		if (result > 255 || result < 0)
		{	
			return (-1);
		}	
		pos->range[c] = result;
		c++;
		i++;
	}
	return (1);
}

int	check_range(t_pos *pos, char *str)
{
	pos->range = malloc(sizeof(int) * 3);
	if (!pos->range)
		return (-1);
	if (recursive(pos, str) == -1)
		return (-1);
	return (0);
}

int	check_path(t_pos *pos)
{
	t_pos	*current;
	int		fd;

	current = pos;
	while (current != NULL)
	{
		fd = open(current->arg, O_RDONLY);
		if (current->value[0] == 'F' || current->value[0] == 'C')
		{
			if (check_range(current, current->arg) == -1)
				return (-1);
		}
		else if (fd == -1)
		{
			return (-1);
		}
		current = current->next;
	}
	return (1);
}
