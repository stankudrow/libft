/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanis <student.21-school.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 22:19:44 by stanis            #+#    #+#             */
/*   Updated: 2021/10/28 22:19:44 by stanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	str = NULL;
	if (s && f)
	{
		str = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
		if (str)
		{
			i = 0;
			while (s[i])
			{
				str[i] = (*f)(i, s[i]);
				i++;
			}
		}
	}
	return (str);
}
