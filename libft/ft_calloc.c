/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkharti <elkharti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:11:54 by elkharti          #+#    #+#             */
/*   Updated: 2024/11/04 17:46:54 by elkharti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*arr;

	if (size && n > __SIZE_MAX__ / size)
		return (NULL);
	arr = malloc(n * size);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, (n * size));
	return (arr);
}
