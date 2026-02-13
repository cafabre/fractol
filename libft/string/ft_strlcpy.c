#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	src_size;
	size_t	i;

	src_size = 0;
	i = 0;
	while (src[src_size] != '\0')
		src_size++;
	if (n > 0)
	{
		while (i < n - 1 && i < src_size)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_size);
}
