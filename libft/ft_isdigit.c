/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 00:46:35 by shachan           #+#    #+#             */
/*   Updated: 2024/05/21 02:00:01 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int main(void)
{
	int i = ft_isdigit('5');
	int j = ft_isdigit('c');
	printf("%d\n", i);
	printf("%d\n", j);
}