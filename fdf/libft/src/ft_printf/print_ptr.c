/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:19:26 by gaollier          #+#    #+#             */
/*   Updated: 2023/11/15 15:19:38 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_printf.h"

static int	len_ptr(unsigned long long nb)
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

static char *hex_itoa(unsigned long long nb)
{
    char    *str;
    int     len;

    len = len_ptr(nb);
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

int    print_ptr(unsigned long long nb)
{
    int     len;
    int     len_tmp;
    char    *str;

    len_tmp = 0;
    len = 0;
    if (nb == 0)
    {
        if (write(1, "(nil)", 5) <= 0)
			return (-1);
		return (5);
    }
    else if (nb > 0)
    {
        str = hex_itoa(nb);
        if (str == NULL)
            return (-1);
        len += write(1, "0x", 2);
        if (len <= 0)
            return (-1);
        len_tmp = print_str(str);
        free(str);
        if(len_tmp <= 0)
            return (-1);
        len += len_tmp;
    }
    return (len);
}
