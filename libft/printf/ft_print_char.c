#include "libft.h"

int	ft_print_char(char c)
{
	if (ft_putchar_fd(c, 1) == -1)
		return (-1);
	return (1);
}
