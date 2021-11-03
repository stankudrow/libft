/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:11:25 by stanislav         #+#    #+#             */
/*   Updated: 2021/11/03 22:11:25 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)ft_calloc(len1 + len2 + 1, sizeof(char));
	if (str)
	{
		ft_memmove(str, s1, len1 + 1);
		ft_memmove(str + len1, s2, len2 + 1);
	}
	return (str);
}
// ft_strlcat(str, s2, len1 + len2 + 1) -> ft_strlcpy(str + len1, s2, len2 + 1);
// ft_strlcpy(str, s1, len1 + 1); -> ft_memove(str, s1, len1 + 1);