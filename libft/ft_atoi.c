/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkharti <elkharti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:05:17 by elkharti          #+#    #+#             */
/*   Updated: 2024/11/06 11:14:10 by elkharti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (result >= __LONG_MAX__ && sign == 1)
			return (-1);
		if (result > __LONG_MAX__ && sign == -1)
			return (0);
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

/*int main ()
{
	char *s = "45545455645645645664882";
	printf("%d\n",ft_atoi(s));
	printf("%d",atoi(s));
}*/