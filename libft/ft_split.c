/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:32:17 by shachan           #+#    #+#             */
/*   Updated: 2024/06/14 01:57:48 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// string mem and array mem
static void	ft_freemem(char **s, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free (s[i]);
		i++;
	}
	free (s);
}

//count num of words 
static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if ((s[i] == c) && (s[i - 1] != c))
			word_count++;
		i++;
	}
	if ((s[i] == '\0') && (s[i - 1] != c) && i != 0)
		word_count++;
	return (word_count);
}

// find word length, assign mem and extract word
static char	*ft_wordarr(char const *s, int start, int end)
{
	char	*word_arr;
	int		i;

	i = 0;
	word_arr = malloc(sizeof(char) * (end - start + 1));
	if ((word_arr == NULL) || (s == NULL))
		return (NULL);
	while (start < end)
	{
		word_arr[i] = s[start];
		i++;
		start++;
	}
	word_arr[i] = '\0';
	return (word_arr);
}

char	**ft_split(char const *s, char c)
{
	char	**array_of_words;
	int		i;
	int		j;
	int		start;

	i = -1;
	j = 0;
	array_of_words = malloc((ft_wordcount(s, c) + 1) * sizeof (char *));
	if ((array_of_words == NULL) || (s == NULL))
		return (NULL);
	while (s[++i] != '\0' && (size_t)i < ft_strlen(s))
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != '\0' && s[i] != c)
				i++;
			array_of_words[j] = ft_wordarr(s, start, i);
			if (array_of_words[j] == NULL)
				return (ft_freemem(array_of_words, j), NULL);
			j++;
		}
	}
	array_of_words[j] = NULL;
	return (array_of_words);
}
/*
#include <stdio.h>
int main() {

    int i; 
    i = 0;
    
    // Test input string
    char input[] = "Hello     world, this is a test string      .  ";

    // Split the input string by space (' ')
    char **result = ft_split(input, ' ');

    // Print the result
    if (result != NULL) 
    {
        while (result[i] != NULL)
        {
            printf("%s\n", result[i]);
            i++;
        }
        // Free the memory allocated for the result
        ft_freemem(result, ft_wordcount(input, ' '));
    } else {
        printf("Failed to split the string.\n");
    }
    return 0;
}*/