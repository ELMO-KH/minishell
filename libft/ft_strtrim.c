/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkharti <elkharti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:10:09 by elkharti          #+#    #+#             */
/*   Updated: 2024/11/06 10:57:39 by elkharti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;
	char	*new;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_check_set(*s1, set))
		s1++;
	size = ft_strlen(s1);
	while (size > 0 && ft_check_set(s1[size - 1], set))
		size--;
	new = (char *)malloc(size + 1);
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, size + 1);
	return (new);
}

/*int main ()
{
	// char str1[]= NULL ;
	char *str2 = "h";
	printf("%s\n",ft_strtrim(NULL, str2));
}*/