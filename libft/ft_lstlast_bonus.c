/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkharti <elkharti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:45:29 by elkharti          #+#    #+#             */
/*   Updated: 2024/11/05 13:46:50 by elkharti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

/*int main ()
{
    t_list *head = NULL;
    t_list *new;

    new = ft_lstnew("Hello, World!");
    ft_lstadd_front(&head, new);
    new = ft_lstnew("This is a linked list.");
    ft_lstadd_front(&head, new);
    printf("%s\n", (char *)ft_lstlast(head)->content);
    while (head) {
        t_list *temp = head;
        head = head->next;
        free(temp);
    }
}*/