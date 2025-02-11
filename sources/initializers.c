/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:11:22 by darkless12        #+#    #+#             */
/*   Updated: 2025/02/11 20:37:15 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//inicia a struct do mapa
int	init_map(t_all *all)
{
	all->plan.map = NULL;
	all->plan.row = 0;
	all->plan.col = 0;
	all->plan.player = 0;
	all->plan.colect = 0;
	all->plan.exit = 0;
	return (0);
}

//inicia struct do mlx
int	init_game_graph(t_all *all)
{
	all->game.last = 0;
	all->game.nuke = 0;
	all->game.x = 0;
	all->game.y = 0;
	all->mlx.ptr = NULL;
	all->mlx.win = NULL;
	all->mlx.addr = NULL;
	all->mlx.img = NULL;
	all->mlx.bpp = 0;
	all->mlx.endian = 0;
	all->mlx.line = 0;
	return (0);
}

int	init_each_tile(t_tile *tile)
{
	tile->addr = NULL;
	tile->img = NULL;
	tile->l = 0;
	tile->h = 0;
	tile->bpp = 0;
	return (0);
}

int	init_tiles(t_all *all)
{
	init_each_tile(&all->exit);
	init_each_tile(&all->floor);
	init_each_tile(&all->nuke);
	init_each_tile(&all->godjira);
	init_each_tile(&all->wall);
	return (0);
}

//chama funcoes que iniciam structs essenciais
int	init_all(t_all *all)
{
	if (init_map(all))
		return (got_error("Map struct failed to initialize\n"));
	if (init_game_graph(all))
		return (got_error("Render struct failed to initialize\n"));
	if (init_tiles(all))
		return (got_error("Tile structs failed to initialize\n"));
	return (0);
}
