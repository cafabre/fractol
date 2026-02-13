#include "libft.h"

int	ft_print_str(char *str)
{
	if (!str)
	{
		if (ft_putstr_fd("(null)", 1) == -1)
			return (-1);
		return (6);
	}
	if (ft_putstr_fd(str, 1) == -1)
		return (-1);
	return (ft_strlen(str));
}
