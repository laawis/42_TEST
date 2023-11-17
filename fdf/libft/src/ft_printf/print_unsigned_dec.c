/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_dec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:21:01 by gaollier          #+#    #+#             */
/*   Updated: 2023/11/15 15:21:09 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_printf.h"

static int	dec_len(unsigned int nb)
{
	int    len;

	len = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}


static char *dec_itoa(unsigned int nb)
{
    char    *str;
    int     len;

    len = dec_len(nb);
    str = malloc(sizeof(*str) * (len + 1));
    if (str == NULL)
        return (NULL);
    str[len] = '\0';
    while (nb > 0)
    {
        str[len - 1] = nb % 10 + '0';
        
        nb /= 10;
        len--;
    }
    return (str);
}

int    print_unsigned_dec(unsigned int nb)
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
        str = dec_itoa(nb);
        if (str == NULL)
            return (-1);
        len = print_str(str);
        free(str);
        if(len <= 0)
            return (-1);
    }
    return (len);
}
