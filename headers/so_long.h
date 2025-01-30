/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:29:43 by darkless12        #+#    #+#             */
/*   Updated: 2025/01/30 21:07:39 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#	include <stdio.h>
#	include <stdlib.h>
#	include <unistd.h>
#	include "libft.h"
#	include "get_next_line.h"

// structure needed to build a map
typedef struct s_plan
{
	char	**map;
	int		rows;
	int		cols;
	int		player;
	int		colect;
	int		exit;
} t_plan;

// main struct that will go all over the place
// connects all game information
typedef struct s_all
{
	struct s_plan	plan;
} t_all;

int	init_all(t_all *all);
int	map_loader(t_all *all, char *fname);
int	check_file_name(t_all *all, char *fname);
int	got_error(char *msg);

#endif