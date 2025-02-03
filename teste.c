/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:10:32 by darkless12        #+#    #+#             */
/*   Updated: 2025/02/03 15:29:04 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <mlx.h>
// #include <stdio.h>

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// int	key_hook(void)
// {
// 	printf("Hello from key_hook!\n");
// 	return (0);
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
// 	mlx_key_hook(vars.win, key_hook, &vars);
// 	mlx_loop(vars.mlx);
// }

// #include <mlx.h>
// #include <stdlib.h>

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;


// int	close_it(int keycode, t_vars *vars)
// {
// 	if (keycode == 0xff1b)
// 	{
// 		mlx_destroy_window(vars->mlx, vars->win);
// 		exit(0);
// 	}
// 	return (0);
// }

// int	create_trgb(int t, int r, int g, int b)
// {
// 	return (t << 24 | r << 16 | g << 8 | b);
// }

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	main(void)
// {
// 	t_vars	vars;
// 	t_data	img;
// 	int		i;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 640, 480, "Like... just press ESC..");
// 	img.img = mlx_new_image(vars.mlx, 640, 480);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	i = 0;
// 	while (i < 200)
// 	{
// 		my_mlx_pixel_put(&img, 20, i + 20, create_trgb(0, 255, i, 0));
// 		my_mlx_pixel_put(&img, 220, i + 20, create_trgb(0, 0, 255, i));
// 		my_mlx_pixel_put(&img, i + 20, 20, create_trgb(0, i, 0, 255));
// 		my_mlx_pixel_put(&img, i + 20, 220, create_trgb(0, i, 128, 128));
// 		i++;
// 	}
// 	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
// 	mlx_hook(vars.win, 2, 1L << 0, close_it, &vars);
// 	mlx_loop(vars.mlx);
// }

// #include <mlx.h>
// #include <stdlib.h>

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// int	create_trgb(int t, int r, int g, int b)
// {
// 	return (t << 24 | r << 16 | g << 8 | b);
// }

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	main(void)
// {
// 	t_vars	vars;
// 	t_data	img;
// 	int		i;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 640, 480, "This is fine...");
// 	img.img = mlx_new_image(vars.mlx, 640, 480);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	i = 0;
// 	while (i < 200)
// 	{
// 		my_mlx_pixel_put(&img, 20, i + 20, create_trgb(0, 255, i, 0));
// 		my_mlx_pixel_put(&img, 220, i + 20, create_trgb(0, 0, 255, i));
// 		my_mlx_pixel_put(&img, i + 20, 20, create_trgb(0, i, 0, 255));
// 		my_mlx_pixel_put(&img, i + 20, 220, create_trgb(0, i, 128, 128));
// 		i++;
// 	}
// 	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
// 	mlx_loop(vars.mlx);
// }

// #include <mlx.h>
// #include <stdlib.h>

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// int	create_trgb(int t, int r, int g, int b)
// {
// 	return (t << 24 | r << 16 | g << 8 | b);
// }

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	main(void)
// {
// 	t_vars	vars;
// 	t_data	img;
// 	int		i;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 640, 480, "This is fine...");
// 	img.img = mlx_new_image(vars.mlx, 640, 480);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	i = 0;
// 	while (i < 200)
// 	{
// 		my_mlx_pixel_put(&img, 20, i + 20, create_trgb(0, 255, 0, 0));
// 		my_mlx_pixel_put(&img, 220, i + 20, create_trgb(0, 255, 0, 0));
// 		my_mlx_pixel_put(&img, i + 20, 20, create_trgb(0, 255, 0, 0));
// 		my_mlx_pixel_put(&img, i + 20, 220, create_trgb(0, 255, 0, 0));
// 		i++;
// 	}
// 	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
// 	mlx_loop(vars.mlx);
// }

// #include <mlx.h>

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// int	main(void)
// {
// 	void	*mlx;
// 	t_data	img;

// 	mlx = mlx_init();
// 	img.img = mlx_new_image(mlx, 1920, 1080);

// 	/*
// 	** After creating an image, we can call `mlx_get_data_addr`, we pass
// 	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
// 	** then be set accordingly for the *current* data address.
// 	*/
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// }


// #include <mlx.h>

// int	main(void)
// {
// 	void	*img;
// 	void	*mlx;

// 	mlx = mlx_init();
// 	img = mlx_new_image(mlx, 800, 600);
// 	(void)img;
// }


// #include <mlx.h>

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 800, 600, "Janela para abismo");
// 	mlx_loop(mlx);
// 	(void)mlx_win;
// }

// #include <mlx.h>

// int	main(void)
// {
// 	void	*mlx;

// 	mlx = mlx_init();
// 	(void)mlx; // so para não dar erro pq a var não foi usada.
// }
