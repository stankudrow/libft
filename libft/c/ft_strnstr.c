/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorton <mhorton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:12:05 by stanislav         #+#    #+#             */
/*   Updated: 2022/09/17 15:54:09 by mhorton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;

	if (!n && !big)
		return (NULL);
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
