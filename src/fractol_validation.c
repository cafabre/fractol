#include "fractol.h"

static int	check_string_validity(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	if (len > 15)
		return (0);
	i = 0;
	while (i < len)
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
		i++;
	}
	return (1);
}

static int	parse_number_chars(char *str, int start)
{
	int	i;
	int	has_digit;
	int	has_dot;

	i = start;
	has_digit = 0;
	has_dot = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			has_digit = 1;
		else if (str[i] == '.' && !has_dot)
			has_dot = 1;
		else
			return (0);
		i++;
	}
	return (has_digit);
}

static int	check_range(char *str)
{
	double	result;

	result = ft_atof(str);
	if (result > 3.4e38 || result < -3.4e38 || result != result)
		return (0);
	return (1);
}

int	is_valid_number(char *str)
{
	int	i;

	if (!str || !*str || !check_string_validity(str))
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i] || str[i] == '.')
		return (0);
	if (!parse_number_chars(str, i))
		return (0);
	return (check_range(str));
}
