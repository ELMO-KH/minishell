/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkharti <elkharti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:24:57 by elkharti          #+#    #+#             */
/*   Updated: 2024/11/03 19:48:33 by elkharti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ret;
	size_t	j;

	i = 0;
	ret = 0;
	if (!dst && !dstsize)
		return (ft_strlen(src));
	ret = ft_strlen(dst);
	if (dstsize == 0 || dstsize <= ret)
		return (ft_strlen(src) + dstsize);
	j = ret;
	while (src[i] && j < dstsize - 1)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (ret + ft_strlen(src));
}

/*int main ()
{
	char s[20] = "hello";
	const char *str = NULL;
	char s1[20] = "hello";
	const char *str1 = NULL;
	//printf("%zu\n", strlcat(s, str, sizeof(s)));
	printf("%zu\n",ft_strlcat(NULL, s1, sizeof(s)));
	return 0;
}*/