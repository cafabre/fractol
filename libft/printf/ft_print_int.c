#include "libft.h"

int	ft_print_int(int nbr)
{
	int		printed_chars;
	char	*str;

	str = ft_itoa((long)nbr);
	if (!str)
		return (-1);
	if (ft_putstr_fd(str, 1) == -1)
		return (-1);
	printed_chars = ft_strlen(str);
	free(str);
	return (printed_chars);
}
