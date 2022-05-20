/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:28:16 by gyumpark          #+#    #+#             */
/*   Updated: 2022/05/20 14:03:02 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	hint_f(t_fdf *fdf, float x, float y, int hint)
{
	if (hint == 0)
	{
		fdf->map.x1 = x + 1;
		fdf->map.y1 = y;
	}
	if (hint == 1)
	{
		fdf->map.x1 = x;
		fdf->map.y1 = y + 1;
	}
}

static void	zoom_color(t_fdf *fdf, float *x, float *y, int *z)
{
	*z = fdf->map.elements[(int)*y][(int)*x];
	*x *= fdf->map.zoom;
	*y *= fdf->map.zoom;
	fdf->map.x1 *= fdf->map.zoom;
	fdf->map.y1 *= fdf->map.zoom;
	fdf->map.color = 0xffffff;
}

static void	isometric(t_fdf *fdf, float *x, float *y, int z)
{
	*x = (*x - *y) * (fdf->map.angle_x);
	*y = (*x + *y) * (fdf->map.angle_y) - z;
}

static void	dda(t_fdf *fdf, float x, float y, int hint)
{
	float	x_step;
	float	y_step;
	int		z;
	int		z1;

	hint_f(fdf, x, y, hint);
	z1 = fdf->map.elements[(int)fdf->map.y1][(int)fdf->map.x1];
	zoom_color(fdf, &x, &y, &z);
	isometric(fdf, &x, &y, z);
	isometric(fdf, &fdf->map.x1, &fdf->map.y1, z1);
	x += fdf->map.shift_x;
	y += fdf->map.shift_y;
	fdf->map.x1 += fdf->map.shift_x;
	fdf->map.y1 += fdf->map.shift_y;
	x_step = fdf->map.x1 - x;
	y_step = fdf->map.y1 - y;
	max(mod(x_step), mod(y_step), &x_step, &y_step);
	while ((int)(x - fdf->map.x1) || (int)(y - fdf->map.y1))
	{
		mlx_pixel_put(fdf->mlx.init, fdf->mlx.win, x, y, fdf->map.color);
		x += x_step;
		y += y_step;
	}
}

int	draw(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->map.height)
	{
		x = 0;
		while (x < fdf->map.width)
		{
			if (x < fdf->map.width - 1)
				dda(fdf, x, y, 0);
			if (y < fdf->map.height - 1)
				dda(fdf, x, y, 1);
			x++;
		}
		y++;
	}
	return (0);
}
