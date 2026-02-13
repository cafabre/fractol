#include "libft.h"

int	ft_isalnum(int x)
{
	return ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z')
		|| (x >= '0' && x <= '9'));
}
