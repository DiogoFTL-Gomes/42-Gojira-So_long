/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:21:47 by darkless12        #+#    #+#             */
/*   Updated: 2025/02/11 20:37:10 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//loading image files to mem
void	load_floor(t_all *all)
{
	all->floor.img = mlx_xpm_file_to_image(all->mlx.ptr, \
		"tiles/city_a.xpm", &all->floor.l, &all->floor.h);
	all->floor.addr = mlx_get_data_addr(all->floor.img, &all->floor.bpp, \
		&all->floor.l, &all->floor.endian);
}

//chamando functions that load images to mem
void	load_textures(t_all *all)
{
	load_floor(all);
	/*all->wall.img = mlx_xpm_file_to_image(all->graph.mlx, \
		"tiles/scraper_a.xpm", 64, 80);
	all->player.img = mlx_xpm_file_to_image(all->graph.mlx, \
		"tiles/godjira_l.xpm", 64, 80);
	all->exit.img = mlx_xpm_file_to_image(all->graph.mlx, \
		"tiles/scraper_b.xpm", 64, 80);
	all->nuke.img = mlx_xpm_file_to_image(all->graph.mlx, \
		"tiles/scraper_c.xpm", 64, 80);*/
}