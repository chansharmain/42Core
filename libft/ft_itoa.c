/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:33:14 by shachan           #+#    #+#             */
/*   Updated: 2024/06/12 23:57:29 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}
//account for INT_MIN
//if number is negative your len should compare to 1
//so the negative sign is not overwritten
char	*ft_itoa(int n)
{
	char	*output;
	int		len;

	len = ft_numlen(n);
	output = malloc((len + 1) * sizeof(char));
	if (output == NULL)
		return (NULL);
	output[len] = '\0';
	if (n == 0)
		output[0] = '0';
	if (n < 0)
	{
		output[0] = '-';
		n = n * -1;
	}
	while (len > 0)
	{
		output[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (output);
}
