/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:47:56 by gaollier          #+#    #+#             */
/*   Updated: 2023/11/15 15:48:14 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin_free(char *const s1, char *const s2)
{
	char *const new_s = ft_strjoin(s1, s2);

	free(s1);
	free(s2);
	return (new_s);
}
