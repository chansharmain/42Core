/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:33:14 by shachan           #+#    #+#             */
/*   Updated: 2024/06/14 01:58:35 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

//account for INT_MIN
char	*ft_itoa(int n)
{
	char	*output;
	int		len;
	long	num;

	num = n;
	len = ft_numlen(n);
	output = malloc((len + 1) * sizeof(char));
	if (output == NULL)
		return (NULL);
	output[len] = '\0';
	if (num == 0)
		output[0] = '0';
	if (num < 0)
	{
		output[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		output[--len] = (num % 10) + '0';
		num = num / 10;
	}
	return (output);
}
/*
#include <stdio.h>
#include <limits.h>
int main() {
    printf("%s\n", ft_itoa(INT_MAX));
    printf("%s\n", ft_itoa(INT_MIN));
	printf("%s\n", ft_itoa(-2147483648));
    printf("%s\n", ft_itoa(0));
    printf("%s\n", ft_itoa(123456789));
    return (0);
}*/