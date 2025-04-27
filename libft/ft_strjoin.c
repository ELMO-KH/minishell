/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkharti <elkharti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:26:57 by elkharti          #+#    #+#             */
/*   Updated: 2024/10/31 15:30:11 by elkharti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}
/*int main(void)
{
    char *str1 = "Hello, ";
    char *str2 = "world!";
    char *result = ft_strjoin(str1, str2);

    if (result)
    {
        printf("Result: %s\n", result); // يجب أن تظهر "Hello, world!"
        free(result); // لا تنسَ تحرير الذاكرة
    }
    else
    {
        printf("Memory allocation failed.\n");
    }

    return 0;
}*/