/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarti <mamarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:38:57 by mamarti           #+#    #+#             */
/*   Updated: 2025/11/13 18:26:52 by mamarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(char const *s, char c)
{
	bool	inword;
	size_t	count;

	inword = false;
	count = 0;
	while (*s)
	{
		if (*s != c && !inword)
		{
			inword = true;
			count++;
		}
		else if (*s == c)
			inword = false;
		s++;
	}
	return (count);
}

static char	*createword(char const *s, size_t start, size_t end)
{
	char	*word;
	size_t	i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	freetab(char **tab, size_t word)
{
	while (word > 0)
		free(tab[--word]);
	free(tab);
}

static int	execsplit(char **tab, char const *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			len++;
			i++;
		}
		if (len != 0)
		{
			tab[word] = createword(s, i - len, i);
			if (!tab[word])
				return (freetab(tab, word), -1);
			word++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	words;

	words = countwords(s, c);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	tab[words] = 0;
	if (execsplit(tab, s, c) == -1)
		return (NULL);
	return (tab);
}
