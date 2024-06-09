/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 01:22:07 by shachan           #+#    #+#             */
/*   Updated: 2024/06/07 00:48:24 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
void *ft_memset(void *str, int c, size_t n)
{
    size_t  i;

    i = 0;
    while (i < n)
    {
        ((unsigned char*)str)[i] = (unsigned char)c;
        i++; 
    }
    return (str);
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*int	main()
{
	char s1[] = "hello";
	char s2[] = "hello";

	printf("memset: %s\n", (char*)memset(s1, 'y', 5));
	printf("ft_memset: %s\n", (char*)ft_memset(s2, 'y', 5));

    char s3[] = "hello";
	char s4[] = "hello";

	printf("memset: %s\n", (char*)memset(s3, 'y', 6));
	printf("ft_memset: %s\n", (char*)ft_memset(s4, 'y', 6));

    char s5[] = "hello";
	char s6[] = "hello";

	printf("memset: %s\n", (char*)memset(s5, 'y', 7));
	printf("ft_memset: %s\n", (char*)ft_memset(s6, 'y', 7));
}*/
