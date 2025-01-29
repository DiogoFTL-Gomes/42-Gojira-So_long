/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:33:05 by darkless12        #+#    #+#             */
/*   Updated: 2025/01/29 12:07:39 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//verifica se o nome termina em .ber
int	check_name(char *fname)
{
	char	*ext;
	int		i;
	int		j;

	ext = ".ber";
	i = 0;
	j = 0;
	while (fname[i] != 0)
		i++;
	while (j < 4 )
	{
		if (fname[i - 4] != ext[j] || i < 5)
			return (0);
		j++;
		i++;
	}
	return (1);
}
