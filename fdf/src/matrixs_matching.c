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

	vertex_matrix = (t_vertex **)malloc(sizeof(t_vertex *) * (height + 1));
	if (vertex_matrix == NULL)
		return (NULL);
	i = 0;
	while (i < height)
	{
		vertex_matrix[i] = ((t_vertex *)malloc(sizeof(t_vertex) * (width + 1)));
		if (vertex_matrix[i] == NULL)
		{
			free_vertex_matrix(vertex_matrix, i);
			return (NULL);
		}
		i++;
	}
	return (vertex_matrix);
}
/*
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
			vertex_matrix[i][j].w = ft_atoi(string_matrix[i][j]);
			vertex_matrix[i][j].y = 150 + (i * 70) - (vertex_matrix[i][j].w * 8);
			vertex_matrix[i][j].x = 150 + (j * 70) + (i * 33);
			vertex_matrix[i][j].color = 0x00FFFFFF;
			j++;
		}
		i++;
	}
	return (vertex_matrix);
}
*/

void	fill_vmatrix(t_map *map, char ***string_matrix)
{
	int	i;
	int	j;

	i = 0;
	while (string_matrix[i] != NULL)
	{
		j = 0;
		while (string_matrix[i][j] != NULL)
		{
			map->v_matrix[i][j].w = ft_atoi(string_matrix[i][j]);
										//      CENTER                       |         // ZOOM                                  | // AMPLITUDE
			map->v_matrix[i][j].y = i; //((WINDOW_HEIGHT - map->height) / 3) + i * (WINDOW_HEIGHT / (map->height + map->width)) - (map->v_matrix[i][j].w * 6);
																														  // |    // ROTATION (POINT DE FUITE)
			map->v_matrix[i][j].x = j; //((WINDOW_WIDTH - map->width) / 7) + j * (WINDOW_WIDTH / (map->width + map->height)) + (i * ((WINDOW_WIDTH / map->width) / 4));
			map->v_matrix[i][j].color = 0x00FFFFFF;
			j++;
		}
		i++;
	}
}