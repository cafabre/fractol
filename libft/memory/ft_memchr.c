#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		value;
	size_t				i;

	p = (const unsigned char *)ptr;
	value = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (p[i] == value)
			return ((void *)&p[i]);
		i++;
	}
	return (NULL);
}
