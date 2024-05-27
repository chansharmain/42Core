/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:49:39 by shachan           #+#    #+#             */
/*   Updated: 2024/05/27 01:48:13 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t  i;
    size_t  srclen;

    i = 0;
    srclen = 0;
    if (dstsize > 0)
    {
        while (src[srclen] != '\0')
        {
            srclen++;
        }
        while ((src[i] != '\0') && (i < dstsize - 1))
        {
            dst[i] == src[i];
            i++;
        }
        dst[i] == '\0';
        return (srclen);
    }
}

#include <stdio.h>
#include <string.h>
int	main()
{
	char	src[] = "Hello World!";
    char	dest[20] = "xxxxxxxxxxxxxxxxxxx";
	//ft_strlcpy(dest, src, 3);
	printf("ft_strlcpy: %ld\n", ft_strlcpy(dest, src, 3));
    printf("dest string is: %s\n", dest);

    printf("strlcpy: %ld\n", strlcpy(dest, src, 3));
}