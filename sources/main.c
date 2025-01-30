/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:49:25 by darkless12        #+#    #+#             */
/*   Updated: 2025/01/30 21:07:37 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		write(2, "Give map file name, pls\n", 24);
		free(all);
	}
	else
	{
		if (init_all(all) || map_loader(all, argv[1]))
		{
			free(all);
			return (1);
		}
		free(all);
	}
	return (0);
}
