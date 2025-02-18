/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cleanup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:02:30 by darkless12        #+#    #+#             */
/*   Updated: 2025/02/18 14:33:30 by darkless12       ###   ########.fr       */
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

void	clean_img(t_all *all, t_tile *tile, int count)
{
	while (count > 0)
	{
		count--;
		mlx_destroy_image(all->mlx.ptr, tile[count].img);
	}
}

//limpar t_all
void	basic_clean(t_all *all)
{
	if (all->plan.map)
		clean_array(all->plan.map);
	if (all->mlx.ptr)
		mlx_destroy_display(all->mlx.ptr);
	free(all);
}

int	close_it(t_all *all)
{
	if (all->plan.map)
		clean_array(all->plan.map);
	clean_img(all, all->floor, 6);
	clean_img(all, all->nuke, 2);
	clean_img(all, all->gojira, 4);
	clean_img(all, all->wall, 3);
	clean_img(all, &all->exit, 1);
	if (all->mlx.win)
		mlx_destroy_window(all->mlx.ptr, all->mlx.win);
	if (all->mlx.ptr)
		mlx_destroy_display(all->mlx.ptr);
	free(all->mlx.ptr);
	free(all);
	exit (1);
	return (0);
}