#include "libft.h"

char	*ft_utoa(unsigned int nbr)
{
	unsigned int	tmp;
	int				len;
	char			*str;

	tmp = nbr;
	len = 1;
	while (tmp >= 10)
	{
		tmp /= 10;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
