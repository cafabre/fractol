#include "libft.h"

void	*ft_calloc(size_t n, size_t s)
{
	void	*res;

	res = malloc(n * s);
	if (!res)
		return (NULL);
	ft_memset(res, 0, n * s);
	return (res);
}
