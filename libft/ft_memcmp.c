/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:17:58 by stanislav         #+#    #+#             */
/*   Updated: 2021/11/03 22:17:58 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ma1;
	unsigned char	*ma2;

	ma1 = (unsigned char *)s1;
	ma2 = (unsigned char *)s2;
	while (n--)
		if (*ma1++ != *ma2++)
			return (*--ma1 - *--ma2);
	return (0);
}
