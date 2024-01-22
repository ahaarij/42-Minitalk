/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:47:48 by ahaarij           #+#    #+#             */
/*   Updated: 2023/11/26 10:27:04 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*hi;
	t_list	*nextnode;

	if (lst == NULL || del == NULL)
		return ;
	hi = *lst;
	while (hi)
	{
		nextnode = hi->next;
		del(hi->content);
		free(hi);
		hi = nextnode;
	}
	*lst = NULL;
}
