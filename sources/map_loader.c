/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:18:53 by darkless12        #+#    #+#             */
/*   Updated: 2025/02/11 16:24:29 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//carregar *.ber para a struct do mapa
int	load_map(t_all *all, char *fname)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	line = ft_strjoin("maps/", fname);
	fd = open(line, O_RDONLY);
	if (fd < 0)
		return (got_error("File not found"));
	free(line);
	all->plan.map = malloc(sizeof(char *) * (all->plan.row + 1));
	if (!all->plan.map)
		return (got_error("Map array failed to initialize"));
	all->plan.map[all->plan.row] = 0;
	while (i < all->plan.row)
	{
		all->plan.map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	// for (int i = 0; i < all->plan.rows; i++)	//isto tem que sair
	// 	printf("%s", all->plan.map[i]);			//isto tb
	// printf("\n");								//isto tb
	return (0);
}

//chama funcoes que carregam o mapa
int	map_loader(t_all *all, char *fname)
{
	if (check_file_name(all, fname))
		return (1);
	if (load_map(all, fname))
		return (1);
	if (check_nav(all))
		return (1);
	return (0);
}
