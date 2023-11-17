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

#include "fdf.h"
#include "libft.h"

// gcc main.c -I minilibx_macos -L minilibx_macos -l mlx -framework OpenGL -framework AppKit

/*
- Vecteur (additionner, soustraire, multiplier / diviser)
- Produit vectorielle / Produit scalaire
- Matrice 3x3 et 4x4
- Algorithme de brensham (tracer des lignes)
*/

static t_vertex	**get_map(char *const filename, ssize_t *height, ssize_t *width)
{
	char		***string_matrix;
	t_vertex	**vertex_matrix;

	*height = get_line_number(filename);
	if (height < 0)
		return (NULL);
	string_matrix = get_matrix_altitude(filename, *height);
	//print_matrix_altitude(string_matrix);
	*width = get_width(string_matrix);
	if (width < 0)
		return (NULL);
	vertex_matrix = alloc_vertex_matrix(*width, *height);
	if (vertex_matrix == NULL)
		return (NULL);
	fill_vertex_matrix(vertex_matrix, string_matrix);
	//print_vertex_matrix(vertex_matrix, width, height);
	free_matrix_altitude(string_matrix);
	(void)string_matrix;
	return (vertex_matrix);
}
// mettre tout ca dans des belles fonctions qui donnent une t_map

int	main(int argc, char **argv)
{
	t_vertex 	**v_matrix;
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	ssize_t		height;
	ssize_t		width;
	
	height = 0;
	width = 0;
	
	(void)argc;

	v_matrix = get_map(argv[1], &height, &width);
	if (v_matrix == NULL)
		return (1);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Fdf project");
	img.img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw_map(&img, v_matrix, &height, &width);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    // // // 60 FPS => 60 images par seconde => 1000ms / 60 = 16ms pour créer une image
    mlx_loop(mlx);
	free_vertex_matrix(v_matrix, height);
    return (0);
}