#include "libft.h"

static int	ft_itoa_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nbr;
	char	*res;

	nbr = n;
	len = ft_itoa_len(nbr);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nbr < 0)
	{
		res[0] = '-';
		nbr *= -1;
	}
	nbr = n;
	while (--len >= (res[0] == '-'))
	{
		res[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (res);
}
