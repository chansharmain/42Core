/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:52:10 by shachan           #+#    #+#             */
/*   Updated: 2024/05/25 16:52:11 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char	c;

	c = 'A';
	printf("isprint: %d\n", isprint(c));
	printf("ft_isprint: %d\n", ft_isprint(c));

	c = '1';
	printf("isprint: %d\n", isprint(c));
	printf("ft_isprint: %d\n", ft_isprint(c));

	c = '!';
	printf("isprint: %d\n", isprint(c));
	printf("ft_isprint: %d\n", ft_isprint(c));

	c = ' ';
	printf("isprint: %d\n", isprint(c));
	printf("ft_isprint: %d\n", ft_isprint(c));
}*/