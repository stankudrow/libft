/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:17:58 by stanislav         #+#    #+#             */
/*   Updated: 2021/11/09 22:30:19 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ma1;
	const unsigned char	*ma2;

	ma1 = s1;
	ma2 = s2;
	while (n--)
		if (*ma1++ != *ma2++)
			return (*--ma1 - *--ma2);
	return (0);
}
