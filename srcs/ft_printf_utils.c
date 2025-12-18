/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarti <mamarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 07:32:25 by mamarti           #+#    #+#             */
/*   Updated: 2025/12/18 12:45:25 by mamarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_print_p(void *ptr)
{
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	else
		return (ft_putstr("0x") + ft_putnbr_base((long) ptr, HEXA_LOW));
}

void	ft_handle_printf(char c, va_list *args, int *count)
{
	if (c == 'c')
		*count += ft_putchar(va_arg(*args, int));
	else if (c == 's')
		*count += ft_putstr(va_arg(*args, char *));
	else if (c == 'p')
		*count += ft_print_p(va_arg(*args, void *));
	else if (c == 'd' || c == 'i')
		*count += ft_putnbr(va_arg(*args, int));
	else if (c == 'u')
		*count += ft_putnbr_unsigned(va_arg(*args, int));
	else if (c == 'x')
		*count += ft_putnbr_base(va_arg(*args, unsigned int), HEXA_LOW);
	else if (c == 'X')
		*count += ft_putnbr_base(va_arg(*args, unsigned int), HEXA_UPP);
	else if (c == '%')
		*count += ft_putchar('%');
}
