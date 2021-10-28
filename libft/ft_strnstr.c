/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanis <student.21-school.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 23:29:20 by stanis            #+#    #+#             */
/*   Updated: 2021/10/28 23:29:20 by stanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (big[i])
	{
		j = 0;
		while (little[j] && big[i + j] == little[j] && (i + j) < n)
			j++;
		if ((i + j) > n)
			return (NULL);
		if (!little[j])
			return ((char *)&big[i]);
		if (!big[i + j])
			return (NULL);
		i++;
	}
	return (NULL);
}
