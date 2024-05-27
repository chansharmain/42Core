/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:52:16 by shachan           #+#    #+#             */
/*   Updated: 2024/05/25 16:52:17 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main()
{
	char	c;

	c = 'A';
	printf("isascii: %d\n", isascii(c));
	printf("ft_isascii: %d\n", ft_isascii(c));

	c = '1';
	printf("isascii: %d\n", isascii(c));
	printf("ft_isascii: %d\n", ft_isascii(c));

	c = '!';
	printf("isascii: %d\n", isascii(c));
	printf("ft_isascii: %d\n", ft_isascii(c));

	c = ' ';
	printf("isascii: %d\n", isascii(c));
	printf("ft_isascii: %d\n", ft_isascii(c));

	c = 128;
	printf("isascii: %d\n", isascii(c));
	printf("ft_isascii: %d\n", ft_isascii(c));	
}*/