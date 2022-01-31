#include <stdlib.h>

int	count_words(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str && *str != '\n')
		{
			count++;
			while (*str && *str != '\n')
			{
				str++;
			}
		}
		str++;
	}
	return (count);
}

char	*allocate_word(char *str)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**result;
	int		i;

	result = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
	i = 0;
	while (*str)
	{
		if (*str && *str != '\n')
		{
			result[i] = allocate_word(str);
			i++;
			while (*str && *str != '\n')
				str++;
		}
		str++;
	}
	result[i] = NULL;
	return (result);
}
