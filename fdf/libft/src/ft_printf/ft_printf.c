/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:17:07 by gaollier          #+#    #+#             */
/*   Updated: 2023/11/15 15:17:52 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#include "ft_printf.h"

static int    print_conv(va_list args, char c)
{
    int    count;

    count = 0;
    if (c == 'c')
        count = write(1, &c, 1);
    else if (c == 's')
        count = print_str(va_arg(args, char *));
    else if (c == 'p')
        count = print_ptr(va_arg(args, unsigned long long));
    else if (c == 'd' || c == 'i')
        count = print_int(va_arg(args, int));
    else if (c == 'u')
        count = print_unsigned_dec(va_arg(args, unsigned int));
    else if (c == 'x')
        count = print_low_hex(va_arg(args, unsigned int));
    else if (c == 'X')
        count = print_up_hex(va_arg(args, unsigned int));
    else if (c == '%')
        count = write(1, "%", 1);
    if (count <= 0)
        return (-1);
    return (count);
}

static int    is_in_string(char c, char *s)
{
    while (*s != '\0')
    {
        if (*s == c)
            return (1);
        s++;
    }
    return (0); // return (c == *s); ????
}

static int    conversion(va_list args, char c)
{
    if (is_in_string(c, "cspdiuxX%") == 1)
        return (print_conv(args, c));
    else
    {
        if (write(1, "%", 1) <= 0)
            return (-1);
        if (write(1, &c, 1) <= 0)
            return (-1);
        return (2);
    }

}

int    ft_printf(const char *format, ...)
{
	va_list	args;
    int    count;

    count = 0;
    if (format == NULL)
        return (0);
    va_start(args, format);
    while (*format != '\0')
    {
        if (*format != '%')
        {
            count += write(1, format, 1);
            if (count <= 0)
                return (-1);
        }
        else if (*(format + 1) != '\0')
        {
                format++;
                count += conversion(args, *format);
                if (count <= 0)
                    return (-1);
        }
        format++;
    }
    va_end(args);
    return (count);
}
