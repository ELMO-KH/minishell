/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkharti <elkharti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:35:47 by elkharti          #+#    #+#             */
/*   Updated: 2024/11/06 11:43:11 by elkharti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (!alst || !new)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	last = ft_lstlast(*alst);
	last->next = new;
}

/*int main ()
{
	t_list *head = NULL;
	t_list *new;
	new = ft_lstnew("first one");
	ft_lstadd_back(&head, new);
	new = ft_lstnew("secend one");
	ft_lstadd_back(&head, new);
	while (head)
	{
		printf("%s\n", (char*)head->content);
		head = head->next;
	}
}*/