/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:49:39 by shachan           #+#    #+#             */
/*   Updated: 2024/05/27 19:49:01 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = 0;
	if (dstsize > 0)
	{
		while ((src[i] != '\0') && (i < (dstsize - 1)))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[srclen] != '\0')
	{
		srclen++;
	}
	return (srclen);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[] = "Hello World!";
	char	dest[20];

	printf("ft_strlcpy: %ld\n", ft_strlcpy(dest, src, 3));
	printf("strlcpy: %ld\n", strlcpy(dest, src, 3));
	printf("dest string is: %s\n", dest);

	printf("ft_strlcpy: %ld\n", ft_strlcpy(dest, src, 10));
	printf("strlcpy: %ld\n", strlcpy(dest, src, 10));
	printf("dest string is: %s\n", dest);
}*/