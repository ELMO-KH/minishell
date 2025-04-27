/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkharti <elkharti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:05:14 by elkharti          #+#    #+#             */
/*   Updated: 2024/11/06 13:55:13 by elkharti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_obj;
	void	*new_content;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_obj = ft_lstnew(new_content);
		if (!new_obj)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_obj);
		lst = lst->next;
	}
	return (new_list);
}

/*int main ()
{
    t_list *head = NULL;
    t_list *new;
    t_list *res;

    new = ft_lstnew("Hello, World!");
    ft_lstadd_front(&head, new);
    new = ft_lstnew("This is a linked list.");
    ft_lstadd_front(&head, new);
    res = ft_lstmap(head, &ft_toupper, &free);
	while (res)
    {
        printf("%s\n", (char *)res->content);
        res = res->next;
    }
}*/