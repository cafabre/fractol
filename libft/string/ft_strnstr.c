#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_s2;

	i = 0;
	len_s2 = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (s2[len_s2] != '\0')
		len_s2++;
	while (*s1 != '\0' && i < len)
	{
		j = 0;
		while (s1[i + j] == s2[j] && i + j < len)
		{
			if (j == len_s2 - 1)
				return ((char *)&s1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
