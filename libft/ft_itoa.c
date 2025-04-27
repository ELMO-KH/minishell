/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkharti <elkharti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:39:34 by elkharti          #+#    #+#             */
/*   Updated: 2024/11/03 20:12:13 by elkharti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len = 1;
	while (nbr != 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	tmp;
	int		len;
	char	*str;

	tmp = n;
	len = ft_intlen(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		tmp = -tmp;
	}
	while (tmp > 0)
	{
		str[--len] = (tmp % 10) + '0';
		tmp /= 10;
	}
	return (str);
}
/*int	main(void)
{
	int num = 0123;
	char *result = ft_itoa(num);
	printf("The string representation of %d is: %s\n", num, result);
	free(result);
	return (0);
}*/
