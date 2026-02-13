#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	dest_size;
	size_t	src_size;
	size_t	i;

	dest_size = 0;
	src_size = 0;
	i = 0;
	while (dest[dest_size] != '\0')
		dest_size++;
	while (src[src_size] != '\0')
		src_size++;
	if (dest_size < n)
	{
		while (i + dest_size < n - 1 && i < src_size)
		{
			dest[i + dest_size] = src[i];
			i++;
		}
		dest[i + dest_size] = '\0';
		return (dest_size + src_size);
	}
	return (n + src_size);
}
