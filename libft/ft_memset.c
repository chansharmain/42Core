/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 01:22:07 by shachan           #+#    #+#             */
/*   Updated: 2024/06/12 20:01:53 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)str)[i] = (unsigned char)c;
		i++;
	}
	return (str);
}

/*int	main(void)
{
	char s1[] = "hello";
	char s2[] = "hello";

	printf("memset: %s\n", (char*)memset(s1, 'y', 5));
	printf("ft_memset: %s\n", (char*)ft_memset(s2, 'y', 5));

	char s3[] = "hello";
	char s4[] = "hello";

	printf("memset: %s\n", (char*)memset(s3, 'y', 6));
	printf("ft_memset: %s\n", (char*)ft_memset(s4, 'y', 6));

	char s5[] = "hello";
	char s6[] = "hello";

	printf("memset: %s\n", (char*)memset(s5, 'y', 7));
	printf("ft_memset: %s\n", (char*)ft_memset(s6, 'y', 7));
}*/
