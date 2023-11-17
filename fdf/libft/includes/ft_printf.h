/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:11:55 by gaollier          #+#    #+#             */
/*   Updated: 2023/11/15 15:12:15 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>

#include "libft.h"

int    ft_printf(const char *format, ...);
int    print_str(char *str);
int    print_ptr(unsigned long long nb);
int    print_int(int nb);
int    print_unsigned_dec(unsigned int nb);
int    print_low_hex(unsigned int nb);
int    print_up_hex(unsigned int nb);
int    hex_len(unsigned int nb);

#endif
