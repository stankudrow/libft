/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:17:10 by stanislav         #+#    #+#             */
/*   Updated: 2021/11/03 22:17:11 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/* original function pourly implemented */
// void	ft_putstr_fd(char *s, int fd)
// {
// 	while (*s)
// 		ft_putchar_fd(*s++, fd);
// }


void ft_putstr_fd(char *s, int fd)
{
    // one system call is cheaper than multiple per-character `write` calls
	write(fd, s, ft_strlen(s));
}
