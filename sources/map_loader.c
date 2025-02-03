/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:18:53 by darkless12        #+#    #+#             */
/*   Updated: 2025/02/03 21:13:58 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//check borders of map copy
int	check_border(char **copy)
{
	int	i;

	i = 0;
	
}

//copy map to check borders & navigation
int	check_map(t_all *all)
{
	char	**copy;
	int		i;
	int		j;

	copy = malloc(sizeof(char *) * (all->plan.rows + 1));
	if (!copy)
		return (got_error("Failed malloc of array copy"));
	copy[all->plan.rows] = 0;
	i = 0;
	while (i < all->plan.rows)
	{
		copy[i] = malloc(sizeof(char) * (all->plan.cols + 1));
		if (!copy[i])
			return (got_error("Failed malloc of array line copy"));
		j = 0;
		while (j < all->plan.cols)
			copy[i][j] = all->plan.map[i][j++];
		copy[i][j] = 0;
		i++;
	}
	return (check_border(copy));
}

//carregar *.ber para a struct do mapa
int	load_map(t_all *all, char *fname)
{
	int		fd;
	char	*line;
	int		i;

	printf("loading");
	i = 0;
	line = ft_strjoin("maps/", fname);
	fd = open(line, O_RDONLY);
	if (fd < 0)
		return (got_error("File not found"));
	free(line);
	all->plan.map = malloc(sizeof(char *) * (all->plan.rows + 1));
	if (!all->plan.map)
		return (got_error("Map array failed to initialize"));
	all->plan.map[all->plan.rows] = 0;
	while (i < all->plan.rows)
	{
		all->plan.map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}

//chama funcoes que carregam o mapa
int	map_loader(t_all *all, char *fname)
{
	if (check_file_name(all, fname))
		return (1);
	if (check_map(all))
		return (1);
	// if (load_map(all, fname))
	// 	return (1);
	return (0);
}
