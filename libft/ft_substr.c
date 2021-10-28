/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanis <student.21-school.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 22:24:15 by stanis            #+#    #+#             */
/*   Updated: 2021/10/28 22:24:53 by stanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;

	sub = NULL;
	if (s)
	{
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
	}
	return (sub);
}
// ft_strlcpy(sub, s + start, slen + 1); -> ft_memmove(sub, s + start, slen);