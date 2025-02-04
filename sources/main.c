/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:49:25 by darkless12        #+#    #+#             */
/*   Updated: 2025/02/04 20:20:17 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_ncols(char *line)
{
	int	i;

	i = 0;
	while (line[i] != 0 && line[i] != '\n')
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	if (!all)
	{
		write(2, "malloc failed at start!\n", 25);
		free(all);
	}
	else if (argc != 2)
	{
		write(2, "Give map one file name, pls\n", 28);
		free(all);
	}
	if (init_all(all) || map_loader(all, argv[1]))
	{
		clean_array(all->plan.map);
		free(all);
		return (1);
	}
	//game_start(all);
	free(all);
	return (0);
}
