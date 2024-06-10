/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:53:53 by shachan           #+#    #+#             */
/*   Updated: 2024/06/07 01:22:27 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_calloc(size_t nitems, size_t size)
{
	void *ptr;

	ptr = malloc(nitems * size);
	if (ptr == NULL)
		return (NULL);
	else
		ft_bzero(ptr, nitems * size);
	return (ptr);
}