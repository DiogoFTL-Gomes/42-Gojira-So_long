/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:33:05 by darkless12        #+#    #+#             */
/*   Updated: 2025/01/30 21:07:35 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//verificar se dados do mapa são validos;
int	check_data(t_all *all)
{
	int	errors;

	errors = 0;
	if (all->plan.player != 1)
		errors += got_error("Map needs only 1 player");
	if (all->plan.colect < 1)
		errors += got_error("Map must have at least 1 collectible");
	if (all->plan.exit != 1)
		errors += got_error("Map must have just 1 exit");
	if (all->plan.cols * all->plan.rows < 15)
		errors += got_error("Map area is too small");
	if (all->plan.cols < 3 || all->plan.rows < 3)
		errors += got_error("Map has too few lines/columns");
	return (errors);
}
//verificar tamanho das linhas, encontrar nº cols, verificar se é rectangulo
int	check_line(t_all *all, char *line)
{
	char *tmp;
	int	 i;

	tmp = "01CPE";
	if (all->plan.cols == 0)
		all->plan.cols = ft_strlen(line);
	else if (all->plan.cols != (int)ft_strlen(line))
		return (got_error("Map is not a rectangle"));
	all->plan.rows++;
	while (*line != 0 && *line != '\n')
	{
		i = 0;
		if (*line == 'P')
			all->plan.player++;
		else if (*line == 'C')
			all->plan.colect++;
		else if (*line == 'E')
			all->plan.exit++;
		while (tmp[i] != 0 && *line != tmp[i])
			i++;
		if (tmp[i] == 0)
			return (got_error("Map has invalid characters"));
		line++;
	}
	return (check_data(all));
}

//limita-se a encontrar o ficheiro e a contar as linhas e colunas
int	check_file(t_all *all, char *fname)
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
			check_line(all, line);
	}
	close(fd);
	return (check_line(all, line));
}

//verifica se o nome termina em .ber
int	check_file_name(t_all *all, char *fname)
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
	return (check_file(all, fname));
}
