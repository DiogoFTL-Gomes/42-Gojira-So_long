/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:11:22 by darkless12        #+#    #+#             */
/*   Updated: 2025/02/17 16:34:26 by darkless12       ###   ########.fr       */
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
	all->game.nuke = 0;
	all->game.dir = 0;
	all->game.x = 0;
	all->game.y = 0;
	all->game.moves = 0;
	all->mlx.ptr = NULL;
	all->mlx.win = NULL;
	all->mlx.addr = NULL;
	all->mlx.img = NULL;
	all->mlx.bpp = 0;
	all->mlx.endian = 0;
	all->mlx.line = 0;
	return (0);
}

int	init_each_tile(t_tile *tile, int nbr)
{
	int i;

	i = 0;
	while (i < nbr)
	{
		tile[i].addr = NULL;
		tile[i].img = NULL;
		tile[i].line = 0;
		tile[i].endian = 0;
		tile[i].x = 0;
		tile[i].y = 0;
		tile[i].bpp = 0;
		i++;
	}
	return (0);
}

int	init_tiles(t_all *all)
{
	init_each_tile(all->floor, 6);
	init_each_tile(all->nuke, 2);
	init_each_tile(all->gojira, 4);
	init_each_tile(all->wall, 3);
	init_each_tile(&all->exit, 1);
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
