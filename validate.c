#include <unistd.h>

void	process_for_ones(char *num, char **result);
void	final(char *n, char **result);
int		str_len(char *num);
char	*add_zero(char *num);
extern char	g_buffer[4000];

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_zero(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '0')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	validator(char *str, char **result)
{
	if (str_len(str) > 39)
		write(2, "Error\n", 6);
	else if (is_zero(str) == 1)
	{
		process_for_ones("0", result);
		g_buffer[str_len(g_buffer) - 1] = '\n';
		write(1, &g_buffer, str_len(g_buffer));
	}
	else if (ft_str_is_numeric(str) == 1)
	{
		final(add_zero(str), result);
		g_buffer[str_len(g_buffer) - 1] = '\n';
		write(1, &g_buffer, str_len(g_buffer));
	}
	else
		write(2, "Error\n", 6);
}

int	dict_validate(char **dict)
{
	int	i;
	int	j;
	int	valid;
	int	out;

	i = 0;
	out = 1;
	while (dict[i] && out)
	{
		j = 0;
		valid = 0;
		while (dict[i][j] != '\0')
		{
			if (dict[i][j] == ':' && (dict[i][0] >= '0' && dict[i][0] <= '9'))
				valid = 1;
			j++;
		}
		if (valid == 0)
			out = 0;
		i++;
	}
	return (valid);
}
