/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixs_matching.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:23:06 by gaollier          #+#    #+#             */
/*   Updated: 2023/11/15 14:29:32 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <libft.h>

#include "fdf.h"

ssize_t	get_width(char ***matrix_altitude)
{
	size_t	i;
	size_t	j;
	size_t	width;

	width = 0;
	i = 0;
	while (matrix_altitude[i] != NULL)
	{
		j = 0;
		while(matrix_altitude[i][j] != NULL && j < MAP_WIDTH_LIMIT)
		{
			j++;
		}
		if ((j != width && i > 0) || j > MAP_WIDTH_LIMIT)
			return (-1);
		width = j;
		i++;
	}
	return (width);
}

t_vertex	**alloc_vertex_matrix(size_t width, size_t height)
{
	t_vertex	**vertex_matrix;
	size_t		i;

	vertex_matrix = (t_vertex **)malloc(sizeof(t_vertex *) * (height));
	if (vertex_matrix == NULL)
		return (NULL);
	i = 0;
	while (i < height)
	{
		vertex_matrix[i] = ((t_vertex *)malloc(sizeof(t_vertex) * (width)));
		if (vertex_matrix[i] == NULL)
		{
			free_vertex_matrix(vertex_matrix, i);
			return (NULL);
		}
		i++;
	}
	return (vertex_matrix);
}

t_vertex	**fill_vertex_matrix(t_vertex **vertex_matrix, char ***string_matrix)
{
	int	i;
	int	j;

	i = 0;
	while (string_matrix[i] != NULL)
	{
		j = 0;
		while (string_matrix[i][j] != NULL)
		{
			vertex_matrix[i][j].y = i;
			vertex_matrix[i][j].x = j;
			vertex_matrix[i][j].w = ft_atoi(string_matrix[i][j]);
			j++;
		}
		i++;
	}
	return (vertex_matrix);
}

void	draw_map(const t_data * const data, t_vertex **v_matrix, size_t width, size_t height)
{
	int	i;
	int	j;

	i = 0;
	while ((i < eight) && (i + 1 <= eight))
	{
		j = 0;
		while ((j < width) && (j + 1 <= width))
		{
			draw_line(data, v_matrix[i][j], v_matrix[i + 1][j]);
			draw_line(data, v_matrix[i][j], v_matrix[i][j + 1]);
			j++;
		}
		draw_line(data, v_matrix[i][j], v_matrix[i + 1][j]);
		i++;
	}
	if (i == eight)
	{
		while ((j < width) && (j + 1 <= width))
		draw_line(data, v_matrix[i][j], v_matrix[i][j + 1]);
		j++;
	}
	return (vertex_matrix);
}

