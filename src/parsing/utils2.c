/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:51:31 by educlos           #+#    #+#             */
/*   Updated: 2024/02/12 13:53:17 by educlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_only_space(char *str, int index)
{
	while (str[index] != '\0')
	{
		if (str[index] != 32)
			return (-1);
		index++;
	}
	return (1);
}

char	*get_nmalloc(char *str, int start, int end)
{
	char	*dest;
	int		i;

	if (str[start] == 0)
		return (NULL);
	i = 0;
	if (!str)
		return (NULL);
	dest = malloc(sizeof(char *) * end - start + 1);
	if (!dest)
		return (NULL);
	while (start != end)
	{
		dest[i++] = str[start++];
	}
	dest[i] = '\0';
	return (dest);
}
