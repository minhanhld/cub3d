/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:50:11 by educlos           #+#    #+#             */
/*   Updated: 2024/03/11 15:00:52 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	skip_space(char *str, int i)
{
	if (!str)
		return (-1);
	while (str[i] == 32 && str[i] != '\0')
		i++;
	return (i);
}

int	ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			if (to_find[j + 1] == '\0')
			{
				return (i);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

int	ft_strlen_double(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != 0)
		i++;
	return (i);
}
