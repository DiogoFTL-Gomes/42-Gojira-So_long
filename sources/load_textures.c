/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:21:47 by darkless12        #+#    #+#             */
/*   Updated: 2025/02/16 22:51:21 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//loading floor images files to mem
void	load_floor(t_all *all)
{
	all->floor[0].img = mlx_xpm_file_to_image(all->mlx.ptr, \
		"tiles/city_a.xpm", &all->floor[0].x, &all->floor[0].y);
	all->floor[0].addr = mlx_get_data_addr(all->floor[0].img, &all->floor[0].bpp, \
		&all->floor[0].line, &all->floor[0].endian);
	all->floor[1].img = mlx_xpm_file_to_image(all->mlx.ptr, \
		"tiles/city_b.xpm", &all->floor[1].x, &all->floor[1].y);
	all->floor[1].addr = mlx_get_data_addr(all->floor[1].img, &all->floor[1].bpp, \
		&all->floor[1].line, &all->floor[1].endian);
	all->floor[2].img = mlx_xpm_file_to_image(all->mlx.ptr, \
		"tiles/city_c.xpm", &all->floor[2].x, &all->floor[2].y);
	all->floor[2].addr = mlx_get_data_addr(all->floor[2].img, &all->floor[2].bpp, \
		&all->floor[2].line, &all->floor[2].endian);
}

//loading scraper images files to mem
void	load_scraper(t_all *all)
{
	all->wall[0].img = mlx_xpm_file_to_image(all->mlx.ptr, \
		"tiles/scraper_a.xpm", &all->wall[0].x, &all->wall[0].y);
	all->wall[0].addr = mlx_get_data_addr(all->wall[0].img, &all->wall[0].bpp, \
		&all->wall[0].line, &all->wall[0].endian);
	all->wall[1].img = mlx_xpm_file_to_image(all->mlx.ptr, \
		"tiles/scraper_b.xpm", &all->wall[1].x, &all->wall[1].y);
	all->wall[1].addr = mlx_get_data_addr(all->wall[1].img, &all->wall[1].bpp, \
		&all->wall[1].line, &all->wall[1].endian);
	all->wall[2].img = mlx_xpm_file_to_image(all->mlx.ptr, \
		"tiles/scraper_c.xpm", &all->wall[2].x, &all->wall[2].y);
	all->wall[2].addr = mlx_get_data_addr(all->wall[2].img, &all->wall[2].bpp, \
		&all->wall[2].line, &all->wall[2].endian);
}

//loading nuke & exit images files to mem
void	load_nuke_exit(t_all *all)
{
	all->nuke[0].img = mlx_xpm_file_to_image(all->mlx.ptr, \
		"tiles/nuke.xpm", &all->nuke[0].x, &all->nuke[0].y);
	all->nuke[0].addr = mlx_get_data_addr(all->nuke[0].img, &all->nuke[0].bpp, \
		&all->nuke[0].line, &all->nuke[0].endian);
	all->nuke[1].img = mlx_xpm_file_to_image(all->mlx.ptr, \
		"tiles/nuke_d.xpm", &all->nuke[1].x, &all->nuke[1].y);
	all->nuke[1].addr = mlx_get_data_addr(all->nuke[1].img, &all->nuke[1].bpp, \
		&all->nuke[1].line, &all->nuke[1].endian);
}
//chamando functions that load images to mem
void	load_textures(t_all *all)
{
	load_floor(all);
	load_scraper(all);
	load_nuke_exit(all);
	/*all->player.img = mlx_xpm_file_to_image(all->graph.mlx, \
		"tiles/godjira_l.xpm", 64, 80);
	all->exit.img = mlx_xpm_file_to_image(all->graph.mlx, \
		"tiles/scraper_b.xpm", 64, 80);
	all->nuke.img = mlx_xpm_file_to_image(all->graph.mlx, \
		"tiles/scraper_c.xpm", 64, 80);*/
}