/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:33:55 by darkless12        #+#    #+#             */
/*   Updated: 2025/02/05 15:16:25 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_start(t_all *all)
{
	all->render.mlx = mlx_init();
	all->render.win = mlx_new_window(all->render.mlx, all->plan.cols * 64, \
		all->plan.rows * 64, "So Long");
	mlx_destroy_window(all->render.mlx, all->render.win);
	mlx_destroy_display(all->render.mlx);
	return (0);
}
