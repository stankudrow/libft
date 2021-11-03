/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:17:16 by stanislav         #+#    #+#             */
/*   Updated: 2021/11/03 22:17:17 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		if (nbr <= -10)
			ft_putnbr_fd(nbr / -10, fd);
		ft_putchar_fd(-(nbr % 10) + '0', fd);
	}
	else
	{
		if (nbr >= 10)
			ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd((nbr % 10) + '0', fd);
	}
}
