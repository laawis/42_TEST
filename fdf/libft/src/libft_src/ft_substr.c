/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:52:32 by gaollier          #+#    #+#             */
/*   Updated: 2023/11/15 15:52:45 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start,size_t len)
{
	char	*str;

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	while (*s)
	{
		if ((*s >= *(s + start)) && (*(s + (size_t)start) < *(s + (size_t)start + len)))
		{
			*str = *s;
			str++;
			start++;
		}
		s++;
	}
	*str = '\0';
	return (str);
}

