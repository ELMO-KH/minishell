/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkharti <elkharti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:35:16 by elkharti          #+#    #+#             */
/*   Updated: 2024/11/06 11:49:26 by elkharti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*int main ()
{
	t_list *head = NULL;
	t_list *new;

	new = ft_lstnew("Hello, World!");
	ft_lstadd_front(&head, new);
	new = ft_lstnew("This is a linked list.");
	ft_lstadd_front(&head, new);
	while (head) {
        printf("%s\n", (char *)head->content);
		head = head->next;

	}
}*/