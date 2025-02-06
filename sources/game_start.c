/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:33:55 by darkless12        #+#    #+#             */
/*   Updated: 2025/02/06 20:14:05 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_it(int keycode, t_all *all)
{
	if (keycode == 0xff1b)
	{
		//destruir aqui imagens
		mlx_destroy_window(all->graph.mlx, all->graph.win);
		mlx_destroy_display(all->graph.mlx);
		clean_all(all);
		exit (1);
	}
	return (0);
}

int	game_start(t_all *all)
{
	all->graph.mlx = mlx_init();
	all->graph.win = mlx_new_window(all->graph.mlx, all->plan.cols * 64, \
		all->plan.rows * 64, "So Long");
	mlx_hook(all->graph.win, 2, 1L << 0, close_it, all);
	mlx_loop(all->graph.mlx);
	return (0);
}
