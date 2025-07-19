/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkharti <elkharti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:00:00 by elkharti          #+#    #+#             */
/*   Updated: 2025/07/12 20:55:33 by elkharti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static bool	is_numeric(const char *str)
{
	int	i;

	if (!str || !*str)
		return (false);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	is_valid_exit_number(const char *str)
{
	int				sign;
	unsigned long	result;
	int				i;

	sign = 1;
	result = 0;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > LLONG_MAX)
			|| (sign == -1 && result > (unsigned long)LLONG_MAX + 1))
			return (false);
		i++;
	}
	return (true);
}

long long	ft_atoll(const char *str)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
		result = result * 10 + (*str++ - '0');
	return (result * sign);
}

static int	check_exit_args(t_data *data, char **args, int *exit_code)
{
	if (args[1] && args[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		g_exit_status = 1;
		clean_exit(data, 2);
		return (FAILURE);
	}
	if (args[1])
	{
		if (!is_numeric(args[1]) || !is_valid_exit_number(args[1]))
		{
			ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
			ft_putstr_fd(args[1], STDERR_FILENO);
			ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
			clean_exit(data, 2);
			return (2);
		}
		*exit_code = (unsigned char)ft_atoll(args[1]);
	}
	else
		*exit_code = g_exit_status;
	return (SUCCESS);
}

int	ft_exit(t_data *data, char **args)
{
	int	exit_code;
	int	status;

	if (!data->is_child)
		ft_putstr_fd("exit\n", STDOUT_FILENO);
	status = check_exit_args(data, args, &exit_code);
	if (status != SUCCESS)
		return (status);
	clean_exit(data, exit_code);
	return (exit_code);
}
