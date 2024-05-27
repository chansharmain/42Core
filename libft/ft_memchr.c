/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:01:47 by shachan           #+#    #+#             */
/*   Updated: 2024/05/25 19:55:34 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
void *ft_memchr(const void *s, int c, size_t n)
{
    size_t    i;

    i = 0;
    while (i < n)
    {
        if (((unsigned char *)s)[i] == (unsigned char)c)
        {
            return ((void*)(s + i));
        }
        i++;
    }
    return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int main ()
{
    char s[] = "Hello World!";
    
    printf("input: Hello World!\nchar: e\nn: 1 \n");
    printf("memchar: %s\n", (char *)memchr(s, 'e', 1));
    printf("ft_memchar: %s\n", (char *)ft_memchr(s, 'e', 1));
    printf("memchar add: %p\n", memchr(s, 'e', 1));
    printf("ft_memchar add: %p\n", ft_memchr(s, 'e', 1));

    printf("input: Hello World!\nchar: e\nn: 3 \n");
    printf("memchar: %s\n", (char *)memchr(s, 'e', 3));
    printf("ft_memchar: %s\n", (char *)ft_memchr(s, 'e', 3));
    printf("memchar add: %p\n", memchr(s, 'e', 3));
    printf("ft_memchar add: %p\n", ft_memchr(s, 'e', 3)); 
}*/