/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:24:01 by stanislav         #+#    #+#             */
/*   Updated: 2021/11/03 22:24:02 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static short	ft_get_numsign(int nbr)
{
	if (nbr < 0)
		return (-1);
	return (1);
}

static size_t	ft_get_numlen(int nbr)
{
	size_t	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static void	ft_strrev(char *s)
{
	char	*left;
	char	tmp;

	left = s;
	while (*s)
		s++;
	while (left < --s)
	{
		tmp = *left;
		*left++ = *s;
		*s = tmp;
	}
}

char	*ft_itoa(int nbr)
{
	char		*str;
	size_t		len;
	size_t		pos;
	short		sign;

	sign = ft_get_numsign(nbr);
	len = ft_get_numlen(nbr);
	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	pos = 0;
	while (nbr)
	{
		str[pos++] = sign * (nbr % 10) + '0';
		nbr /= 10;
	}
	if (!(nbr || pos))
		str[pos++] = '0';
	if (sign < 0)
		str[pos++] = '-';
	str[pos] = '\0';
	ft_strrev(str);
	return (str);
}
