/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:11:22 by darkless12        #+#    #+#             */
/*   Updated: 2025/01/29 14:50:33 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//inicia a struct do mapa
int	init_map(t_all *all)
{
	all->map.plant = NULL;
	all->map.rows = 0;
	all->map.cols = 0;
	return (1);
}

//chama funcoes que iniciam structs essenciais
int	init_all(t_all *all)
{
	if (!(init_map(all)))
		return (got_error("Map struct failed to initialize\n"));
	return (1);
}