/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cleanup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:02:30 by darkless12        #+#    #+#             */
/*   Updated: 2025/02/01 18:35:21 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//limpa strings de **map
void	clean_map(t_all *all)
{
	int	i;

	i = 0;
	while (all->plan.map[i] != 0)
		free(all->plan.map[i]);
	free(all->plan.map);
}

//imprime erros
int	got_error(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	return (1);
}