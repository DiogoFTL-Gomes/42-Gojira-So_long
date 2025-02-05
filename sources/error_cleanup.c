/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cleanup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:02:30 by darkless12        #+#    #+#             */
/*   Updated: 2025/02/05 15:17:19 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//imprime erros
int	got_error(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	return (1);
}

//limpa strings de **map
void	clean_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != 0)
		free(array[i++]);
	free(array);
}

//limpar t_all
void	clean_all(t_all *all)
{
	if (all->plan.map)
		clean_array(all->plan.map);
	if (all->render.mlx)
		free(all->render.mlx);
	// if (all->render.win)
	// 	free(all->render.win);
	free(all);
}
