/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 01:17:34 by shachan           #+#    #+#             */
/*   Updated: 2024/07/06 16:36:11 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_format_specifier(char fs, va_list arg_ptr)
{
	int	count;

	count = 0;
	if (fs == 'c')
		count += ft_putchar(va_arg(arg_ptr, int));
	else if (fs == 's')
		count += ft_putstr(va_arg(arg_ptr, char*));
	else if (fs == 'p')
		count += ft_putpointer(va_arg(arg_ptr, unsigned long long));
	else if ((fs == 'd') || (fs == 'i'))
		count += ft_putnbr_base(va_arg(arg_ptr, int), "0123456789");
	else if (fs == 'u')
		count += ft_putunsigned(va_arg(arg_ptr, unsigned int));
	else if (fs == 'x')
		count += ft_putnbr_base(va_arg(arg_ptr, long unsigned int), "0123456789abcdef");
	else if (fs == 'X')
		count += ft_putnbr_base(va_arg(arg_ptr, long unsigned int), "0123456789ABCDEF");		
	else if (fs == '%')
		count += ft_putchar('%');
	else
		count += ft_putchar(fs);
	return(count);
}

int	ft_printf(const char *formatted_string, ...)
{
	va_list	arg_ptr;
	int	count;
	int	i;

	va_start(arg_ptr, formatted_string);
	count = 0;
	while (formatted_string[i] != '\0')
	{
		if (formatted_string[i] == '%')
			count += ft_format_specifier(formatted_string[++i], arg_ptr);
		else
			count += write(1, &formatted_string[i], 1);
		i++;
	}
	va_end (arg_ptr);
	return(count);
}
