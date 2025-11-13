/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarti <mamarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:05:59 by mamarti           #+#    #+#             */
/*   Updated: 2025/11/13 18:22:55 by mamarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*strr;

	strr = NULL;
	while (*str)
	{
		if (*str == (char)c)
			strr = (char *)str;
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (strr);
}
