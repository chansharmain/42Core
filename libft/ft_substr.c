/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 01:11:54 by shachan           #+#    #+#             */
/*   Updated: 2024/06/12 20:05:32 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{

	char *s = "hello world";

	printf("expected subst: empty string\n");
	printf("substring: %s\n", ft_substr(s, 0, 0));

	printf("expected subst: ell \n");
	printf("substring: %s\n", ft_substr(s, 1, 3));

	printf("expected subst: lo world \n");
	printf("substring: %s\n", ft_substr(s, 3, -5));

	printf("expected subst: NULL\n");
	printf("substring: %s\n", ft_substr(s, -5, 1));
}*/
