/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarti <mamarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 07:47:14 by mamarti           #+#    #+#             */
/*   Updated: 2025/12/02 12:51:39 by mamarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putchar(char c)
{
	return (write(1, &c, 1), 1);
}

size_t	ft_putstr(char *str)
{
	size_t	i;

	if (!str)
		return (ft_putstr("(null)"));
	i = 0;
	while (*str)
		i += ft_putchar(*str++);
	return (i);
}

size_t	ft_putnbr(long int n)
{
	size_t			i;
	unsigned int	nb;

	i = 0;
	if (n < 0)
	{
		nb = -n;
		i += ft_putchar('-');
	}
	else
		nb = n;
	if (nb > 9)
		i += ft_putnbr(nb / 10);
	i += ft_putchar(nb % 10 + '0');
	return (i);
}

size_t	ft_putnbr_base(unsigned long nb, char *base)
{
	const int	len_base = 16;
	size_t		i;

	i = 0;
	if (nb == 0)
		return (ft_putchar(base[0]));
	if (nb >= len_base)
		i += ft_putnbr_base(nb / len_base, base);
	i += ft_putchar(base[nb % len_base]);
	return (i);
}

size_t	ft_putnbr_unsigned(unsigned int nb)
{
	size_t	i;

	i = 0;
	if (nb > 9)
		i += ft_putnbr_unsigned(nb / 10);
	i += ft_putchar(nb % 10 + '0');
	return (i);
}
