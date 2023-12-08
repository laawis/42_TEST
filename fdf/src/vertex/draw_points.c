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

void	my_mlx_pixel_put(const t_data *const data, const int x, const int y, const int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// le premier const signifie que ce qui est pointe (valeur) est constant
// 2ieme const signifie que la valeur du pointeur est constant
// void	draw_point(const t_data *const data, const t_vertex vertex)
// {
// 	if ((vertex.x <= WINDOW_WIDTH && vertex.x >= 0) && (vertex.y <= WINDOW_HEIGHT && vertex.y >= 0))
// 	{
// //		printf("pourquoi je dessine pas vertex X %d --- vertex Y %d ---- Vertex W %d ---- Vertex Color %d\n\n", vertex->x, vertex->y, vertex->w, vertex->color);
// 		my_mlx_pixel_put(data, vertex.x, vertex.y, vertex.color);
// 	}
// }

void	draw_point(const t_data *const data, const int x, const int y, const int color)
{
	if ((x <= WINDOW_WIDTH && x >= 0) && (y <= WINDOW_HEIGHT && y >= 0))
	{
//		printf("pourquoi je dessine pas vertex X %d --- vertex Y %d ---- Vertex W %d ---- Vertex Color %d\n\n", vertex->x, vertex->y, vertex->w, vertex->color);
		my_mlx_pixel_put(data, x, y, color);
	}
}

// void	draw_line(const t_data *const data, t_vertex v1, t_vertex v2)
// {
// 	int	dx;
// 	int	sx;
// 	int	dy;
// 	int	sy;
// 	int	error;
// 	int e2;

// 	//printf("v1{%d;%d;%d} v2{%d;%d;%d}", v1.x, v1.y, v1.w, v2.x,v2.y, v2.w);
// 	dx = abs(v2.x - v1.x);
// 	sx = v1.x < v2.x ? 1 : -1;
// 	dy = -abs(v2.y - v1.y);
// 	sy = v1.y < v2.y ? 1 : -1;
// 	error = dx + dy;

// 	while (1)
// 	{
// 		draw_point(data, v1);
// 		if (v1.x == v2.x && v1.y == v2.y)
// 			break;
// 		e2 = 2 * error;
// 		if (e2 >= dy)
// 		{
// 			if (v1.x == v2.x)
// 				break;
// 			error += dy;
// 			v1.x += sx;
// 		}
// 		if (e2 <= dx)
// 		{
// 			if (v1.y == v2.y)
// 				break;
// 			error += dx;
// 			v1.y += sy;
// 		}
// 	}
// }

static void	draw_vector(const t_data *const data, t_vertex v1, t_vertex v2)
{
	double d_x = sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2));
	int pr = d_x; // (qualite du trait)
	int x;
	int y;
	int i = 0;
// la composante A comprends l'ensemble de x,y
// pythagore: soustraire composante point B a point A pour obtenir la distance sur chaque composante
	while (i < pr)
	{
		x = round(v1.x + ((v2.x - v1.x) * ((float) i / pr)));
		y = round(v1.y + ((v2.y - v1.y) * ((float) i / pr)));
		//printf("%d %d\n", x, y);
		draw_point(data, x, y, 0xFF0000);
		i++;
	}
}
//Bresenham Joseph
// void	draw_line(const t_data *const data, t_vertex v1, t_vertex v2)
// {
// 	int	dx;
// 	int	dy;
// 	int	incx;
// 	int	incy;
// 	int	e;
// 	int	e2;

// 	//printf("v1{%d;%d;%d} v2{%d;%d;%d}\n", v1.x, v1.y, v1.w, v2.x, v2.y, v2.w);

// 	dx = abs(v2.x - v1.x);
// 	dy = abs(v2.y - v1.y);
// 	incx = v1.x < v2.x ? 1 : -1;
// 	incy = v1.y < v2.y ? 1 : -1;
// 	e = dx - dy;
	
// 	draw_point(data, v1);
// 	while((v1.x != v2.x) || v1.y != v2.y)
// 	{
// 		e2 = e * 2;
// 		if (e2 > -dy)
// 		{
// 			e -= dy;
// 			v1.x += incx;
// 		}
// 		if (e2 < dx)
// 		{
// 			e += dx;
// 			v1.y += incy;
// 		}
// 		draw_point(data, v1);
// 	}
// }

// void	draw_map(const t_data *const data, t_map map)
// {
// 	int	i;
// 	int	j;

// 	//printf("width=%zd; height=%zd \n", *width, *height);
// 	i = 0;
// 	while (i < (map.height))
// 	{
// 		j = 0;
// 		while (j < (map.width - 1))
// 		{
// 			draw_line(data, map.v_matrix[i][j], map.v_matrix[i][j + 1]);
// 			j++;			
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	while (i < (map.height - 1))
// 	{
// 		j = 0;
// 		while (j < (map.width))
// 		{
// 			draw_line(data, map.v_matrix[i][j], map.v_matrix[i + 1][j]);
// 			j++;			
// 		}
// 		i++;
// 	}
// }
void	draw_map(const t_data *const data, const t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (j < map.width - 1)
				draw_vector(data, map.v_matrix[i][j], map.v_matrix[i][j + 1]);
			if (i < map.height - 1)
				draw_vector(data, map.v_matrix[i][j], map.v_matrix[i + 1][j]);
			++j;
		}
		++i;
	}
}
