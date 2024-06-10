/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:33:14 by shachan           #+#    #+#             */
/*   Updated: 2024/06/10 02:26:13 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	if (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

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
