/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarti <mamarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:16:29 by mamarti           #+#    #+#             */
/*   Updated: 2025/11/13 18:22:52 by mamarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	if (!*tofind)
		return ((char *)str);
	i = 0;
	while (str[i] && i < n)
	{
		if (str[i] == tofind[0])
		{
			j = 0;
			while (str[i + j] == tofind[j] && i + j < n)
			{
				if (tofind[j + 1] == '\0')
					return ((char *)&str[i]);
				j++;
			}
		}
		i++;
	}
	return (0);
}
