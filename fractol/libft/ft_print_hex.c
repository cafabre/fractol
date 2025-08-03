/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:46:36 by cafabre           #+#    #+#             */
/*   Updated: 2025/07/21 21:13:53 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_hex(unsigned int nbr, char *base, int is_upper)
{
	int		printed_chars;
	char	c;

	printed_chars = 0;
	if (nbr >= 16)
		printed_chars += ft_putnbr_hex(nbr / 16, base, is_upper);
	c = base[nbr % 16];
	if (is_upper)
		c = ft_toupper(c);
	if (ft_putchar_fd(c, 1) == -1)
		return (-1);
	printed_chars++;
	return (printed_chars);
}

int	ft_print_hex(unsigned int nbr, char specifier)
{
	int	is_upper;

	is_upper = (specifier == 'X');
	return (ft_putnbr_hex(nbr, "0123456789abcdef", is_upper));
}
