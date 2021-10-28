/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanis <student.21-school.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 22:10:25 by stanis            #+#    #+#             */
/*   Updated: 2021/10/28 22:10:25 by stanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ma;
	unsigned char		chr;

	ma = (unsigned char *)s;
	chr = (unsigned char)c;
	while (n--)
		if (*ma++ == chr)
			return ((void *)--ma);
	return (NULL);
}
