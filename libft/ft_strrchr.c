/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:19:26 by shachan           #+#    #+#             */
/*   Updated: 2024/06/13 00:05:03 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	len;

	len = ft_strlen(str);
	while (len > 0)
	{
		if (str[len] == (unsigned char)c)
		{
			return ((char *)(str + len));
		}
		len--;
	}
	if (str[len] == (unsigned char)c)
		return ((char *)(str + len));
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int main ()
{
	char s[] = "Hello World!";
	int c = 'o';

	printf("input: Hello World!\nchar to find: o\n");
	printf("strrchr: %s\n", strrchr(s, c));
	printf("ft_strrchr: %s\n", ft_strrchr(s, c));
	printf("strrchr add: %p\n", strrchr(s, c));
	printf("ft_strrchr add: %p\n", ft_strrchr(s, c));

	char s2[] = "Hello World!";
	int c2 = 'a';

	printf("input: Hello World!\nchar to find: a\n");
	printf("strrchr: %s\n", strrchr(s2, c2));
	printf("ft_strrchr: %s\n", ft_strrchr(s2, c2));
	printf("strrchr add: %p\n", strrchr(s2, c2));
	printf("ft_strrchr add: %p\n", ft_strrchr(s2, c2));
}*/