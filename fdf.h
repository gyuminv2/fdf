/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:28:06 by gyumpark          #+#    #+#             */
/*   Updated: 2022/05/20 11:28:07 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "./libft/libft.h"
# include "./minilibx_macos/mlx.h"

# define WIN_WIDTH	(980)
# define WIN_HEIGHT	(560)
# define BUFFER_SIZE 1

typedef struct s_mlx
{
	void	*init;
	void	*win;
}	t_mlx;

typedef struct s_map
{
	int		**elements;
	int		width;
	int		height;
	int		zoom;
	float	angle_x;
	float	angle_y;
	int		isometric;
	int		shift_x;
	int		shift_y;
	int		color;
	int		m_click;
	float	x1;
	float	y1;
}	t_map;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_fdf
{
	t_mlx	mlx;
	t_map	map;
	t_color	color;
}	t_fdf;

void	ft_read(char *av, t_fdf *fdf);
void	ft_error(char *e, size_t len);
char	*get_next_line(int fd);
int		draw(t_fdf *fdf);
void	max(int a, int b, float *x_step, float *y_step);
int		mod(int a);
#endif
