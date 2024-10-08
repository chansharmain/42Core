/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 00:21:48 by shachan           #+#    #+#             */
/*   Updated: 2024/08/25 02:01:56 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (start >= s_len)
	{
		len = 0;
		start = s_len;
	}
	if (len > s_len - start)
		len = s_len - start;
	substr = malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	while (((start + i) < s_len) && (i < len))
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
