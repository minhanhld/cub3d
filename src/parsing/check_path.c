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

int	check_nb_between_comma(char *str, int i)
{
	if (!str)
		return (-1);
	while (str[i] != ',' && str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (1);
		i++;
	}
	return (-1);
}

int	recursive(t_pos *pos, char *str, int c)
{
	int	i;
	int	result;

	i = 0;
	while (str[i] != '\0')
	{
		i = skip_space(str, i);
		result = 0;
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
			result = result * 10 + (str[i++] - 48);
		if (result > 255 || result < 0)
			return (-1);
		pos->range[c++] = result;
		i = skip_space(str, i);
		if (str[i] != ',' && str[i] != '\0')
			return (-1);
		if (str[i] != '\0')
			i++;
	}
	if (c != 3)
		return (-1);
	return (1);
}

int	check_range(t_pos *pos, char *str)
{
	pos->range = malloc(sizeof(int) * 3);
	if (!pos->range)
		return (-1);
	if (recursive(pos, str, 0) == -1)
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
