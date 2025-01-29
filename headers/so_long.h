/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:29:43 by darkless12        #+#    #+#             */
/*   Updated: 2025/01/29 13:48:41 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


#	include <stdlib.h>
#	include <unistd.h>
#	include "libft.h"

// structure needed to build a map
typedef struct s_map
{
	char	**plant;
	int		rows;
	int		cols;
} t_map;

// main struct that will go all over the place
// connects all game information
typedef struct s_all
{
	struct s_map	map;
} t_all;

int	init_all(t_all *all);
int	map_loader(t_all *all,char *fname);
int	check_name(char *fname);
int	got_error(char *msg);

#endif