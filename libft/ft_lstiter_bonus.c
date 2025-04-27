/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkharti <elkharti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:07:26 by elkharti          #+#    #+#             */
/*   Updated: 2024/11/06 13:43:21 by elkharti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	if (!lst || !f)
		return ;
	tmp = lst;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}

/*
void print_content(void *content)
{
	printf("%s\n", (char *)content);
}

int main()
{
	t_list *element = ft_lstnew("Hello World");
	t_list *element2 = ft_lstnew("Hello World 2");
	t_list *element3 = ft_lstnew("Hello World 3");
	ft_lstadd_front(&element, element2);
	ft_lstadd_front(&element, element3);
	ft_lstiter(element, &print_content);
	return 0;
}
*/