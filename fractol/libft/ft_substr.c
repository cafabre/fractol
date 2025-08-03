/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:09:49 by cafabre           #+#    #+#             */
/*   Updated: 2025/07/21 20:39:15 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_const_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*empty_string(void)
{
	char	*res;

	res = malloc(1);
	if (res == NULL)
		return (NULL);
	res[0] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;

	res = NULL;
	i = 0;
	if (start >= ft_const_strlen(s))
	{
		res = empty_string();
		return (res);
	}
	while (s[start + i] != '\0' && i < len)
		i++;
	res = malloc(i * sizeof(char) + 1);
	if (res == NULL)
		return (res);
	j = 0;
	while (j < i)
	{
		res[j] = s[start + j];
		j++;
	}
	res[i] = '\0';
	return (res);
}
