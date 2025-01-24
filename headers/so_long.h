/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:29:43 by darkless12        #+#    #+#             */
/*   Updated: 2025/01/23 18:47:59 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


#	include <stdlib.h>
#	include <unistd.h>

// o que e preciso para construir e usar o mapa
typedef struct s_map
{
	char	**map;
} t_map;

// struct principal que vai andar a passear por todo o lado.
// liga a toda a informação importante do jogo
typedef struct s_all
{
	struct s_map	map;
} t_all;


#endif