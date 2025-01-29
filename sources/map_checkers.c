/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:33:05 by darkless12        #+#    #+#             */
/*   Updated: 2025/01/29 15:34:58 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//limita-se a encontrar o ficheiro e a contar as linhas e colunas
int	check_fname(t_all *all, char *fname)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	line = ft_strjoin("maps/", fname);
	fd = open(line, O_RDONLY);
	if (fd < 0)
	{
		free(line);
		return (got_error("File not found"));
	}
	while (line != NULL || i == 0)
	{
		if (line)
			free(line);
		line = get_next_line(fd);
		if (i++ == 0 || line != NULL)
		{
			all->map.cols = ft_strlen(line);
			all->map.rows++;
		}
	}
	close(fd);
	return (1);
}

//verifica se o nome termina em .ber
int	check_name(char *fname)
{
	char	*ext;
	int		i;
	int		j;

	ext = ".ber";
	i = 0;
	j = 0;
	while (fname[i] != 0)
		i++;
	while (j < 4 )
	{
		if (fname[i - 4] != ext[j] || i < 5)
			return (got_error("File extension must be .ber"));
		j++;
		i++;
	}
	return (1);
}
