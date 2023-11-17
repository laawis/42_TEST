/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:22:42 by gaollier          #+#    #+#             */
/*   Updated: 2023/11/15 15:22:54 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "get_next_line.h"
#include "libft.h"

char *get_next_line(int fd)
{
  static char buf[OPEN_MAX][BUFFER_SIZE];
  char *line_tmp;
  char *line;

  if (BUFFER_SIZE <= 0 || fd < 0)
    return (NULL);
  if (check_empty_buf(buf[fd], BUFFER_SIZE))
  {
    if (read(fd, buf[fd], BUFFER_SIZE) <= 0)
      return (NULL);
  }
  line = extract_line(buf[fd], BUFFER_SIZE);
  while (line != NULL && !ft_strchr(line, '\n'))
  {
    if (read(fd, buf[fd], BUFFER_SIZE) == 0)
      return (line);
    line_tmp = extract_line(buf[fd], BUFFER_SIZE);
    if (line_tmp == NULL)
    {
      free(line);
      return (NULL);
    }
    line = ft_strjoin_free(line, line_tmp);
  }
  return (line);
}

int check_empty_buf(const char *buf, size_t buffer_size)
{
   size_t i;

  i = 0;
  while (i < buffer_size)
  {
    if (buf[i] != '\0')
      return (0);
    i++;
  }
  return (1);
}

char *extract_line(char *buf, size_t buffer_size)
{
  char *line;
  size_t index_start;
  size_t len;

  index_start = get_start_line(buf, buffer_size);
  len = get_line_len(buf, buffer_size, index_start);
  line = sub_line_in_buf(buf, index_start, len);
  return (line);
}

size_t get_line_len(char *buf, size_t buffer_size, size_t index_start)
{
  size_t len;

  len = 0;
  while (index_start < buffer_size && buf[index_start] != '\n' &&
         buf[index_start] != '\0')
  {
    index_start++;
    len++;
  }
  if (index_start < buffer_size && buf[index_start] == '\n')
    len++;
  return (len);
}

size_t get_start_line(char *buf, size_t buffer_size)
{
  size_t i;

  i = 0;
  while (i < buffer_size && buf[i] == '\0')
    i++;
  return (i);
}
