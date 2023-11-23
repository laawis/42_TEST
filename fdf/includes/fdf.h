/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:17:00 by gaollier          #+#    #+#             */
/*   Updated: 2023/11/15 14:17:34 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <libft.h>

# define WINDOW_WIDTH	1920
# define WINDOW_HEIGHT	1080

# define MAP_HEIGHT_LIMIT	INT_MAX
# define MAP_WIDTH_LIMIT INT_MAX

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef unsigned int uint;

struct	s_vertex
{
	int		x;
	int		y;
	int		w;
	uint	color;
};
typedef struct	s_vertex t_vertex;

typedef struct	s_map {
	t_vertex	**v_matrix;
	ssize_t			width;
	ssize_t			height;
}				t_map;
/*
typedef struct s_points
{
	t_point	p1;
	t_point	p2;
}				t_points;
*/

int			main(int argc, char **argv);
void		print_matrix_altitude(char ***const matrix_altitude);
char		***fillstring_matrix(char ***matrix_altitude, const char *const filename);
char		***get_matrix_altitude(const char *const filename, const size_t nb_line);
ssize_t		get_line_number(char *const filename);
void		free_strings(char **string_array);
void		free_vertex_matrix(t_vertex **vertex_matrix, size_t height);
void		free_matrix_altitude(char ***matrix_altitude);
void		draw_point(const t_data *const data, const t_vertex vertex);
ssize_t		get_width(char ***matrix_altitude);
t_vertex	**alloc_vertex_matrix(size_t width, size_t height);
t_vertex	**fill_vertex_matrix(t_vertex **vertex_matrix, char ***string_matrix);
void		print_vertex_matrix(t_vertex **const vertex_matrix, size_t width, size_t height);
void		draw_line(const t_data *const data, t_vertex v1, t_vertex v2);
void		draw_map(const t_data * const data, t_vertex **v_matrix, ssize_t *height, ssize_t *width);
void		my_mlx_pixel_put(const t_data *const data, const int x, const int y, const int color);
int			close_window(t_vars *vars);
int			key_hook(int keycode, t_vars *vars);


#endif
