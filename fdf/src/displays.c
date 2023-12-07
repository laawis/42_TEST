/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:19:46 by gaollier          #+#    #+#             */
/*   Updated: 2023/11/15 14:20:37 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "fdf.h"

void	print_matrix_altitude(char ***const matrix_altitude)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (matrix_altitude[i] != NULL)
	{
		j = 0;
		while (matrix_altitude[i][j] != NULL)
		{
			ft_printf("[%s]", matrix_altitude[i][j]); // plus simple
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

void	print_vertex_matrix(t_vertex **const vertex_matrix, size_t width, size_t height)
{
	size_t	i;
	size_t	j;
	(void) vertex_matrix;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			//ft_printf("{%d;%d;%d}", vertex_matrix[i][j].x, vertex_matrix[i][j].y, vertex_matrix[i][j].w );
			//printf("\n");
			//printf("{%d;%d;%d}", vertex_matrix[i][j].x, vertex_matrix[i][j].y, vertex_matrix[i][j].w );
			if (j + 1 < width)
				printf(",");
			j++;
		}
		printf("\n");
		i++;
	}
/*
	ft_printf("\n");
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			ft_printf("{%d;%d;%d}", vertex_matrix[i][j].x, vertex_matrix[i][j].y, vertex_matrix[i][j].w );
			if (j + 1 < width)
				printf(",");
			j++;
		}
		printf("\n");
		i++;
	}
*/
	printf("\n");
}
