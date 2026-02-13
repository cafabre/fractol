#include "libft.h"

int	ft_isalpha(int x)
{
	return ((65 <= x && x <= 90) || (97 <= x && x <= 122));
}
