/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_functions2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:23:05 by shachan           #+#    #+#             */
/*   Updated: 2024/07/12 00:23:16 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base2(unsigned long long n, char *base)
{
	// int	baselen;
	// int	count;
	unsigned long long	baselen;
	unsigned long long	count;

	baselen = 0;
	while (base[baselen] != '\0')
		baselen++;
	if (baselen < 1)
		return (0);
	count = 0;
	if (n >= baselen)
		count += ft_putnbr_base(n / baselen, base);
	count += ft_putchar(base[n % baselen]);
	return (count);
}
