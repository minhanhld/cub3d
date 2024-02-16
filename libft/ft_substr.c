/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:03:36 by mle-duc           #+#    #+#             */
/*   Updated: 2022/11/11 15:10:23 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	getsize(char const *s, unsigned int start, size_t len)
{
	size_t	size;

	size = 0;
	while (size < len && start < ft_strlen(s) && s[size + start])
		size++;
	return (size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	size;

	if (!s)
		return (0);
	size = getsize(s, start, len);
	ret = malloc (sizeof(char) *(size + 1));
	if (!ret)
		return (0);
	i = 0;
	while (i < len && start < ft_strlen(s) && s[i + start])
	{
		ret[i] = s[start + (unsigned int)i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
