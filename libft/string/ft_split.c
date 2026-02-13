#include "libft.h"

static void	free_all(char **res, int index)
{
	while (index >= 0)
		free(res[index--]);
	free(res);
}

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*ft_strncpy(char *res, const char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && i < n)
	{
		res[i] = s[i];
		i++;
	}
	while (i < n)
	{
		res[i] = '\0';
		i++;
	}
	return (res);
}

static char	*fill_word(const char *s, int pos_word, int len_word)
{
	char	*word;

	word = (char *)malloc((len_word + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	ft_strncpy(word, &s[pos_word], len_word);
	word[len_word] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char		**res;
	char		**current_res;
	const char	*start;

	res = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	current_res = res;
	while (*s)
	{
		while (*s == c)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		if (s > start)
		{
			*current_res = fill_word(start, 0, s - start);
			if (!(*current_res))
				return (free_all(res, current_res - res - 1), NULL);
			current_res++;
		}
	}
	*current_res = NULL;
	return (res);
}
