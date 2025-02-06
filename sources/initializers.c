/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:11:22 by darkless12        #+#    #+#             */
/*   Updated: 2025/02/06 14:42:55 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//inicia a struct do mapa
int	init_map(t_all *all)
{
	all->plan.map = NULL;
	all->plan.rows = 0;
	all->plan.cols = 0;
	all->plan.player = 0;
	all->plan.colect = 0;
	all->plan.exit = 0;
	return (0);
}

//inicia struct do mlx
int	init_graph(t_all *all)
{
	all->graph.mlx = NULL;
	all->graph.win = NULL;
	return (0);
}
int	init_each_tile(t_tile *tile)
{
	tile->addr = NULL;
	tile->img = NULL;
	return (0);
}

int	init_tiles(t_all *all)
{
	init_each_tile(&all->exit);
	init_each_tile(&all->floor);
	init_each_tile(&all->nuke);
	init_each_tile(&all->player);
	init_each_tile(&all->wall);
	return (0);
}

//chama funcoes que iniciam structs essenciais
int	init_all(t_all *all)
{
	if (init_map(all))
		return (got_error("Map struct failed to initialize\n"));
	if (init_graph(all))
		return (got_error("Render struct failed to initialize\n"));
	if (init_tiles(all))
		return (got_error("Tile structs failed to initialize\n"));
	return (0);
}
