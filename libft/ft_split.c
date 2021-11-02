/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanis <student.21-school.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:42:47 by stanis            #+#    #+#             */
/*   Updated: 2021/11/02 22:42:47 by stanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *str, char sep)
{
	size_t	words;

	words = 0;
	while (*str)
	{
		while (*str && *str == sep)
			str++;
		while (*str && *str != sep)
		{
			if (*(str + 1) == sep || !*(str + 1))
				words++;
			str++;
		}
	}
	return (words);
}

static char	*ft_wordnew(char const *str, unsigned int *start, char sep)
{
	size_t	len;

	while (str[*start] && str[*start] == sep)
		(*start)++;
	len = 0;
	while (str[*start] && str[*start] != sep)
	{
		(*start)++;
		len++;
	}
	return (ft_substr(str, *start - len, len));
}

static void	ft_free_words(char **strs, size_t nwords)
{
	size_t	iword;

	iword = 0;
	while (iword < nwords)
		free(strs[iword++]);
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	char			**words;
	size_t			wsc;
	size_t			iword;
	unsigned int	start;

	if (!s)
		return (NULL);
	wsc = ft_count_words(s, c);
	words = (char **)ft_calloc(wsc + 1, sizeof(char *));
	if (!words)
		return (NULL);
	iword = -1;
	start = 0;
	while (++iword < wsc)
	{
		words[iword] = ft_wordnew(s, &start, c);
		if (!words[iword])
		{
			ft_free_words(words, iword + 1);
			return (NULL);
		}
	}
	words[iword] = NULL;
	return (words);
}
