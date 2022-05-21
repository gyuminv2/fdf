/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:28:40 by gyumpark          #+#    #+#             */
/*   Updated: 2022/05/21 17:37:32 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static void	saving_row_col(int *row, int *col, int *len)
{
	if (*len > *row)
		*row = *len;
	(*col)++;
	if (*len != *row)
		ft_error("Error: match rows_len\n", 23);
}

static int	error_and_get(char *line)
{
	int	rows;

	rows = 0;
	while (*line)
	{
		if (ft_isdigit(*line))
		{
			rows ++;
			while (ft_isdigit(*line) || *line == ',' || ft_isalpha(*line))
				line ++;
		}
		else if (*line != ' ' && *line != '-' && *line != '\n')
			ft_error("Error: no digit\n", 17);
		line ++;
	}
	return (rows);
}

static void	pasing_ready(char *av, t_fdf *fdf)
{
	int		fd;
	int		one_line;
	int		rows;
	int		cols;
	char	*line;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_error("ERROR: no map_file\n", 20);
	one_line = 0;
	rows = 0;
	cols = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		one_line = error_and_get(line);
		saving_row_col(&rows, &cols, &one_line);
		free(line);
	}
	close(fd);
	fdf->map.width = rows;
	fdf->map.height = cols;
}

static void	save_elements(t_fdf *fdf, int x, int y, char *line)
{
	char	**split;
	int		i;

	split = ft_split(line, ' ');
	if (split)
	{
		i = 0;
		while (split[i] && (x != fdf->map.width))
		{
			fdf->map.elements[y][x] = ft_atoi(split[i++]);
			x ++;
		}
		i = 0;
		while (split[i])
			i++;
		while (i >= 0)
			free(split[i--]);
	}
	free(line);
}

void	ft_read(char *av, t_fdf *fdf)
{
	int		x;
	int		y;
	int		fd;
	char	*line;

	x = 0;
	y = 0;
	fd = open(av, O_RDONLY);
	pasing_ready(av, fdf);
	fdf->map.elements = (int **) malloc(sizeof(int *) * fdf->map.height);
	if (!fdf->map.elements)
		ft_error("Error: Assignment failed\n", 26);
	while (y != fdf->map.height)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		fdf->map.elements[y] = (int *) malloc(sizeof(int) * fdf->map.width);
		if (!fdf->map.elements[y])
			ft_error("Error: Assignment failed\n", 26);
		save_elements(fdf, x, y, line);
		x = 0;
		y ++;
	}
	close(fd);
}
