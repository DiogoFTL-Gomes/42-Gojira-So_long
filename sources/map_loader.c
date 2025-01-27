/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:18:53 by darkless12        #+#    #+#             */
/*   Updated: 2025/01/27 21:23:19 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int	find_file(t_all *all, char *fname)
{

}

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
	i -= 4;
	while (j < 4 )
	{
		if (fname[i] != ext[j] || i < 5)
			return (0);
		j++;
		i++;
	}
	return (1);
}

int	map_loader(t_all *all, char *fname)
{
	if (!(check_name(fname)))
		return (0);
	if (!(find_file(all, fname)))
		return (0);
}