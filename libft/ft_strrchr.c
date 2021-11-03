/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:12:12 by stanislav         #+#    #+#             */
/*   Updated: 2021/11/03 22:12:12 by stanislav        ###   ########.fr       */
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
