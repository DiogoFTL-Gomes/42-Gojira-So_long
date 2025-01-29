/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:18:53 by darkless12        #+#    #+#             */
/*   Updated: 2025/01/29 14:50:56 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//chama funcoes que carregam o mapa
int	map_loader(t_all *all, char *fname)
{
	if (!(check_name(fname)))
		return (0);
	if (!(check_fname(all, fname)))
		return (0);
	return (1);
}