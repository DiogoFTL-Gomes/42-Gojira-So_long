/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiogo-f <ddiogo-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:21:47 by darkless12        #+#    #+#             */
/*   Updated: 2025/02/19 10:20:27 by ddiogo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//loading floor images files to mem
void	load_floor(t_all *all)
{
	all->floor[0].img = mlx_xpm_file_to_image(all->mlx.ptr, \
		"tiles/city_a.xpm", &all->floor[0].x, &all->floor[0].y);
	all->floor[0].addr = mlx_get_data_addr(all->floor[0].img, \
		&all->floor[0].bpp, &all->floor[0].line, &all->floor[0].endian);
	all->floor[1].img = mlx_xpm_file_to_image(all->mlx.ptr, \
		"tiles/city_b.xpm", &all->floor[1].x, &all->floor[1].y);
	all->floor[1].addr = mlx_get_data_addr(all->floor[1].img, \
		&all->floor[1].bpp, &all->floor[1].line, &all->floor[1].endian);
	all->floor[2].img = mlx_xpm_file_to_image(all->mlx.ptr, \
		"tiles/city_c.xpm", &all->floor[2].x, &all->floor[2].y);
	all->floor[2].addr = mlx_get_data_addr(all->floor[2].img, \
		&all->floor[2].bpp, &all->floor[2].line, &all->floor[2].endian);
	all->floor[3].img = mlx_xpm_file_to_image(all->mlx.ptr, \
		"tiles/city_d_a.xpm", &all->floor[3].x, &all->floor[3].y);
	all->floor[3].addr = mlx_get_data_addr(all->floor[3].img, \
		&all->floor[3].bpp, &all->floor[3].line, &all->floor[3].endian);
	all->floor[4].img = mlx_xpm_file_to_image(all->mlx.ptr, \
		"tiles/city_d_b.xpm", &all->floor[4].x, &all->floor[4].y);
	all->floor[4].addr = mlx_get_data_addr(all->floor[4].img, \
		&all->floor[4].bpp, &all->floor[4].line, &all->floor[4].endian);
	all->floor[5].img = mlx_xpm_file_to_image(all->mlx.ptr, \
		"tiles/city_d_c.xpm", &all->floor[5].x, &all->floor[5].y);
	all->floor[5].addr = mlx_get_data_addr(all->floor[5].img, \
		&all->floor[5].bpp, &all->floor[5].line, &all->floor[5].endian);
}

//loading scraper images files to mem
void	load_scraper(t_all *all)
{
	all->wall[0].img = mlx_xpm_file_to_image(all->mlx.ptr, \
		"tiles/scraper_a.xpm", &all->wall[0].x, &all->wall[0].y);
	all->wall[0].addr = mlx_get_data_addr(all->wall[0].img, \
		&all->wall[0].bpp, &all->wall[0].line, &all->wall[0].endian);
	all->wall[1].img = mlx_xpm_file_to_image(all->mlx.ptr, \
		"tiles/scraper_b.xpm", &all->wall[1].x, &all->wall[1].y);
	all->wall[1].addr = mlx_get_data_addr(all->wall[1].img, \
		&all->wall[1].bpp, &all->wall[1].line, &all->wall[1].endian);
	all->wall[2].img = mlx_xpm_file_to_image(all->mlx.ptr, \
		"tiles/scraper_c.xpm", &all->wall[2].x, &all->wall[2].y);
	all->wall[2].addr = mlx_get_data_addr(all->wall[2].img, \
		&all->wall[2].bpp, &all->wall[2].line, &all->wall[2].endian);
}

//loading nuke & exit images files to mem
void	load_nuke_exit(t_all *all)
{
	all->nuke[0].img = mlx_xpm_file_to_image(all->mlx.ptr, \
		"tiles/nuke.xpm", &all->nuke[0].x, &all->nuke[0].y);
	all->nuke[0].addr = mlx_get_data_addr(all->nuke[0].img, \
		&all->nuke[0].bpp, &all->nuke[0].line, &all->nuke[0].endian);
	all->nuke[1].img = mlx_xpm_file_to_image(all->mlx.ptr, \
		"tiles/nuke_d.xpm", &all->nuke[1].x, &all->nuke[1].y);
	all->nuke[1].addr = mlx_get_data_addr(all->nuke[1].img, \
		&all->nuke[1].bpp, &all->nuke[1].line, &all->nuke[1].endian);
	all->exit.img = mlx_xpm_file_to_image(all->mlx.ptr, \
		"tiles/exit.xpm", &all->exit.x, &all->exit.y);
	all->exit.addr = mlx_get_data_addr(all->exit.img, &all->exit.bpp, \
		&all->exit.line, &all->exit.endian);
}

void	load_gojira(t_all *all)
{
	all->gojira[0].img = mlx_xpm_file_to_image(all->mlx.ptr, \
		"tiles/gojira_l.xpm", &all->gojira[0].x, &all->gojira[0].y);
	all->gojira[0].addr = mlx_get_data_addr(all->gojira[0].img, \
		&all->gojira[0].bpp, &all->gojira[0].line, &all->gojira[0].endian);
	all->gojira[1].img = mlx_xpm_file_to_image(all->mlx.ptr, \
		"tiles/gojira_r.xpm", &all->gojira[1].x, &all->gojira[1].y);
	all->gojira[1].addr = mlx_get_data_addr(all->gojira[1].img, \
		&all->gojira[1].bpp, &all->gojira[1].line, &all->gojira[1].endian);
	all->gojira[2].img = mlx_xpm_file_to_image(all->mlx.ptr, \
		"tiles/gojira_u.xpm", &all->gojira[2].x, &all->gojira[2].y);
	all->gojira[2].addr = mlx_get_data_addr(all->gojira[2].img, \
		&all->gojira[2].bpp, &all->gojira[2].line, &all->gojira[2].endian);
	all->gojira[3].img = mlx_xpm_file_to_image(all->mlx.ptr, \
		"tiles/gojira_d.xpm", &all->gojira[3].x, &all->gojira[3].y);
	all->gojira[3].addr = mlx_get_data_addr(all->gojira[3].img, \
		&all->gojira[3].bpp, &all->gojira[3].line, &all->gojira[3].endian);
}

//chamando functions that load images to mem
void	load_textures(t_all *all)
{
	load_floor(all);
	load_scraper(all);
	load_nuke_exit(all);
	load_gojira(all);
}
