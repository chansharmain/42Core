/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:51:46 by shachan           #+#    #+#             */
/*   Updated: 2024/05/27 22:13:51 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
int ft_strncmp(const char *str1, const char *str2, size_t n)
{
    size_t  i;
    i = 0;
    
    while ((str1[i] != '\0' || str2[i] != '\0') && i < n)
    {
        if (str1[i] != str2[i])
        {
            return (str1[i] - str2[i]);
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

    printf("strncmp:%d\n", strncmp(s1, s2, 4));
    printf("ft_strncmp:%d\n", ft_strncmp(s1, s2, 4));

    printf("strncmp:%d\n", strncmp(s1, s3, 4));
    printf("ft_strncmp:%d\n", ft_strncmp(s1, s3, 4)); 
}*/
    
