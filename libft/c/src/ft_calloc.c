/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:24:44 by stanislav         #+#    #+#             */
/*   Updated: 2021/11/09 01:29:00 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// thanks to @jbelinda and @thera for insights
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	total;

	if (!nmemb || !size)
	{
		nmemb = 1;
		size = 1;
	}
	if (size > (size_t)-1 / nmemb)
		return (NULL);
	total = nmemb * size;
	mem = malloc(total);
	if (mem)
		ft_memset(mem, 0, total);
	return (mem);
}
// ft_bzero(mem, total); -> ft_memset(mem, 0, total);