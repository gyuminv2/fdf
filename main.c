/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:28:54 by gyumpark          #+#    #+#             */
/*   Updated: 2022/05/21 17:48:20 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	change_view(t_fdf *fdf)
{
	if (fdf->map.isometric++ % 2)
		fdf->map.angle_y *= 0.5;
	else
		fdf->map.angle_y *= 2;
}

static int	key_down(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	else if (keycode == 49)
		change_view(fdf);
	else if (keycode == 126)
		fdf->map.shift_y -= 30;
	else if (keycode == 125)
		fdf->map.shift_y += 30;
	else if (keycode == 124)
		fdf->map.shift_x += 30;
	else if (keycode == 123)
		fdf->map.shift_x -= 30;
	else if (keycode == 34)
		fdf->map.zoom += 1;
	else if (keycode == 31)
		fdf->map.zoom -= 1;
	else if (keycode == 46)
	{
		fdf->map.color = (rand() % 0xffffff);
		fdf->map.m_click++;
	}
	mlx_clear_window(fdf->mlx.init, fdf->mlx.win);
	draw(fdf);
	return (0);
}

static void	map_init(t_fdf *fdf)
{
	if (fdf->map.width > fdf->map.height)
		fdf->map.zoom = ceil((WIN_WIDTH / fdf->map.width) - 2);
	else
		fdf->map.zoom = ceil((WIN_HEIGHT / fdf->map.height) - 2);
	fdf->map.isometric = 1;
	fdf->map.angle_x = cos(M_PI / 3);
	fdf->map.angle_y = sin(M_PI / 6);
	fdf->map.shift_x = 150;
	fdf->map.shift_y = 150;
	fdf->map.color = 0x4F;
	fdf->map.m_click = 0;
	fdf->color.red = 0xff0000;
	fdf->color.green = 0x00ff00;
	fdf->color.blue = 0x0000ff;
}

int	main(int ac, char **av)
{
	t_fdf	*fdf;

	fdf = (t_fdf *) malloc(sizeof(t_fdf));
	if (ac == 1)
		ft_error("Error: input.argc = 1\n", 23);
	else if (ac > 2)
		ft_error("Error: input.argc > 2\n", 23);
	if (!fdf)
		ft_error("Error: Assignment failed\n", 26);
	ft_read(av[1], fdf);
	map_init(fdf);
	fdf->mlx.init = mlx_init();
	fdf->mlx.win = mlx_new_window(fdf->mlx.init, WIN_WIDTH, WIN_HEIGHT, "FDF");
	draw(fdf);
	mlx_hook(fdf->mlx.win, 2, 3, key_down, fdf);
	mlx_loop(fdf->mlx.init);
	free(fdf);
	return (0);
}
