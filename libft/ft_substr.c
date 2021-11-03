/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:13:38 by stanislav         #+#    #+#             */
/*   Updated: 2021/11/03 22:13:38 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;

	slen = ft_strlen(s);
	if (start < slen)
	{
		if (slen > (start + len))
			slen = start + len;
		slen -= start;
		sub = (char *)ft_calloc(slen + 1, sizeof(char));
		if (sub)
			ft_memmove(sub, s + start, slen);
	}
	else
		sub = (char *)ft_calloc(1, sizeof(char));
	return (sub);
}
// ft_strlcpy(sub, s + start, slen + 1); -> ft_memmove(sub, s + start, slen);