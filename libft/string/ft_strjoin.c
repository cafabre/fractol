#include "libft.h"

static int	ft_const_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		res_size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res_size = ft_const_strlen(s1) + ft_const_strlen(s2);
	res = malloc(res_size * sizeof(char) + 1);
	if (res == NULL)
		return (res);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}
