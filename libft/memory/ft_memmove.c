/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:49:29 by cafabre           #+#    #+#             */
/*   Updated: 2025/07/21 20:43:22 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*memmove_memcpy(unsigned char *d,
		unsigned const char *s, size_t n, int reverse)
{
	size_t	i;

	i = 0;
	if (reverse)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;

	d = (unsigned char *)dest;
	s = (unsigned const char *)src;
	if (!d && !s && n > 0)
		return (NULL);
	if (s == d || n == 0)
		return (dest);
	if (d > s && d < s + n)
		return (memmove_memcpy(d, s, n, 1));
	else
		return (memmove_memcpy(d, s, n, 0));
}
