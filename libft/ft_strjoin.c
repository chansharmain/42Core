/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 01:25:27 by shachan           #+#    #+#             */
/*   Updated: 2024/06/07 02:00:52 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

// remove above

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t i;
    size_t j;
    char *output;

    i = 0;
    j = 0;
    if (s1 == NULL || s2 == NULL)
        return (NULL);
    output = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (output == NULL)
        return (NULL);
    while (i < ft_strlen(s1))
    {
        output[i] = s1[i];
        i++;
    }
    while (j < ft_strlen(s2))
    {
        output[i + j] = s2[j];
        j++;
    }
    output[i + j] = '\0';
    return (output);    
}
/*
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *s1 = "Hello ";
    const char *s2 = "world!";
    
    char *result = ft_strjoin(s1, s2);
    if (result != NULL) {
        printf("Concatenated string: %s\n", result);
        free(result); // Freeing the memory allocated by ft_strjoin
    } else {
        printf("Error: Memory allocation failed.\n");
    }
    
    return 0;
}*/