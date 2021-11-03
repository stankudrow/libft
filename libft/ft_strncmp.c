/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:11:58 by stanislav         #+#    #+#             */
/*   Updated: 2021/11/03 22:11:59 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (!n)
		return (0);
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (*str1 && *str2 && --n && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
