/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:33:55 by darkless12        #+#    #+#             */
/*   Updated: 2025/02/03 18:30:51 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_start(t_all *all)
{
	all->render.mlx = mlx_init();
	all->render.win = mlx_new_window(all->render.mlx, all->plan.cols * 64, \
		all->plan.rows * 64, "So Long");
	clean_map(all);
}
