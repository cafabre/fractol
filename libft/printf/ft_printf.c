#include "libft.h"

static int	ft_process_format(const char *str, va_list args, int *printed_chars)
{
	int	res;

	res = ft_handle_format(*str, args);
	if (res == -1)
		return (-1);
	*printed_chars += res;
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		printed_chars;
	int		i;

	printed_chars = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_process_format(&str[++i], args, &printed_chars) == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar_fd(str[i], 1) == -1)
				return (-1);
			printed_chars++;
		}
		i++;
	}
	va_end(args);
	return (printed_chars);
}
