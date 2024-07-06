/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 01:53:10 by shachan           #+#    #+#             */
/*   Updated: 2024/07/06 17:18:42 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *str)
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
		count++;
	}
	return(count);
}

int	ft_putpointer(unsigned long long n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		write(1, )
	}
	
}
/*
int	ft_putnbr(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
		ft_putnbr(n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}
*/

int	ft_putunsigned(unsigned int	n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putunsigned(n / 10);
		count += ft_putunsigned(n % 10);
	}
	count += ft_putchar(n + '0');
	return (count);
}

int	ft_putnbr_base(long n, char *base)
{
	int	baselen;
	int	count;

	baselen = 0;
	while (base[baselen] != '\0')
		baselen++;
	if (baselen < 1)
		return (0);
	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= baselen)
		count += ft_putnbr_base(n / baselen, base);
	count += ft_putchar(base[n % baselen]);
	return(count);
}
