/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:25:55 by gaollier          #+#    #+#             */
/*   Updated: 2023/11/15 15:26:11 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "get_next_line.h"

char *sub_line_in_buf(char *s, size_t index_start, size_t len)
{
  char *str;
  size_t i;

  if (!s)
    return (NULL);
  str = malloc(sizeof(char) * (len + 1));
  if (!str)
    return (NULL);
  i = 0;
  while (i < len)
  {
    str[i] = s[index_start + i];
    s[index_start + i] = '\0';
    i++;
  }
  str[i] = '\0';
  return (str);
}
