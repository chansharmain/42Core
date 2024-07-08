/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:26:32 by shachan           #+#    #+#             */
/*   Updated: 2024/06/18 23:55:56 by shachan          ###   ########.fr       */
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
