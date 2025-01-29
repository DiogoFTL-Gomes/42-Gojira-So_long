/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:18:53 by darkless12        #+#    #+#             */
/*   Updated: 2025/01/29 14:01:20 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

//limita-se a encontrar o ficheiro e a contar as linhas e colunas
int	find_file(t_all *all, char *fname)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	line = ft_strjoin("maps/", fname);
	fd = open(line, O_RDONLY);
	free(line);
	if (fd < 0)
		return (0);
	while (line != NULL || i == 0)
	{
		if (line)
			free(line);
		line = get_next_line(fd);
		if (i == 0 && line != NULL)
			all->map.cols = ft_strlen(line);
		i++;
		all->map.rows++;
	}
	close(fd);
	return (1);
}

//chama funcoes que carregam o mapa
int	map_loader(t_all *all, char *fname)
{
	if (!(check_name(fname)))
		return (0);
	if (!(find_file(all, fname)))
		return (0);
	return (1);
}