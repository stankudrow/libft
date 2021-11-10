/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:11:52 by stanislav         #+#    #+#             */
/*   Updated: 2021/11/11 01:43:16 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	size_t			slen;
	unsigned int	i;

	slen = ft_strlen(s);
	if (slen == (size_t)-1)
		return (NULL);
	str = (char *)ft_calloc(slen + 1, sizeof(char));
	if (str)
	{
		i = 0;
		while (s[i])
		{
			str[i] = (*f)(i, s[i]);
			i++;
		}
	}
	return (str);
}
