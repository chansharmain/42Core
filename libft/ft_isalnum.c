/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:00:59 by shachan           #+#    #+#             */
/*   Updated: 2024/05/25 16:01:15 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
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
	printf("isalnum: %d\n", isalnum(c));
	printf("ft_isalnum: %d\n", ft_isalnum(c));

	c = '1';
	printf("isalnum: %d\n", isalnum(c));
	printf("ft_isalnum: %d\n", ft_isalnum(c));

	c = 'a';
	printf("isalnum: %d\n", isalnum(c));
	printf("ft_isalnum: %d\n", ft_isalnum(c));
	
	c = '!';
	printf("isalnum: %d\n", isalnum(c));
	printf("ft_isalnum: %d\n", ft_isalnum(c));
	
	c = ' ';
	printf("isalnum: %d\n", isalnum(c));
	printf("ft_isalnum: %d\n", ft_isalnum(c));
}*/