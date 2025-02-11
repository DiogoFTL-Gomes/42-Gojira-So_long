/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:30:30 by darkless12        #+#    #+#             */
/*   Updated: 2025/02/11 21:04:31 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_pixel_color(char *data, int x, int y, int line_len, int bpp)
{
	int	offset;

	offset = (y * line_len) + (x * (bpp / 8));
	return (*(int *)(data + offset));
}

void	put_pixel(t_all *all, int x, int y, int color)
{
	int	offset;

	if (x >= 0 && x < all->plan.col * 64 && y >= 0 && y < all->plan.row * 64)
	{
		offset = (y * all->mlx.line) + (x * (all->mlx.bpp / 8));
		*(int *)(all->mlx.addr + offset) = color;
	}
}

void	blend_image(t_all *all, t_tile *src, int len, int hei)
{
	int				x;
	int				y;
	int				color;
	unsigned char	alpha;

	printf("no blend_image\n");
	y = 64 - src->h;
	printf("y = %d\n", y);
	while (y < src->h)
	{
		x = 64 - src->l;
		printf("yx = %d\n", x);
		while (x < src->l)
		{
			color = get_pixel_color(src->addr, x + src->l - 64, \
				y + src->h - 64, src->l, src->bpp);
			alpha = (color >> 24) & 0xFF;
			if (alpha != 0xFF)
				put_pixel(all, len + x, hei + y, color);
			x++;
		}
		y++;
	}
}

void	find_tile(t_all *all, int x, int y)
{
	if (all->plan.map[y][x])
		blend_image(all, &all->floor, x * 64, y * 64);
}

void	render_frames(t_all *all)
{
	int	x;
	int	y;

	y = 0;
	all->mlx.img = mlx_new_image(all->mlx.ptr, all->plan.col * 64, \
		all->plan.row * 64);
	all->mlx.addr = mlx_get_data_addr(all->mlx.ptr, &all->mlx.bpp, \
		&all->mlx.line, &all->mlx.endian);
	while (y < all->plan.row)
	{
		x = 0;
		while (x < all->plan.col)
		{
			find_tile(all, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, \
		all->plan.col * 64, all->plan.row * 64);
	mlx_destroy_image(all->mlx.ptr, all->mlx.img);
}
