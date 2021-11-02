/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanis <student.21-school.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:40:32 by stanis            #+#    #+#             */
/*   Updated: 2021/11/02 22:40:33 by stanis           ###   ########.fr       */
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
	if (src < dst)
		while (n--)
			dest[n] = source[n];
	if (src > dst)
		ft_memcpy(dst, src, n);
	return (dst);
}
