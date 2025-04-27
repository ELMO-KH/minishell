/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkharti <elkharti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:12:06 by elkharti          #+#    #+#             */
/*   Updated: 2024/11/04 18:12:08 by elkharti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
/*#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
	int fd;


	fd = open("hello.txt", O_RDWR | O_CREAT);

	ft_putchar_fd('h', fd);

	close(fd);
	return 0;
}*/