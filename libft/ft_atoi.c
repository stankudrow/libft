/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanis <student.21-school.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 22:06:07 by stanis            #+#    #+#             */
/*   Updated: 2021/10/28 22:06:14 by stanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return ((c > 8 && c < 14) || c == 32);
}

static void	ft_skip(const char **nptr, short int *sign)
{
	while (ft_isspace(**nptr))
		(*nptr)++;
	if (**nptr == '-' || **nptr == '+')
	{
		if (**nptr == '-')
			*sign = -1;
		(*nptr)++;
	}
	while (**nptr == '0')
		(*nptr)++;
}

int	ft_atoi(const char *nptr)
{
	long	nbr;
	short	sign;

	sign = 1;
	nbr = 0;
	ft_skip(&nptr, &sign);
	while (ft_isdigit(*nptr))
	{
		if ((10 * nbr + (*nptr - '0')) < nbr)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		nbr = 10 * nbr + (*nptr - '0');
		nptr++;
	}
	return (sign * (int)nbr);
}
