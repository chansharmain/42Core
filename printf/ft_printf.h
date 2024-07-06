/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 01:20:36 by shachan           #+#    #+#             */
/*   Updated: 2024/07/06 16:35:24 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINT_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>

static int	ft_format_specifier(char fs, va_list arg_ptr);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putpointer(unsigned long long n);
//int	ft_putnbr(long n);
int	ft_putunsigned();
int	ft_putnbr_base(long n, char *base);

int	ft_printf(const char *formatted_string, ...);

#endif