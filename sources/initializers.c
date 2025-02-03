/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:11:22 by darkless12        #+#    #+#             */
/*   Updated: 2025/02/03 18:31:59 by darkless12       ###   ########.fr       */
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
int	init_render(t_all *all)
{
	all->render.mlx = 0;
	all->render.win = 0;
	return (0);
}

//chama funcoes que iniciam structs essenciais
int	init_all(t_all *all)
{
	if (init_map(all))
		return (got_error("Map struct failed to initialize\n"));
	if (init_render(all))
		return (got_error("Render struct failed to initialize\n"));
	return (0);
}
