/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:40:31 by gaollier          #+#    #+#             */
/*   Updated: 2023/11/15 15:40:50 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*altdest;
	char	*altsrc;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	altdest = (char *)dest;
	altsrc = (char *)src;
	i = 0;
	while (i < n)
	{
			altdest[i] = altsrc[i];
			i++;
	}
	return (dest);
}
