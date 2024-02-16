/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:02:34 by mle-duc           #+#    #+#             */
/*   Updated: 2023/06/06 17:19:25 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ret;
	int		i;

	if (!s)
		return (0);
	i = 0;
	ret = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ret)
		return (0);
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
