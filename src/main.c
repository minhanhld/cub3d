/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:19:44 by educlos           #+#    #+#             */
/*   Updated: 2024/03/11 14:56:25 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cub3d.h"

int	init_pstruct(t_parsing *p)
{
	p->lcount = 0;
	p->map = NULL;
	p->pos = NULL;
	p->_map = NULL;
	return (1);
}

char	*file_cpy(char *dest, char *str)
{
	char	*tmp;

	if (!dest)
		return (dest = strdup(str));
	tmp = ft_strjoin(dest, str);
	if (!tmp)
		return (NULL);
	return (tmp);
}

int	parsing(t_parsing *p, int fd)
{
	char	*str;
	char	*dest;

	dest = NULL;
	while (-1)
	{
		p->lcount++;
		str = get_next_line(fd);
		if (!str)
			break ;
		dest = file_cpy(dest, str);
		free(str);
	}
	if (!dest)
		return (-1);
	if (get_config(p, dest) == -1)
		return (-1);
	if (parsing_map(p) == -1)
		return (-2);
	return (1);
}

int	error_handling(t_parsing *p, char **argv, int fd)
{
	int	error;

	if (fd == -1 || ft_check_format(argv[1], ".cub") == -1)
	{
		free_structs(p);
		printf("%sError\nFile:%s Wrong%s\n", RED, argv[1], RESET);
		return (-1);
	}
	error = parsing(p, fd);
	if (error != 1)
	{
		if (error == -2)
			printf("%sError\nInvalid map format%s\n", RED, RESET);
		else
			printf("%sError\nInvalid settings(textures, ceiling, floor...) (%s\n", RED, RESET);
		free_structs(p);
		return (-1);
	}
	return (0);
}

int	main(int ac, char **argv)
{
	int			fd;
	t_parsing	*p;

	if (ac != 2)
	{
		printf("usage: ./cub3D map.cub\n");
		return (-1);
	}
	p = malloc(sizeof(t_parsing));
	if (!p)
		return (-1);
	init_pstruct(p);
	fd = open(argv[1], O_RDONLY);
	if (error_handling(p, argv, fd) == -1)
		return (-1);
	cub3d(p);
	free_structs(p);
}
