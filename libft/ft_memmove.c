/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkharti <elkharti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:35:43 by elkharti          #+#    #+#             */
/*   Updated: 2024/11/06 11:27:38 by elkharti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*tmp_dest;
	char	*tmp_src;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	tmp_dest = (char *) dest;
	tmp_src = (char *) src;
	i = 0;
	if (tmp_dest > tmp_src)
	{
		while (len-- > 0)
		{
			tmp_dest[len] = tmp_src[len];
		}
	}
	else
	{
		while (i < len)
		{
			tmp_dest[i] = tmp_src[i];
			i++;
		}
	}
	return (dest);
}

/*
int main() {
    char src[] = "Hello, World!";
    char dest[20];
    
    ft_memmove(dest, src, 13);
    printf("%s", dest);
    return 0;
}
*/