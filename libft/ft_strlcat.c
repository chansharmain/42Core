/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:06:04 by shachan           #+#    #+#             */
/*   Updated: 2024/05/27 20:31:19 by shachan          ###   ########.fr       */
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

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t  i;
    size_t  dstlen;
    
    i = 0;
    dstlen = 0;
    if (size > 0)
    {
        while (dst[i] != '\0' && (i < size - 1))
        {
            i++;
            dstlen++;
        }
        while (src[i-dstlen] !=  '\0' && (i < size - 1))
        {
            dst[i] = src [i - dstlen];
            i++;
        }
        dst[i] = '\0';
    }
    return ((ft_strlen(src)) + ft_strlen(dst));
}

#include <stdio.h>
#include <string.h>
int	main()
{
	char	src[] = "Hello";
    char	dest[11] = "World!";
/*
	printf("ft_strlcat: %ld\n", ft_strlcat(dest, src, 3));
    printf("strlcat: %ld\n", strlcat(dest, src, 3));
    printf("dest string is: %s\n", dest);
*/
	printf("ft_strlcat: %ld\n", ft_strlcat(dest, src, 10));
    printf("strlcat: %ld\n", strlcat(dest, src, 10));
    printf("dest string is: %s\n", dest);
 
}