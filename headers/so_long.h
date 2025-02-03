/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:29:43 by darkless12        #+#    #+#             */
/*   Updated: 2025/02/03 18:36:14 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h> //remove. for printf()
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "get_next_line.h"
# include <mlx.h>

// structure needed to build a map
typedef struct s_plan
{
	char	**map;
	int		rows;
	int		cols;
	int		player;
	int		colect;
	int		exit;
}	t_plan;

typedef struct s_render
{
	void	*mlx;
	void	*win;
}	t_render;

// main struct that will go all over the place
// connects all game information
typedef struct s_all
{
	struct s_plan	plan;
	struct s_render	render;
}	t_all;

int		init_all(t_all *all);
int		map_loader(t_all *all, char *fname);
int		check_file_name(t_all *all, char *fname);
int		got_error(char *msg);
int		find_ncols(char *line);
void	clean_map(t_all *all);
void	game_start(t_all *all);

#endif