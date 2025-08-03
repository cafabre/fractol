/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:52:10 by cafabre           #+#    #+#             */
/*   Updated: 2025/07/21 21:13:53 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int nbr)
{
	int		printed_chars;
	char	*str;

	str = ft_utoa(nbr);
	if (!str)
		return (-1);
	if (ft_putstr_fd(str, 1) == -1)
		return (-1);
	printed_chars = ft_strlen(str);
	free(str);
	return (printed_chars);
}

static int	get_unsigned_length(unsigned int nbr)
{
	int	length;

	length = 1;
	while (nbr >= 10)
	{
		nbr /= 10;
		length++;
	}
	return (length);
}

char	*ft_utoa(unsigned int nbr)
{
	int		len;
	char	*str;

	len = get_unsigned_length(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
