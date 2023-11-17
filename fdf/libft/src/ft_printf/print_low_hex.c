/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_low_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:18:49 by gaollier          #+#    #+#             */
/*   Updated: 2023/11/15 15:19:12 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "ft_printf.h"

int	hex_len(unsigned int nb)
{
	int    len;

	len = 0;
	while (nb > 0)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}

static char *hex_itoa(unsigned int nb)
{
    char    *str;
    int     len;

    len = hex_len(nb);
    str = malloc(sizeof(*str) * (len + 1));
    if (str == NULL)
        return (NULL);
    str[len] = '\0';
    while (nb > 0)
    {
        if (nb % 16 <= 9)
            str[len - 1] = nb % 16 + '0';
        else if (nb % 16 >= 10 && nb % 16 <= 15)
            str[len -1] = nb % 16 + 'W';
        nb /= 16;
        len--;
    }
    return (str);
}

int    print_low_hex(unsigned int nb)
{
    int     len;
    char    *str;

    if (nb == 0)
    {
        if (write(1, "0", 1) <= 0)
			return (-1);
		return (1);
    }
    else
    {
        str = hex_itoa(nb);
        if (str == NULL)
            return (-1);
        len = print_str(str);
        free(str);
        if(len <= 0)
            return (-1);
    }
    return (len);
}
