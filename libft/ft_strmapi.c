/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:16:17 by shachan           #+#    #+#             */
/*   Updated: 2024/06/10 01:25:11 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int    i;
    char    *output;

    i = 0;
    output = malloc((ft_strlen(s) + 1) * sizeof(char));
    if ((output == NULL) || (s == NULL) || (f == NULL))
        return (NULL);
    while (s[i] != '\0')
    {
        output[i] = f(i, s[i]);
        i++;
    }
    output[i] = '\0';
    return (output);
}
