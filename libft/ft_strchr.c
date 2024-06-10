/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:40:46 by shachan           #+#    #+#             */
/*   Updated: 2024/05/27 21:17:03 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

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
/*
#include <stdio.h>
#include <string.h>

int main ()
{
	char s[] = "Hello World!";
	int c = 'e';

	printf("input: Hello World!\nchar to find: e\n");
	printf("strchr: %s\n", strchr(s, c));
	printf("ft_strchr: %s\n", ft_strchr(s, c));
	printf("strchr add: %p\n", strchr(s, c));
	printf("ft_strchr add: %p\n", ft_strchr(s, c));

	char s2[] = "Hello World!";
	int c2 = 'a';

	printf("input: Hello World!\nchar to find: a\n");
	printf("strchr: %s\n", strchr(s2, c2));
	printf("ft_strchr: %s\n", ft_strchr(s2, c2));
	printf("strchr add: %p\n", strchr(s2, c2));
	printf("ft_strchr add: %p\n", ft_strchr(s2, c2));
}*/
