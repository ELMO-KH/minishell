/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkharti <elkharti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:58:54 by elkharti          #+#    #+#             */
/*   Updated: 2024/11/06 12:15:35 by elkharti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}

/*int main ()
{
    t_list *head = NULL;
    t_list *new;

    new = ft_lstnew("Hello, World!");
    ft_lstadd_front(&head, new);
    new = ft_lstnew("This is a linked list.");
    ft_lstadd_front(&head, new);
    ft_lstclear(&head, free);
}*/