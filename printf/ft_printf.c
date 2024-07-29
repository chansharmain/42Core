/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 01:17:34 by shachan           #+#    #+#             */
/*   Updated: 2024/07/29 23:30:16 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_specifier(char fs, va_list arg_ptr)
{
	int	count;

	count = 0;
	if (fs == 'c')
		count += ft_putchar(va_arg(arg_ptr, int));
	else if (fs == 's')
		count += (ft_putstr(va_arg(arg_ptr, char *)));
	else if (fs == 'p')
		count += ft_putpointer(va_arg(arg_ptr, unsigned long long));
	else if ((fs == 'd') || (fs == 'i'))
		count += ft_putnbr_base(va_arg(arg_ptr, int), "0123456789");
	else if (fs == 'u')
		count += ft_putunsigned(va_arg(arg_ptr, unsigned int));
	else if (fs == 'x')
		count += ft_putnbr_base(va_arg(arg_ptr, unsigned int),
				"0123456789abcdef");
	else if (fs == 'X')
		count += ft_putnbr_base(va_arg(arg_ptr, unsigned int),
				"0123456789ABCDEF");
	else if (fs == '%')
		count += ft_putchar('%');
	else
		count += ft_putchar(fs);
	return (count);
}

int	ft_printf(const char *formatted_string, ...)
{
	va_list	arg_ptr;
	int		count;
	int		i;

	i = 0;
	va_start(arg_ptr, formatted_string);
	count = 0;
	while (formatted_string[i] != '\0')
	{
		if (formatted_string[i] == '%')
		{
			if (formatted_string[i + 1] != '\0')
			{
				count += ft_format_specifier(formatted_string[i + 1], arg_ptr);
				i++;
			}
		}
		else
			count += ft_putchar(formatted_string[i]);
		i++;
	}
	va_end (arg_ptr);
	return (count);
}

// #include <limits.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int	ft_count;
// 	int count;

// 	ft_count = 0;
// 	count = 0;
// 	char *s;
// 	char c;
// 	s = "helloworld";
// 	c = 'b';

// 	printf("1. Test case for c output\n");
// 	ft_count = ft_printf("ft_printf: This is a char: %c\n", c);
// 	printf("Chars printed: %d\n", ft_count);
// 	count = printf("og_printf: This is a char: %c\n", c);
// 	printf("Chars printed: %d\n\n", count);
// 	printf("======================================\n");

// 	printf("2. Test case for s output\n");
// 	ft_count = ft_printf("ft_printf: This is a string: %s\n", s);
// 	printf("Chars printed: %d\n", ft_count);
// 	count = printf("og_printf: This is a string: %s\n", s);
// 	printf("Chars printed: %d\n\n", count);
// 	printf("======================================\n");

// 	printf("3. Test case for p output\n");
// 	ft_count = ft_printf("ft_printf: Pointer: %p\n", s);
// 	printf("Chars printed: %d\n", ft_count);
// 	count = printf("og_printf: Pointer: %p\n", s);
// 	printf("Chars printed: %d\n\n", count);
// 	printf("======================================\n");

// 	printf("4. Test case for i/d output\n");
// 	ft_count = ft_printf("ft_printf: Numbers: %i %d %i %d\n",
// 	 -1, 100, INT_MAX, INT_MIN);
// 	printf("Chars printed: %i\n", ft_count);
// 	count = printf("og_printf: Numbers: %i %d %i %d\n",
// 	 -1, 100, INT_MAX, INT_MIN);
// 	printf("Chars printed: %i\n\n", count);
// 	printf("======================================\n");

// 	printf("5. Test case for u output\n");
// 	ft_count = ft_printf("ft_printf: Unsigned: %u %u %u %u\n",
// 	 10, -10, -2147483647, INT_MIN);
// 	printf("Chars printed: %i\n", ft_count);
// 	count = printf("og_printf: Unsigned: %u %u %u %u\n",
// 	 10, -10, -2147483647, INT_MIN);
// 	printf("Chars printed: %i\n\n", count);
// 	printf("======================================\n");

// 	printf("6. Test case for x/X output\n");
// 	ft_count = ft_printf("ft_printf: Unsigned: %x %x %X %x %X\n",
// 	 10, -10, 16, 123, INT_MAX);
// 	printf("Chars printed: %i\n", ft_count);
// 	count = printf("og_printf: Unsigned: %x %x %X %x %X\n",
// 	 10, -10, 16, 123, INT_MAX);
// 	printf("Chars printed: %i\n\n", count);
// 	printf("======================================\n");

// 	printf("7. Test case for percent output\n");
// 	ft_count = ft_printf("ft_printf: Unsigned: %%\n");
// 	printf("Chars printed: %i\n", ft_count);
// 	count = printf("og_printf: Unsigned: %%\n");
// 	printf("Chars printed: %i\n\n", count);
// 	printf("======================================\n");

// 	printf("8. Test case for combined outputs\n");
// 	ft_count = ft_printf("ft_printf: %s %c %d\n", s, c, 10);
// 	printf("Chars printed: %i\n", ft_count);
// 	count = printf("og_printf: %s %c %d\n", s, c, 10);
// 	printf("Chars printed: %i\n\n", count);
// 	printf("======================================\n");

// 	ft_printf("9. Test case for other outputs\n");
// 	ft_count = ft_printf("%\n");
// 	ft_printf("Chars printed: %i\n", ft_count);
// 	ft_count = ft_printf("%a\n");
// 	ft_printf("Chars printed: %i\n", ft_count);
// 	ft_count = ft_printf("%%%\n");
// 	ft_printf("Chars printed: %i\n", ft_count);
// 	printf("======================================\n");
// }