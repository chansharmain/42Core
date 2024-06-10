/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:32:17 by shachan           #+#    #+#             */
/*   Updated: 2024/06/10 23:13:31 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int  ft_wordcount(char const *s, char c)
{
    int i;
    int word_count;

    i = 0;
    word_count = 0;
    while (s[i] != '\0' && s[i] == c)
        i++;
    while (s[i] != '\0')    
    {
        if ((s[i] == c) && (s[i + 1] != c))
            word_count++;
        i++;
    }
    if ((s[i] == '\0') && (s[i - 1] != c) && i != 0)
        word_count++;
    return (word_count);
}

static char *ft_wordcpy(char const *s, int start, int end)
{
    char    *output;
    int i;
    
    i = 0;
    output = malloc(sizeof(char) * (end - start + 1));
    if (output == NULL)
        return (NULL);
    while (start < end)
    {
        output[i] = s[start];
        i++;
        start++;
    }
}



char	**ft_split(char const *s, char c)
{
    
}



#include <stdio.h>
int main()
{
    char *s = " .?";
    int i = ft_wordcount(s, '.');
    printf("%d\n", i);
}