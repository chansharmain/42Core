/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:03:10 by shachan           #+#    #+#             */
/*   Updated: 2024/05/25 16:04:38 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >='A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	char	c;

	c = 'A';
	printf("isalpha: %d\n", isalpha(c));
	printf("ft_isalpha: %d\n", ft_isalpha(c));

	c = 'a';
	printf("isalpha: %d\n", isalpha(c));
	printf("ft_isalpha: %d\n", ft_isalpha(c));

	c = '1';
	printf("isalpha: %d\n", isalpha(c));
	printf("ft_isalpha: %d\n", ft_isalpha(c));

	c = ' ';
	printf("isalpha: %d\n", isalpha(c));
	printf("ft_isalpha: %d\n", ft_isalpha(c));

	c = '!';
	printf("isalpha: %d\n", isalpha(c));
	printf("ft_isalpha: %d\n", ft_isalpha(c));
}*/