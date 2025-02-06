/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:29:43 by darkless12        #+#    #+#             */
/*   Updated: 2025/02/06 14:41:36 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h> //remove. for printf()
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "mlx_int.h"

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

// struct for mlx
typedef struct s_graph
{
	void	*mlx;
	void	*win;
}	t_graph;

typedef struct s_tile
{
	void	*img;
	void	*addr;
}	t_tile;

// main struct that will go all over the place
// connects all game information
typedef struct s_all
{
	t_plan		plan;
	t_graph		graph;
	t_tile		floor;
	t_tile		wall;
	t_tile		player;
	t_tile		nuke;
	t_tile		exit;
}	t_all;

int		init_all(t_all *all);
int		map_loader(t_all *all, char *fname);
int		check_file_name(t_all *all, char *fname);
int		got_error(char *msg);
int		find_ncols(char *line);
int		game_start(t_all *all);
int		check_nav(t_all *all);
void	clean_array(char **array);
void	clean_all(t_all *all);

#endif