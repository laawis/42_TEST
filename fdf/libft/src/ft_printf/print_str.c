/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:20:06 by gaollier          #+#    #+#             */
/*   Updated: 2023/11/15 15:20:24 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

#include "ft_printf.h"

int print_str(char *str)
{
    if (str == NULL)
    {
        return (-1);
    }
	return (write(1, str, ft_strlen(str)));
}
