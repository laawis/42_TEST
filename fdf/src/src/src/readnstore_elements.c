/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readnstore_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:30:17 by gaollier          #+#    #+#             */
/*   Updated: 2023/11/15 14:47:14 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <fcntl.h>

#include "fdf.h"

static void	rm_newline_char_instring(char *const line)
{
	const size_t	len = ft_strlen(line);

	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}
char	***fillstring_matrix(char ***matrix_altitude, const char *const filename)
{
	const int	fd = open(filename, O_RDONLY);
	// on doit initialise un const en meme temps que ça declaration
	char		*line;
	size_t		i;

	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (line != NULL)
	{
		rm_newline_char_instring(line);
		matrix_altitude[i] = ft_split(line, ' ');
		if (matrix_altitude[i] == NULL)
		{
			free_matrix_altitude(matrix_altitude);
			return (NULL);
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	matrix_altitude[i] = NULL;
	if (close(fd) == -1)
		return (NULL);
	return (matrix_altitude);
}

char ***get_matrix_altitude(const char *const filename, const size_t nb_line)
{
	char	***matrix_altitude;
	// Lorsque tu dereference 3fois un triple pointeur de char la variable devient un char

	matrix_altitude = (char ***)malloc(sizeof(char**) * (nb_line + 1));
	if (matrix_altitude == NULL)
		return (NULL);
	matrix_altitude = fillstring_matrix(matrix_altitude, filename);
	if (matrix_altitude == NULL)
		return (NULL);
	return (matrix_altitude);
}

ssize_t	get_line_number(char *const filename)
{
	const int	fd = open(filename, O_RDONLY);
	ssize_t		nb_line;
	char		*line;

	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	if (line == NULL)
		return (-1);
	nb_line = 0;
	while (line != NULL && nb_line < MAP_HEIGHT_LIMIT)
	{
		free(line);
		line = get_next_line(fd);
		nb_line++;
	}
	if (close(fd) == -1 || nb_line > MAP_HEIGHT_LIMIT)
		return (-1);
	return (nb_line);
}
