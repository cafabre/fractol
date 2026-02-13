#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char			*last;
	unsigned char	uc;

	last = NULL;
	uc = (unsigned char)c;
	while (*str != '\0')
	{
		if (*str == uc)
			last = (char *)str;
		str++;
	}
	if (uc == '\0')
		return ((char *)str);
	return (last);
}
