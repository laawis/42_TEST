/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:47:48 by gaollier          #+#    #+#             */
/*   Updated: 2023/11/15 14:48:21 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>

#include "fdf.h"

static void	my_mlx_pixel_put(const t_data *const data, const int x, const int y, const int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// le premier const signifie que cee qui est pointe (valeur) est constant
// 2ieme const signifie que la valeur du pointeur est constant
void	draw_point(const t_data *const data, const t_vertex *const vertex)
{
	if ((vertex->x <= WINDOW_WIDTH && vertex->x >= 0) && (vertex->y <= WINDOW_HEIGHT && vertex->y >= 0))
		my_mlx_pixel_put(data, vertex->x, vertex->y, vertex->color);
}

void	draw_line(const t_data *const data, t_vertex *v1, t_vertex *v2)
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	error;
	int e2;

	dx = abs(v2->x - v1->x);
	sx = v1->x < v2->x ? 1 : -1;
	dy = -abs(v2->y - v1->y);
	sy = v1->y < v2->y ? 1 : -1;
	error = dx + dy;

	while (1)
	{
		draw_point(data, v1);
		if (v1->x == v2->x && v1->y == v2->y)
			break;
		e2 = 2 * error;
		if (e2 >= dy)
		{
			if (v1->x == v2->x)
				break;
			error += dy;
			v1->x += sx;
		}
		if (e2 <= dx)
		{
			if (v1->y == v2->y)
				break;
			error += dx;
			v1->y += sy;
		}
	}
}

void	draw_map(const t_data * const data, t_vertex **v_matrix, ssize_t *height, ssize_t *width)
{
	int	i;
	int	j;

	i = 0;
	while ((i < *height) && ((i + 1) <= *height))
	{
		j = 0;
		while ((j < *width) && ((j + 1) <= *width))
		{
			draw_line(data, &v_matrix[i][j], &v_matrix[i + 1][j]);
			draw_line(data, &v_matrix[i][j], &v_matrix[i][j + 1]);
			j++;
		}
		draw_line(data, &v_matrix[i][j], &v_matrix[i + 1][j]);
		i++;
	}
	if (i == *height)
	{
		j = 0;
		while ((j < *width) && ((j + 1) <= *width))
		{
			draw_line(data, &v_matrix[i][j], &v_matrix[i][j + 1]);
			j++;
		}
	}
}
