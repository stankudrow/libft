/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanis <student.21-school.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 22:09:21 by stanis            #+#    #+#             */
/*   Updated: 2021/10/28 22:09:22 by stanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	if (lst && del)
	{
		while (*lst)
		{
			node = *lst;
			*lst = (*lst)->next;
			ft_lstdelone(node, del);
			node = NULL;
		}
	}
}
