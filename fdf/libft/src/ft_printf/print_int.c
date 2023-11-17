/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:18:15 by gaollier          #+#    #+#             */
/*   Updated: 2023/11/15 15:18:38 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

#include "ft_printf.h"

int    print_int(int nb)
{
    char   *str;
    int    len;

    str = ft_itoa(nb);
    if (str == NULL)
        return (-1);
    len = print_str(str);
    free(str);
    if (len < 0)
        return (-1);
    return (len);
}
