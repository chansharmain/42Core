/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 01:15:16 by shachan           #+#    #+#             */
/*   Updated: 2024/08/22 16:13:42 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*output;

	i = 0;
	j = 0;
	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	output = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (output == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		output[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		output[i + j] = s2[j];
		j++;
	}
	output[i + j] = '\0';
	return (output);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ((unsigned char)c))
		{
			return ((char *)(str + i));
		}
		i++;
	}
	if (str[i] == ((unsigned char)c))
		return ((char *)(str + i));
	return (NULL);
}

// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	i;
// 	size_t	srclen;

// 	i = 0;
// 	srclen = 0;
// 	if (dstsize > 0)
// 	{
// 		while ((src[i] != '\0') && (i < (dstsize - 1)))
// 		{
// 			dst[i] = src[i];
// 			i++;
// 		}
// 		dst[i] = '\0';
// 	}
// 	while (src[srclen] != '\0')
// 	{
// 		srclen++;
// 	}
// 	return (srclen);
// }

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		len = 0;
		start = ft_strlen(s);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	while (((start + i) < ft_strlen(s)) && (i < len))
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

// void	ft_free_store(char **store)
// {
// 	int	i;

// 	i = 0;
// 	if (store != NULL)
// 	{
// 		while (i < NUM_FD)
// 		{
// 			if (store[i] != NULL)
// 			{
// 				free(store[i]);
// 				store[i] = NULL;
// 			}
// 			i++;
// 		}
// 		free (store);
// 	}
// }