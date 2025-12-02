/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarti <mamarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:29:45 by mamarti           #+#    #+#             */
/*   Updated: 2025/11/13 18:22:49 by mamarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned int		i;
	const unsigned char	*strr1;
	const unsigned char	*strr2;

	i = 0;
	strr1 = (unsigned char *) str1;
	strr2 = (unsigned char *) str2;
	while ((strr1[i] || strr2[i]) && i < n)
	{
		if (strr1[i] != strr2[i])
			return (strr1[i] - strr2[i]);
		i++;
	}
	return (0);
}
