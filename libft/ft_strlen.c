/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:51:58 by shachan           #+#    #+#             */
/*   Updated: 2024/05/25 16:52:33 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *s = "hello";
	printf("strlen: %ld\n", strlen(s));
	printf("ft_strlen: %ld\n", ft_strlen(s));

	char *c = "world ";
	printf("strlen: %ld\n", strlen(c));
	printf("ft_strlen: %ld\n", ft_strlen(c));
}*/