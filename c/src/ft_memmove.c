/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:17:45 by stanislav         #+#    #+#             */
/*   Updated: 2022/05/03 12:44:04 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*source;

	if (dst == src)
		return (dst);
	dest = dst;
	source = src;
	if (src < dst && dst - src < (long long int) n)
		while (n--)
			dest[n] = source[n];
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
