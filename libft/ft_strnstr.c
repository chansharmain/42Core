/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:15:53 by shachan           #+#    #+#             */
/*   Updated: 2024/05/27 22:46:24 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
char *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t  i;
    size_t  j;

    i = 0;
    if (little[i] != '\0')
    {
        while ((big[i] != '\0') && (i < len))
        {
            j = 0;
            while ((big [i + j] != '\0') && (i + j) < len)
            {
                if (big[i + j] == little[i])
                {
                    return ((char*)(big + i));
                }
                j++;
            }
            i++;
            return (NULL);
        }
        return ((char*)(big));
    }
}
