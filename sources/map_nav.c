/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_nav.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:07:10 by darkless12        #+#    #+#             */
/*   Updated: 2025/02/04 20:19:47 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//fill all navigable tiles
void	fill_map_nav(t_all *all, char **tester, int x, int y)
{
	if (x < 0 || x > all->plan.cols || y < 0 || y > all->plan.rows)
		return;
	if (tester[y][x] == '1' || tester[y][x] == 'X')
		return;
	tester[y][x] = 'X';
	for (int i = 0; i < all->plan.rows; i++)	// remover
		printf("%s\n", tester[i]);				// remover
	printf("\n");								// remover
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
	while (i++ < all->plan.rows)
	{
		j = 0;
		while (j++ < all->plan.cols)
		{
			if (tester[i - 1][j - 1] == 'P')
				fill_map_nav(all, tester, j - 1, i - 1);
		}
	}
	i = 0;
	while (i++ < all->plan.rows)
	{
		j = 0;
		while (j++ < all->plan.cols)
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
	while (i < all->plan.cols)
	{
		if (tester[0][i] != '1' || tester[all->plan.rows - 1][i] != '1')
		{
			clean_array(tester);
			return (got_error("Upper or lower margins are not a 1\n"));
		}
		i++;
	}
	i = 0;
	while (i < all->plan.rows)
	{
		if (tester[i][0] != '1' || tester[i][all->plan.cols - 1] != '1')
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

	tester = malloc(sizeof(char *) * (all->plan.rows + 1));
	if (!tester)
		return (got_error("Failed malloc of array copy"));
	tester[all->plan.rows] = 0;
	i = 0;
	while (i < all->plan.rows)
	{
		tester[i] = malloc(sizeof(char) * (all->plan.cols + 1));
		if (!tester[i])
			return (got_error("Failed malloc of array line copy"));
		j = 0;
		while (j < all->plan.cols)
		{
			tester[i][j] = all->plan.map[i][j];
			j++;
		}
		tester[i][j] = 0;
		i++;
	}
	return (check_border(all, tester));
}
