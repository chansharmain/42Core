/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:47:55 by shachan           #+#    #+#             */
/*   Updated: 2024/06/12 20:01:21 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (((((unsigned char *)str1)[i] != '\0') || ((unsigned char *)str2)[i])
		&& i < n)
	{
		if (((unsigned char *)str1)[i] != ((unsigned char *)str2)[i])
		{
			return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main ()
{
	char s1[] = "Hello";
	char s2[] = "hello";
	char s3[] = "Help";

	printf("memcmp:%d\n", memcmp(s1, s2, 4));
	printf("ft_memcmp:%d\n", ft_memcmp(s1, s2, 4));

	printf("memcmp:%d\n", memcmp(s1, s3, 4));
	printf("ft_memcmp:%d\n", ft_memcmp(s1, s3, 4));
}*/