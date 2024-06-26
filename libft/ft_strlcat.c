/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:06:04 by shachan           #+#    #+#             */
/*   Updated: 2024/06/12 20:03:52 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size == 0 || size <= dstlen)
	{
		return (size + srclen);
	}
	while (src[i] != '\0' && (i < size - dstlen - 1))
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
/*
#include <bsd/string.h>
#include <stdio.h>

int	main(void)
{
	char	src[] = "Hello";
	char	dest[20] = "World!";
	printf("ft_strlcat: %ld\n", ft_strlcat(dest, src, 3));
	printf("strlcat: %ld\n", strlcat(dest, src, 3));
	printf("dest string is: %s\n", dest);

	char	src2[] = "Hello";
	char	dest2[] = "World!";
	printf("ft_strlcat: %ld\n", ft_strlcat(dest2, src2, 10));
   // printf("strlcat: %ld\n", strlcat(dest2, src2, 10));
	printf("dest string is: %s\n", dest2);

	char	src3[] = "Hello";
	char	dest3[] = "World!";
	printf("strlcat: %ld\n", strlcat(dest3, src3, 10));
	printf("dest string is: %s\n", dest3);

}*/