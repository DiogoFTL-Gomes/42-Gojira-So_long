/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_nav.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:07:10 by darkless12        #+#    #+#             */
/*   Updated: 2025/02/11 17:26:57 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//fill all navigable tiles
void	fill_map_nav(t_all *all, char **tester, int x, int y)
{
	if (x < 0 || x > all->plan.col || y < 0 || y > all->plan.row)
		return;
	if (tester[y][x] == '1' || tester[y][x] == 'X')
		return;
	if (tester[y][x] == 'P')
	{
		all->game.x = x;
		all->game.y = y;
	}
	tester[y][x] = 'X';
	// for (int i = 0; i < all->plan.rows; i++)	// remover
	// 	printf("%s\n", tester[i]);				// remover
	// printf("\n");								// remover
	fill_map_nav(all, tester, x + 1, y);
	fill_map_nav(all, tester, x - 1, y);
	fill_map_nav(all, tester, x, y + 1);
	fill_map_nav(all, tester, x, y - 1);
}

//Encontrar o inicio do jogo e validar navegabilidade
int	validate_map(t_all *all, char **tester)
{
	int	i;
	int	j;

	i = 0;
	while (i++ < all->plan.row)
	{
		j = 0;
		while (j++ < all->plan.col)
		{
			if (tester[i - 1][j - 1] == 'P')
				fill_map_nav(all, tester, j - 1, i - 1);
		}
	}
	i = 0;
	while (i++ < all->plan.row)
	{
		j = 0;
		while (j++ < all->plan.col)
		{
			if (tester[i - 1][j - 1] == 'C' || tester[i - 1][j - 1] == 'E')
				return (got_error("Collectible or exit no accessible\n"));
		}
	}
	return (0);
}

//check borders of map copy
int	check_border(t_all *all, char **tester)
{
	int	i;

	i = 0;
	while (i < all->plan.col)
	{
		if (tester[0][i] != '1' || tester[all->plan.row - 1][i] != '1')
		{
			clean_array(tester);
			return (got_error("Upper or lower margins are not a 1\n"));
		}
		i++;
	}
	i = 0;
	while (i < all->plan.row)
	{
		if (tester[i][0] != '1' || tester[i][all->plan.col - 1] != '1')
		{
			clean_array(tester);
			return (got_error("Side margins are not a 1"));
		}
		i++;
	}
	return (validate_map(all, tester));
}

//copy map to check borders & navigation
int	check_nav(t_all *all)
{
	char	**tester;
	int		i;
	int		j;

	tester = malloc(sizeof(char *) * (all->plan.row + 1));
	if (!tester)
		return (got_error("Failed malloc of array copy"));
	tester[all->plan.row] = 0;
	i = 0;
	while (i < all->plan.row)
	{
		tester[i] = malloc(sizeof(char) * (all->plan.col + 1));
		if (!tester[i])
			return (got_error("Failed malloc of array line copy"));
		j = 0;
		while (j++ < all->plan.col)
			tester[i][j - 1] = all->plan.map[i][j - 1];
		tester[i][all->plan.col] = 0;
		i++;
	}
	i = check_border(all, tester);
	clean_array(tester);
	return (i);
}
