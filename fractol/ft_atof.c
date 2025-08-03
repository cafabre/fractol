/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:00:00 by cafabre           #+#    #+#             */
/*   Updated: 2025/08/03 00:00:00 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	parse_decimal(char *str, int *i)
{
	double	result;
	double	decimal;

	result = 0.0;
	decimal = 0.1;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] && ft_isdigit(str[*i]))
		{
			result += (str[*i] - '0') * decimal;
			decimal /= 10.0;
			(*i)++;
		}
	}
	return (result);
}

double	ft_atof(char *str)
{
	double	result;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	if (str[0] == '-')
	{
		sign = -1;
		i = 1;
	}
	result = 0.0;
	while (str[i] && str[i] != '.')
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	result += parse_decimal(str, &i);
	return (result * sign);
}
