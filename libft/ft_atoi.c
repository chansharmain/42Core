/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:28:48 by shachan           #+#    #+#             */
/*   Updated: 2024/06/12 20:00:11 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	i;
	int	sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9') && nptr[i] != '\0')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	printf("ft_atoi: %d\n", ft_atoi("-123"));
	printf("atoi: %d\n\n", atoi("-123"));

	printf("ft_atoi: %d\n", ft_atoi("  -123"));
	printf("atoi: %d\n\n", atoi("  -123"));

	printf("ft_atoi: %d\n", ft_atoi(" - 123"));
	printf("atoi: %d\n\n", atoi(" - 123"));

	printf("ft_atoi: %d\n", ft_atoi("abc"));
	printf("atoi: %d\n\n", atoi("abc"));

	printf("ft_atoi: %d\n", ft_atoi("123abc"));
	printf("atoi: %d\n\n", atoi("123abc"));

	printf("ft_atoi: %d\n", ft_atoi("--123"));
	printf("atoi: %d\n\n", atoi("--123"));

	printf("ft_atoi: %d\n", ft_atoi("+--123"));
	printf("atoi: %d\n\n", atoi("+--123"));

	printf("ft_atoi: %d\n", ft_atoi(""));
	printf("eatoi: %d\n\n", atoi(""));

	printf("ft_atoi: %d\n", ft_atoi("@123"));
	printf("atoi: %d\n\n", atoi("@123"));

	printf("ft_atoi: %d\n", ft_atoi("-@123"));
	printf("atoi: %d\n\n", atoi("-@123"));
}*/
