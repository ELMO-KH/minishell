/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkharti <elkharti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:08:14 by elkharti          #+#    #+#             */
/*   Updated: 2024/11/06 14:07:52 by elkharti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	return (str);
}
/*

int main() {
    const char *str = "Hello, World!";
    printf("%s\n", ft_substr(str, 7, 5));
    return 0;
}

*/
/*int	main()
{
	char	*result;

	result = ft_substr("abcde",3, 5);
	printf("Substring: '%s'\n", result);
	free(result);
	return (0);
}*/