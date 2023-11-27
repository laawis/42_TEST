/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:21:42 by gaollier          #+#    #+#             */
/*   Updated: 2023/11/15 14:22:49 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>

#include "fdf.h"
#include "libft.h"

// gcc main.c -I minilibx_macos -L minilibx_macos -l mlx -framework OpenGL -framework AppKit

/*
- Vecteur (additionner, soustraire, multiplier / diviser)
- Produit vectorielle / Produit scalaire
- Matrice 3x3 et 4x4
- Algorithme de brensham (tracer des lignes)
*/

// static void	rotate_x_axis(t_vertex *vertex)
// {
// 	int	prev_y;

// 	prev_y = vertex->y;
// 	vertex->y = prev_y * cos(vertex->x) + vertex->w * sin(vertex->x);
// 	vertex->w = prev_y * -sin(vertex->x) + vertex->w * cos(vertex->x);
// }

// static void	rotate_y_axis(t_vertex *vertex)
// {
// 	int	prev_x;

// 	prev_x = vertex->x;
// 	vertex->x = prev_x * cos(vertex->y) + vertex->w * sin(vertex->y);
// 	vertex->w = prev_x * -sin(vertex->y) + vertex->w * cos(vertex->y);
// }

void	shift_map_from_center()
	shift_map(map, -center->x, -center->y); // decale en haut a gauche le centre

void	shift_map_to_center()
	shift_map(map, center->x, center->y); // remet la map au centre

// shift_map_from_center();
// rotate();
// shift_map_to_center();

void	shift_map(t_map *map, float shift_x, float shift_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j= 0;
		while (j < map->width)
		{
			map->v->matrix[i][j].x += shift_x; 
			map->v->matrix[i][j].y += shift_y
			j++;
		}
		i++;
	}
}

static void rotate_vertex(t_vertex *vertex)
{
	const double	theta = M_PI_4; // a mettre en define
	const int		prev = vertex->x;

	vertex->x = prev * cos(theta) - vertex->y * sin(theta);
	vertex->y = vertex->y * cos(theta) + prev * cos(theta);
}

// static void	rotate_w_axis(t_vertex *vertex)
// {
// 	t_vertex	prev;

// 	prev.x = vertex->x;
// 	prev.y = vertex->y;
// 	vertex->x = prev.x * cos(vertex->w) - prev.y * sin(vertex->w);
// 	vertex->y = prev.x * sin(vertex->w) + prev.y * cos(vertex->w);
// }

static void	zoom_vertex(t_map *const map, t_vertex *const vertex)
{
	const int	zoom_x = (WINDOW_WIDTH / (map->width + map->height));
	const int	zoom_y = (WINDOW_HEIGHT / (map->height + map->width));

	vertex->x *= zoom_x;
	vertex->y *= zoom_y;
}

static void	center_vertex(t_map *const map, t_vertex *const vertex)
{
	const int	zoom_x = (WINDOW_WIDTH / (map->width + map->height));
	const int	zoom_y = (WINDOW_HEIGHT / (map->height + map->width));
	const int	center_offset_x = WINDOW_WIDTH / 2 - ((map->width - 1) * zoom_x) / 2;
	const int	center_offset_y = WINDOW_HEIGHT / 2 - ((map->height - 1) * zoom_y) / 2;

	vertex->x += center_offset_x;
	vertex->y += center_offset_y;
}

static void	zoom(t_map *const map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			zoom_vertex(map, &(map->v_matrix[i][j]));
			j++;
		}
		i++;
	}
}

static void	center(t_map *const map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			center_vertex(map, &(map->v_matrix[i][j]));
			j++;
		}
		i++;
	}
}

static void	rotate(t_map *const map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			//rotate_x_axis(&(map->v_matrix[i][j]));
			//rotate_y_axis(&(map->v_matrix[i][j]));
			//rotate_w_axis(&(map->v_matrix[i][j]));
			rotate_vertex(&(map->v_matrix[i][j]));
			j++;
		}
		i++;
	}
}

static void	transform_vmatrix(t_map *const map)
{
	zoom(map);
	center(map);
	rotate(map);
	// amplitude();
	// color();
}

static int	get_map(char *const filename, t_map *map)
{
	char		***string_matrix;

	map->height = get_line_number(filename);
	if (map->height < 0)
		return (-1);
	string_matrix = get_matrix_altitude(filename, map->height);
	//print_matrix_altitude(string_matrix);
	map->width = get_width(string_matrix);
	if (map->width < 0)
		return (-1);
	map->v_matrix = alloc_vertex_matrix(map->width, map->height);
	if (map->v_matrix == NULL)
		return (-1);
	fill_vmatrix(map, string_matrix);
	transform_vmatrix(map);
	free_matrix_altitude(string_matrix);
	return (1);
}

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		close_window(vars);
		mlx_destroy_window(vars->mlx, vars->win);
	}
	return (0);
}
// le mouse_hook me fait segfault !!!!!
// mlx_mouse_hook(vars.win, mouse_hook, &vars);
int	mouse_hook(int m_code, t_vars *vars)
{
	if (m_code == 1)
	{
		close_window(vars);
		mlx_destroy_window(vars->mlx, vars->win);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map		map;
	t_data		img;
	t_vars		vars;

	if (argc != 2)
		return(1);
	if (get_map(argv[1], &map) == -1)
		return (1);
	//print_vertex_matrix(v_matrix, width, height);
	//img = malloc(sizeof(t_data));
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Fdf project");
	img.img = mlx_new_image(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//initialiser la window et l'image dans une fonction
	draw_map(&img, &map);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
    // // // 60 FPS => 60 images par seconde => 1000ms / 60 = 16ms pour créer une image
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 17, close_window, &vars);
    mlx_loop(vars.mlx);
	free_vertex_matrix(map.v_matrix, map.height);
    return (0);
}