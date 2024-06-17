/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:26:32 by shachan           #+#    #+#             */
/*   Updated: 2024/06/17 14:00:05 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if ((lst == NULL) || (del == NULL))
		return ;
	temp = *lst;
	while (*lst != NULL)
	{
		temp = *lst;
		*lst = (*lst)->next;
		del (temp->content);
		free (temp);
	}
}
