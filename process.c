char	g_buffer[4000];

char	*ft_strcat(char *dest, char src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	dest[i] = src;
	dest[i + 1] = '\0';
	return (dest);
}

void	process_for_ones(char *num, char **result)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (result[i])
	{
		j = 0;
		while (result[i][j] != ':' && result[i][j] != ' ')
			j++;
		if (j == 1 && result[i][0] == num[0])
		{
			while (result[i][j + 1] == ' ' || result[i][j + 1] == ':')
				j++;
			while (result[i][j + 1] != '\0')
			{
				ft_strcat(g_buffer, result[i][j + 1]);
				j++;
			}
			if (result[i][j + 1] == '\0')
				ft_strcat(g_buffer, ' ');
		}
		i++;
	}
}

void	process_for_tens(char *num, char **result)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (result[i])
	{
		j = 0;
		while (result[i][j] != ':' && result[i][j] != ' ')
			j++;
		if (j == 2 && result[i][0] == num[0] && result[i][1] == num[1])
		{
			while (result[i][j + 1] == ' ' || result[i][j + 1] == ':')
				j++;
			while (result[i][j + 1] != '\0')
			{
				ft_strcat(g_buffer, result[i][j + 1]);
				j++;
			}
			if (result[i][j + 1] == '\0')
				ft_strcat(g_buffer, ' ');
		}
		i++;
	}
}

int	str_len(char *num)
{
	int	i;

	i = 0;
	while (num[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	process_for_others(char *num, char **result)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = 0;
	while (result[++i])
	{
		j = 0;
		while (result[i][j] != ':' && result[i][j] != ' ')
			j++;
		k = j;
		if (j > 2)
		{
			while (result[i][j + 1] == ':' || result[i][j + 1] == ' ')
				j++;
			while (result[i][j + 1] != '\0' && str_len(num) == k)
			{
				ft_strcat(g_buffer, result[i][j + 1]);
				j++;
			}
			if (result[i][j + 1] == '\0')
				ft_strcat(g_buffer, ' ');
		}
	}
}
