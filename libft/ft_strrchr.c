/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanis <student.21-school.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 22:20:35 by stanis            #+#    #+#             */
/*   Updated: 2021/10/28 22:20:35 by stanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*cptr;
	unsigned char	chr;

	cptr = s;
	chr = c;
	while (*s)
	{
		if (*s == c)
			cptr = s;
		s++;
	}
	if (*cptr == chr)
		return ((char *)cptr);
	if (*s == chr)
		return ((char *)s);
	return (NULL);
}
