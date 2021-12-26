/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 01:00:42 by stanislav         #+#    #+#             */
/*   Updated: 2021/12/26 17:02:24 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

static int	ft_isspace(int c)
{
	return ((c > 8 && c < 14) || c == 32);
}

static void	ft_skip(const char **nptr, char *sign)
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

// nbr is an always positive number while in the loop of ft_atoi
static int	ft_isoverflow(long nbr, unsigned char digit, char sign)
{
	if (sign < 0)
		return ((LONG_MIN / 10 > nbr) || \
				(LONG_MIN + digit > -10 * nbr));
	if (sign > 0)
		return ((LONG_MAX / 10 < nbr) || \
				(LONG_MAX - digit < 10 * nbr));
	return (-1);
}

// libft-unit-test - that is why such an implementation
int	ft_atoi(const char *nptr)
{
	long	nbr;
	char	sign;

	sign = 1;
	nbr = 0;
	ft_skip(&nptr, &sign);
	while (ft_isdigit(*nptr))
	{
		if (ft_isoverflow(nbr, *nptr - '0', sign))
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		nbr = 10 * nbr + (*nptr - '0');
		nptr++;
	}
	return (sign * nbr);
}
