/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:10:54 by stanislav         #+#    #+#             */
/*   Updated: 2021/11/03 22:10:54 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	void	*str;
	size_t	len;

	len = ft_strlen(s);
	str = ft_calloc(len + 1, sizeof(char));
	if (str)
		ft_memmove(str, s, len + 1);
	return (str);
}
// ft_strlcpy(str, s, len + 1); -> ft_memmove(str, s, len + 1);