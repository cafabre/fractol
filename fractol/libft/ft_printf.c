/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:06:25 by cafabre           #+#    #+#             */
/*   Updated: 2025/07/21 21:08:40 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_process_format(const char *str, va_list args, int *printed_chars)
{
	int	res;

	res = ft_handle_format(*str, args);
	if (res == -1)
		return (-1);
	*printed_chars += res;
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		printed_chars;
	int		i;

	printed_chars = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_process_format(&str[++i], args, &printed_chars) == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar_fd(str[i], 1) == -1)
				return (-1);
			printed_chars++;
		}
		i++;
	}
	va_end(args);
	return (printed_chars);
}
