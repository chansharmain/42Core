/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:19:28 by shachan           #+#    #+#             */
/*   Updated: 2024/06/12 20:05:13 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_matchchar(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*output;
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	while (s1[start] != '\0' && ft_matchchar(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_matchchar(s1[end - 1], set))
		end--;
	output = malloc((end - start + 1) * sizeof(char));
	if (output == NULL)
		return (NULL);
	while (start < end)
	{
		output[i] = s1[start];
		start++;
		i++;
	}
	output[i] = '\0';
	return (output);
}
/*
#include <stdio.h>

int	main(void)
{
	char const *s1 = " Hello World ";
	char const *set = " ";
	printf("input string: ' Hello World '\n");
	printf("to trim: ' ' \n");
	printf("expected output: 'Hello World'\n");
	printf("output: %s\n\n", ft_strtrim(s1, set));

	printf("input string: '###Hello World###'\n");
	printf("to trim: '#' \n");
	printf("expected output: 'Hello World'\n");
	printf("output: %s\n\n", ft_strtrim("###Hello World###", "#"));

	printf("input string: ' '\n");
	printf("to trim: ' ' \n");
	printf("expected output: ' '\n");
	printf("output: %s\n\n", ft_strtrim(" ", " "));
}*/