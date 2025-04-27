/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkharti <elkharti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:18:20 by elkharti          #+#    #+#             */
/*   Updated: 2024/11/04 19:46:20 by elkharti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write (fd, s, 1);
		s++;
	}
}

/*#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
	int fd;


	fd = open("hello.txt", O_RDWR | O_CREAT | ), 03);

	ft_putstr_fd("masfiwi", fd);

	close(fd);
	return 0;
}*/