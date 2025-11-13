/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarti <mamarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:06:13 by mamarti           #+#    #+#             */
/*   Updated: 2025/11/13 18:26:11 by mamarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbrlen(long n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
	{
		n = -n;
		i++;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	putnbrstr(char *str, long nbr, size_t *i)
{
	if (nbr > 9)
	{
		putnbrstr(str, nbr / 10, i);
		putnbrstr(str, nbr % 10, i);
	}
	else
		str[(*i)++] = nbr + '0';
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	size_t	i;

	nbr = (long) n;
	str = malloc(sizeof(char) * (nbrlen(nbr) + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		str[i++] = '-';
	}
	putnbrstr(str, nbr, &i);
	str[i] = '\0';
	return (str);
}
