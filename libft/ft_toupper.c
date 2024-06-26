/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:52:03 by shachan           #+#    #+#             */
/*   Updated: 2024/06/12 20:05:53 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char c;

	c = 'A';
	printf("toupper: %c\n", toupper(c));
	printf("ft_toupper: %c\n", ft_toupper(c));

	c = 'a';
	printf("toupper: %c\n", toupper(c));
	printf("ft_toupper: %c\n", toupper(c));

	c = '1';
	printf("toupper: %c\n", toupper(c));
	printf("ft_toupper: %c\n", toupper(c));

	c = ' ';
	printf("toupper: %c\n", toupper(c));
	printf("ft_toupper: %c\n", toupper(c));

	c = '!';
	printf("toupper: %c\n", toupper(c));
	printf("ft_toupper: %c\n", ft_toupper(c));
}*/