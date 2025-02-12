/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:33:55 by darkless12        #+#    #+#             */
/*   Updated: 2025/02/12 15:44:28 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_it(int keycode, t_all *all)
{
	if (keycode == 0xff1b)
	{
		//destruir aqui imagens
		mlx_destroy_window(all->mlx.ptr, all->mlx.win);
		mlx_destroy_display(all->mlx.ptr);
		clean_all(all);
		exit (1);
	}
	return (0);
}

int	game_start(t_all *all)
{
	all->mlx.ptr = mlx_init();
	all->mlx.win = mlx_new_window(all->mlx.ptr, all->plan.col * 64, \
		all->plan.row * 64, "So Long");
	load_textures(all);
	render_frames(all);
	mlx_hook(all->mlx.win, 2, 1L << 0, close_it, all);
	mlx_loop(all->mlx.ptr);
	return (0);
}
