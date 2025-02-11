/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:29:43 by darkless12        #+#    #+#             */
/*   Updated: 2025/02/11 17:41:02 by darkless12       ###   ########.fr       */
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
	int		row;
	int		col;
	int		player;
	int		colect;
	int		exit;
}	t_plan;

// struct for mlx
typedef struct s_mlx
{
	void	*ptr;
	void	*win;

	void	*img;
	void	*addr;
	int		bpp;
	int		endian;
	int		line;
}	t_mlx;

//struct for tile management
typedef struct s_tile
{
	void	*img;
	void	*addr;

	int		bpp;
	int		endian;

	int		l;
	int		h;
}	t_tile;

typedef struct s_game
{
	int	x;
	int	y;
	int nuke;
	int last;
}	t_game;

// main struct that will go all over the place
// connects all game information
typedef struct s_all
{
	t_plan		plan;
	t_mlx		mlx;
	t_game		game;
	t_tile		floor;
	t_tile		wall;
	t_tile		godjira;
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
void	load_textures(t_all *all);
void	render_frames(t_all *all);

#endif