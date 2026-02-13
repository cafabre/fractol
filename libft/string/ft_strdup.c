#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	int		i;

	res = NULL;
	i = 0;
	while (s[i] != '\0')
		i++;
	res = malloc(i * sizeof(char) + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
