/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 00:46:35 by shachan           #+#    #+#             */
/*   Updated: 2024/05/25 16:08:27 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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

	c = '1';
	printf("isdigit: %d\n", isdigit(c));
	printf("ft_isdigit: %d\n", ft_isdigit(c));

	c = 'A';
	printf("isdigit: %d\n", isdigit(c));
	printf("ft_isdigit: %d\n", ft_isdigit(c));

	c = ' ';
	printf("isdigit: %d\n", isdigit(c));
	printf("ft_isdigit: %d\n", ft_isdigit(c));

	c = '!';
	printf("isdigit: %d\n", isdigit(c));
	printf("ft_isdigit: %d\n", ft_isdigit(c));
}*/