/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:48:47 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/04 17:41:43 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*source;
	unsigned char		chr;

	if (dst == src)
		return (dst);
	dest = dst;
	source = src;
	chr = c;
	while (n--)
	{
		*dest++ = *source++;
		if (*(dest - 1) == chr)
			return ((void *)dest);
	}
	return (NULL);
}
