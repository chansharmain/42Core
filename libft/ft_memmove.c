/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 00:29:56 by shachan           #+#    #+#             */
/*   Updated: 2024/06/05 01:36:31 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
void *ft_memmove(void *dst, const void *src, size_t n)
{
    size_t  i; 

    i = 0;
    if (dst == NULL || src == NULL)
        return (NULL);
    if (dst > src)
    {
        while (n > 0)
        {
           ((unsigned char *)dst)[n-1] = ((unsigned char *)src)[n-1];
            n--;  
        }
    }
    else
    {
        while (i < n)
        {
            ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
            i++;
        }
    }
    return (dst);
}