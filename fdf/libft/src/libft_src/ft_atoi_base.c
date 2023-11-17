/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:28:02 by gaollier          #+#    #+#             */
/*   Updated: 2023/11/15 15:28:34 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

size_t    ft_strlen(const char *str)
{
    size_t    i = 0;

    while(str[i] != '\0')
        i++;
    return (i);
}

static int    is_doublon(const char *base)
{
    int    i = 0;
    int    j;

    while (base[i] != '\0')
    {
        j = 0;
        while (base[j] != '\0')
        {
            if (j != i && base[j] == base[i])
                return (1);
            else
                j++;
        }
        i++;
    }
    return (0);
}

static int    is_valid_base(const char *base)
{
    int    i = 0;

    if (base == NULL || ft_strlen(base) == 1 || is_doublon(base) == 1)
        return (0);
    while (base[i] != '\0')
    {
        if (base[i] == '-' || base[i] == '+' || ft_strlen(base) == 1 || base[i] == ' ' || base[i] == '\t'
            || base[i] == '\n')
            return (0);
        i++;
    }
    return (1);
}

static int    get_position(const char *base, char c)
{
    int    i = 0;

    while (base[i] != '\0')
    {
        if (base[i] == c)
            return (i);
        i++;
    }
    return (-1);
}

int     ft_atoi_base(const char *str, const char *base)
{
    int    i = 0;
    int    sign = 1;
    int    res = 0;
    int    len_base;

    if (str == NULL || is_valid_base(base) == 0)
        return (0);
    while (str[i] != '\0' && (str[i] == '\n' || str[i] == '\t' || str[i] == ' '))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    len_base = ft_strlen(base);
    while (str[i] != '\0')
    {
		// str[i] on veut trouver son index dans la base
		// i index dans la str
		// str = "qwdqda"
		// i = 5;
		// 'a'
		// Base => "bcdea"
        if (get_position(base, str[i]) == -1)
            return (res);
        res = res * len_base + get_position(base, str[i]);
		// str[i] = '0' -> '9'
		// str[i] - '0' => 0 et 9
        i++;
    }
    return (res * sign);
}
