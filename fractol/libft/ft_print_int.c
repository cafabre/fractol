/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:47:46 by cafabre           #+#    #+#             */
/*   Updated: 2025/07/21 21:13:53 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int nbr)
{
	int		printed_chars;
	char	*str;

	str = ft_itoa((long)nbr);
	if (!str)
		return (-1);
	if (ft_putstr_fd(str, 1) == -1)
		return (-1);
	printed_chars = ft_strlen(str);
	free(str);
	return (printed_chars);
}
