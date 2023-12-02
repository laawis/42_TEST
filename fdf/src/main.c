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
static void	altitude_vertex(t_vertex *vertex)
{
	vertex->x += (vertex->w * 4);
	//vertex->y += (vertex->w * 2);
}

static void	altitude(const t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			altitude_vertex(&map->v_matrix[i][j]);
			++j;
		}
		++i;
	}
}

static void	shift_map(t_map *map, float shift_y, float shift_x)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j= 0;
		while (j < map->width)
		{
			map->v_matrix[i][j].x += shift_x; 
			map->v_matrix[i][j].y += shift_y;
			j++;
		}
		i++;
	}
}

static void	shift_map_from_center(t_map *map, float x, float y) {
	shift_map(map, -y, -x); // decale en haut a gauche le centre
}

static void	shift_map_to_center(t_map *map, float x, float y) {
	shift_map(map, y, x); // remet la map au centre
}

// // // shift_map_from_center();
// // // rotate();
// // // shift_map_to_center();

// // // static void rotate_vertex(t_map *map, t_vertex vertex)
// // static void rotate_vertex(t_vertex *vertex)
// // {
// // 	const double	theta = M_PI_4; // a mettre en define
// // 	const int		prev = vertex->x;

// // 	vertex->x = prev * cos(theta) - vertex->y * sin(theta);
// // 	vertex->y = vertex->y * cos(theta) + prev * sin(theta);
// // 	// vertex->x = (((prev - vertex->y) * 2) - (vertex->y * 2));
// // 	// vertex->y = (((vertex->y + prev) * 2) + (prev * 2));
// // 	//vertex->x = vertex->y * ((WINDOW_WIDTH / map->width) / 4);
// // 	//vertex->y = vertex->y * ((WINDOW_WIDTH / map->width) / 4);
// // }



 static void rotate_vertex(t_vertex *vertex)
{	
	const double	theta = (M_PI / 180) * 20; // conversion en radian = (M_PI / 180) * (angle en degres)
	const double	prev_x = vertex->x;
	const double	prev_y = vertex->y;

	vertex->x = round(prev_x * cos(theta) - prev_y * sin(theta));
	vertex->y = round(prev_x * sin(theta) + prev_y * cos(theta));
	
	// vertex->x = (((prev - vertex->y) * 2) - (vertex->y * 2));
	// vertex->y = (((vertex->y + prev) * 2) + (prev * 2));
	//vertex->x = vertex->y * ((WINDOW_WIDTH / map->width) / 4);
	//vertex->y = vertex->y * ((WINDOW_WIDTH / map->width) / 4);
}

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
	shift_map_from_center(map, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	rotate(map);
	shift_map_to_center(map, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	altitude(map);
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
	draw_map(&img, map);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
    // // // 60 FPS => 60 images par seconde => 1000ms / 60 = 16ms pour créer une image
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 17, close_window, &vars);
    mlx_loop(vars.mlx);
	free_vertex_matrix(map.v_matrix, map.height);
    return (0);
}