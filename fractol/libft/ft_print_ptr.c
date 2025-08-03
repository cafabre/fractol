/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:57:37 by cafabre           #+#    #+#             */
/*   Updated: 2025/07/21 21:13:53 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base(unsigned long nbr, char *base)
{
	int	printed_chars;

	printed_chars = 0;
	if (nbr >= 16)
		printed_chars += ft_putnbr_base(nbr / 16, base);
	if (ft_putchar_fd(base[nbr % 16], 1) == -1)
		return (-1);
	printed_chars++;
	return (printed_chars);
}

int	ft_print_ptr(void *ptr)
{
	int	printed_chars;

	if (!ptr)
	{
		if (ft_putstr_fd("(nil)", 1) == -1)
			return (-1);
		return (5);
	}
	if (ft_putstr_fd("0x", 1) == -1)
		return (-1);
	printed_chars = 2;
	printed_chars += ft_putnbr_base((unsigned long)ptr, "0123456789abcdef");
	return (printed_chars);
}
