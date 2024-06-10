/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:15:53 by shachan           #+#    #+#             */
/*   Updated: 2024/06/04 00:32:33 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)(big));
	while ((big[i] != '\0') && (i < len))
	{
		j = 0;
		while ((little[j] != '\0') && (big[i + j] == little[j]) && (i
				+ j) < len)
		{
			if (little[j + 1] == '\0')
			{
				return ((char *)(big + i));
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
#include <bsd/string.h>
#include <stdio.h>

int main ()
{
	char s[20] = "Hello World!";
	char c[20] = "e";
	size_t len = 3;

	printf("input: Hello World!\nchar to find: e\n");
	printf("strnstr: %s\n", strnstr(s, c, len));
	printf("ft_strnstr: %s\n", ft_strnstr(s, c, len));
	printf("strnstr add: %p\n", strnstr(s, c, len));
	printf("ft_strnstr add: %p\n\n", ft_strnstr(s, c, len));

	char s2[20] = "Hello World!";
	char c2[20] = "ll";
	size_t len2 = 10;

	printf("input: Hello World!\nchar to find: a\n");
	printf("strnstr: %s\n", strnstr(s2, c2, len2));
	printf("ft_strnstr: %s\n", ft_strnstr(s2, c2, len2));
	printf("strnstr add: %p\n", strnstr(s2, c2, len2));
	printf("ft_strnstr add: %p\n\n", ft_strnstr(s2, c2, len2));

	char s3[20] = "HelloWorld!";
	char c3[20] = " ";
	size_t len3 = 10;

	printf("input: HelloWorld!\nchar to find:  \n");
	printf("strnstr: %s\n", strnstr(s3, c3, len3));
	printf("ft_strnstr: %s\n", ft_strnstr(s3, c3, len3));
	printf("strnstr add: %p\n", strnstr(s3, c3, len3));
	printf("ft_strnstr add: %p\n\n", ft_strnstr(s3, c3, len3));

	char s4[20] = "HelloWorld!";
	char c4[20] = "ep";
	size_t len4 = 10;

	printf("input: HelloWorld!\nchar to find: ep\n");
	printf("strnstr: %s\n", strnstr(s4, c4, len4));
	printf("ft_strnstr: %s\n", ft_strnstr(s4, c4, len4));
	printf("strnstr add: %p\n", strnstr(s4, c4, len4));
	printf("ft_strnstr add: %p\n\n", ft_strnstr(s4, c4, len4));
}*/